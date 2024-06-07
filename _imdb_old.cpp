#include "imdb.h"
#include "ui_imdb.h"
#include "math.h"

#include <QUrl>
#include <QVariant>
#include <QSettings>
#include <QLCDNumber>
#include <QStatusBar>
#include <QWebElement>
#include <QWebFrame>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QDirIterator>
#include <QPair>
#include <QStringList>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QImage>
#include <QAction>
#include <QMessageBox>
#include <QClipboard>
#include <QStandardItemModel>
#include <QByteArray>
#include <QStringList>
#include <QScrollArea>
#include <QTableView>
#include <QStandardItem>

/*Qt uses "/" as a universal directory separator in the same way that "/" is used as a path separator in URLs. If you always use "/" as a directory separator, Qt will translate your paths to conform to the underlying operating system.*/
const QString imdb::safepathdelimeter = QString("/");

imdb::imdb(QWidget *parent) :
    QWidget(parent)//,
  //ui(new Ui::imdb)
{
    setupUi(this);
mdiArea->tileSubWindows();
    m_network = new QNetworkAccessManager(this); // use for getting image for movie
    m_movies =  new  QList< QPair<QString,  QPair<QString, QString> > > ;
    m_logid = 0;

    connect(wvImdb, SIGNAL(loadProgress(int)), progressBar, SLOT(setValue(int)));
    connect(wvImdb->page(),SIGNAL(statusBarMessage(QString)),this,SLOT(HandleStatus(QString)));

#if defined(DEBUG)
    wvImdb->page()->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled,true);
#endif

    wvImdb->page()->settings()->setAttribute(QWebSettings::PluginsEnabled, false);
    wvImdb->page()->settings()->setAttribute(QWebSettings::JavascriptEnabled, false);
    //wvImdb->page()->settings()->setAttribute(QWebSettings::AutoLoadImages, false);


    m_imdbtimer = new QImdbTimer();
    connect(m_imdbtimer, SIGNAL(DoFeeBack()), this, SLOT(busyWorking()));

    connect(tabCategoryGroups,SIGNAL(TabImageSelected(QWidget*,QString)),this,SLOT(OnTabImageSelected(QWidget*,QString)));

    //connect(this,SIGNAL(run()),this,SLOT(dorun()));

}

imdb::~imdb()
{
    m_imdbtimer->disconnect(SIGNAL(DoFeeBack()));
    m_imdbtimer->stopWatch();
    delete m_imdbtimer;
    delete m_movies;

}


QMainWindow *imdb::mainwin(){
    return (QMainWindow*)parent();
}

QVariant imdb::ini(const QString &key, const QVariant &defaultValue) const
{
    QCoreApplication::setOrganizationName("HardcoreSoftware");
    QCoreApplication::setApplicationName("imdb");
    QSettings settings("catalog",QSettings::IniFormat);
    return settings.value(key, defaultValue);
}


void imdb::setElementText(QWebView *view, const QString &eleName, const QString &value){
    QWebElement ele=document(view).findFirst(eleName);
    if (!ele.isNull()){
        ele.removeAllChildren();
        if (!value.isNull() && !value.isEmpty()){
            ele.appendInside(QString("%1").arg(value));}
    }
}

void imdb::status_Movie(const QString &value){
    setElementText(wvStatus,tr("#selMovie"),value);
}

void imdb::status_fileName(const QString &value){
    setElementText(wvStatus,tr("#fullfileName"),value);
}

void imdb::status_year(const QString &value){
    setElementText(wvStatus,tr("#movieYear"),value);
}

void imdb::status_category(const QString &value){
    setElementText(wvStatus,tr("#category"),value);
}

void imdb::status_location(const QString &value){
    setElementText(wvStatus,tr("#newLocation"),value);
}


void imdb::resetStatusInfo(){

    status_Movie("");
    status_fileName("");
    status_year("");
    status_category("");
    status_location("");

}



void imdb::HandleStatus(  QString text)
{
    if(!text.isEmpty() && !text.isNull()){
        if (m_logid>1000){
            m_logid=0;
            edtLog->clear();
        }
        m_logid++;
        edtLog->appendHtml(QString("<div><b>%1</b>&nbsp;<span>%2</span></div>").arg(m_logid).arg(text));
        QMainWindow* p = mainwin();
        p->statusBar()->showMessage(text);
    }
}


void imdb::busyWorking()
{

    QString remaining = m_imdbtimer->remaining();
    QStringList t= remaining.split(':');

    setupLCDC(lcdHour,t.at(0).toInt()>0);
    setupLCDC(lcdMinute,t.at(1).toInt()>0);
    setupLCDC(lcdSecond,t.at(2).toInt()>0);
    setupLCDC(lcdMilisec,t.at(3).toInt()>0);


    lcdHour->display(t.at(0));//t.at(0).toInt();
    lcdMinute->display(t.at(1));
    lcdSecond->display(t.at(2));
    lcdMilisec->display(t.at(3).toInt()<0?"0":t.at(3));

}


void imdb::setupLCDC( QLCDNumber *lcd, const bool &hasval){

    QPalette palette = lcd->palette();
    palette.setColor(QPalette::Active, QPalette::Light, hasval?Qt::red:Qt::black);
    //palette.setColor(QPalette::Active, QPalette::Window, hasval?Qt::lightGray:Qt::white);
    /*
    palette.setColor(QPalette::Normal, QColorGroup::Foreground, Qt::red);
    palette.setColor(QPalette::Normal, QColorGroup::Background, Qt::black);
    palette.setColor(QPalette::Normal, QColorGroup::Light, Qt::yellow);
    palette.setColor(QPalette::Normal, QColorGroup::Dark, Qt::darkYellow);
    */
    lcd->setPalette(palette);
    //   lcd->repaint();
}

QWebElement imdb::document(QWebView *view) const {
    return  document(view->page()->currentFrame());
}

QWebElement imdb::document(QWebFrame *frame) const {
    return  frame->documentElement();
}


void imdb::doPushQue()
{
    m_imdbtimer->execute();
}

//the scan menujitem
void imdb::dorun()
{
    int n_interval = ini("DelayInterval","10").toString().toInt()*1000;
    qsrand(n_interval);//+ QTime::currentTime().msec());// setup random seed once.. else it will be the same for each call

    m_stopScan = false;
    m_logid = 0;
    m_currentMovieNo = 0;
    m_dropApostrophe =  ini("dropapostrophe","true").toString().compare("true",Qt::CaseInsensitive)==0;
    lstFailedFiles->clear();
    edtLog->clear();
    stackedWidget->setCurrentIndex(0);
    lcdTotalMovies->display(0);
    lcdMovieProcessedOk->display(0);

    progressBar->setMaximum(100);
    HandleStatus(tr("Loading IMDB website"));
    connect(wvImdb, SIGNAL(loadFinished(bool)), this, SLOT(imDbLoaded(bool)));
    QUrl imbUrl(ini("imdbUrl","http://www.imdb.com").toString());
    wvImdb->setUrl(imbUrl);
}

void imdb::imDbLoaded(bool)
{
    wvImdb->disconnect(SIGNAL(loadFinished(bool)));
    HandleStatus(tr("IMDB Ready"));

    m_imdbtimer->stopWatch();
    m_movies->clear();

    resetStatusInfo();

    HandleStatus(tr("Scanning movie folder"));

    loadUnsortedFolder();

    lcdTotalMovies->display(m_movies->count());
    lcdMovieProcessedOk->display(0);
    HandleStatus(tr("Starting movie categorization"));

    m_imdbtimer->startWatch(2500,this,SLOT(findMovie()));
}

void imdb::loadUnsortedFolder(){

    QStringList locations =  ini("MovieLocation","").toString().split(QChar::Nbsp,QString::SkipEmptyParts);
    QStringList filematchRegExpressions = ini("filematchRegExp","(.*\\.[mp4|mpg|avi|m4v|div|mkv]{3}$)").toString().split(QChar::Nbsp,QString::SkipEmptyParts);
    QStringList choppers =  ini("choppers","").toString().split(QChar::Nbsp,QString::SkipEmptyParts);

    foreach(QString dir, locations){
        if (m_stopScan) return;
        if (!dir.isNull() && !dir.isEmpty()) {
            QDir d(dir) ;
            if (d.exists()){
                matchFiles(dir,filematchRegExpressions,choppers);
                QDirIterator it(d, QDirIterator::Subdirectories);
                while (it.hasNext()) {
                    //Qdir item( it.next());
                    QString sfolder = it.next();
                    if (it.fileInfo().isDir()){
                        if (!it.fileInfo().fileName().startsWith('.',Qt::CaseInsensitive) && !it.fileInfo().fileName().endsWith('/',Qt::CaseInsensitive)  )
                        {
                            matchFiles(sfolder,filematchRegExpressions,choppers);
                        }
                    }
                }
            }
        }
    }
}


QString &imdb::safeMovieDescr(const QString &value)
{

    //QString descr(value);
    //QByteArray data(value.toLatin1());
    QString result = QUrl::fromPercentEncoding(value.toLatin1());
    return m_dropApostrophe? *new QString(result.replace('.',' ').replace('~','-').replace('_',' ').remove(QRegExp("[^a-zA-Z\\d\\s\\-\\&]")).simplified()) :  *new QString(result.replace('.',' ').replace('~','-').replace('_',' ').replace('`','\'').remove(QRegExp("[^a-zA-Z\\d\\s\\-\\&\\']")).simplified());
}

void imdb::matchFiles(const QString &sRoot,const QStringList &filematchRegExpressions, const QStringList &choppers)
{
    HandleStatus(tr("Scanning folder %1").arg(sRoot));
    QString sfolder = QDir::cleanPath(sRoot);
    if (sfolder.endsWith(imdb::safepathdelimeter))
        sfolder.chop(1);
    QDir subdir(sfolder);

    QStringList files;
    QString fileNameMatch  = "*";
    files = subdir.entryList(QStringList(fileNameMatch),
                             QDir::Files | QDir::NoSymLinks);
    if (!files.isEmpty()){
        foreach(QString f, files){
            if (m_stopScan) return;
            resetStatusInfo();


            //span_selMovie.appendInside(QString("%1").arg(f));

            //if (f.contains("S",Qt::CaseInsensitive) && f.contains("E",Qt::CaseInsensitive) ){
            foreach(QString filematchRegExp, filematchRegExpressions){
                int pos = 0;
                QRegExp exp;
                //[Ss]eason ([0-9]+)[\\]([0-9]+)
                exp.setCaseSensitivity(Qt::CaseInsensitive);
                exp.setPattern(filematchRegExp);
                //exp.setPattern(TabWidget::rxSeriesEpisodes);//"(?:[s])(\\d+)(?:[e](\\d+)(?:[e](\\d+))?)?");//(?x)(?i)[\//]*\sS(\d+)\sE(\d+)*");//"(?:[se])(\\d+)*(?:[se])(\\d+)"); /* \\b(s|e)\\b(^\\d\\d?$) \\b(S|s|E|e])\\b^\\d\\d?$"); */

                if ((pos = exp.indexIn(f,0))!= -1){
                    QString fullfilename = QString(f);
                    if (!fullfilename.isEmpty()){

                        QString searchInputEntry= fullfilename;
                        if (searchInputEntry.indexOf('.')!= -1){
                            searchInputEntry.chop(searchInputEntry.length()-searchInputEntry.lastIndexOf('.'));
                        }
                        //searchInputEntry= safeMovieName(searchInputEntry);//.replace('.',' ').replace('-',' ').replace('_',' ').trimmed().simplified().trimmed().remove(QRegExp("[^a-zA-Z\\d\\s]"));
                        QString movieYear=0;

                        QRegExp exp;
                        exp.setCaseSensitivity(Qt::CaseInsensitive);
                        exp.setPattern("[^0-9]([0-9]{4})[^0-9]|^([0-9]{4})[^0-9]");
                        int yidx ;
                        if ((yidx = exp.indexIn(searchInputEntry,0))!= -1){
                            movieYear= searchInputEntry.right(searchInputEntry.length()-yidx-1);
                            movieYear.truncate(4);
                            searchInputEntry.chop(searchInputEntry.length()-yidx-1);
                        }

                        //QStringList cutNames =  ini("choppers","").toString().split(QChar::Nbsp,QString::SkipEmptyParts);
                        //cutNames << "dvdrip" << "pvrip" << "brrip" << "bdrip" << "dvdscr" << "xvid" << "CAM XVID" << "[" << "{" << "(";
                        foreach (QString n_name, choppers){
                            int nidx = searchInputEntry.indexOf(n_name,0,Qt::CaseInsensitive);
                            if (nidx != -1)
                            {
                                searchInputEntry.chop(searchInputEntry.length()-nidx);
                            }
                        }

                        QString maskSearchValue = safeMovieDescr(searchInputEntry);
                        status_Movie(maskSearchValue);
                        status_fileName(fullfilename);
                        status_year(movieYear);



                        bool fnd = false;
                        for(int i=0;i<m_movies->count();i++){
                            QPair<QString, QPair<QString, QString > >  nmovie = m_movies->at(i);
                            fnd = nmovie.first.compare(sfolder+imdb::safepathdelimeter+fullfilename,Qt::CaseInsensitive)==0;
                            if (fnd){
                                QString hasyear = nmovie.second.second;
                                if (!movieYear.isNull() && !hasyear.isNull() && hasyear.compare(movieYear,Qt::CaseInsensitive)!=0){
                                    fnd = false;
                                }
                            }
                        }
                        if (!fnd){
                            QPair< QString,QString >  details(maskSearchValue,movieYear);
                            QPair< QString,QPair< QString,QString > > newitem(sfolder+imdb::safepathdelimeter+fullfilename,details);
                            m_movies->append(newitem);
                            HandleStatus(tr("Added '%1' --> '%2'").arg(maskSearchValue).arg(sfolder+imdb::safepathdelimeter+fullfilename) );
                        }
                    }
                }
            }
        }
    }
}

void imdb::nextMovie(){
    if (m_stopScan){
        m_imdbtimer->stopWatch();
        HandleStatus(tr("Stopped"));
        return;}

    int irandom = qrand();
    while (irandom < 2500){
        irandom = qrand();
    }

    HandleStatus(tr("Waiting to process next movie in %1 seconds").arg(irandom/1000));
    m_imdbtimer->startWatch(irandom,this,SLOT(findMovie()));
}

void imdb::findMovie(){

    if (!m_movies->empty()){
        progressBar->setMaximum(100);

        selectedMovie = m_movies->takeFirst();

        m_currentMovieNo++;
        int i = lcdMovieProcessedOk->value();
        lcdMovieProcessedFailed->display(m_currentMovieNo-i);

        HandleStatus(tr("Submit search for '%1'").arg(selectedMovie.second.first));

        resetStatusInfo();

        status_Movie(selectedMovie.second.first);
        status_fileName(selectedMovie.first);
        status_year(selectedMovie.second.second);

        QWebElement edtnavbarquery =document(wvImdb).findFirst("#navbar-query");
        if (!edtnavbarquery.isNull()){
            inputValue(edtnavbarquery,selectedMovie.second.first);
            connect(wvImdb, SIGNAL(loadFinished(bool)), this, SLOT(searchcompleted(bool)));

            QWebElement btnnavbarsubmitbutton =document(wvImdb).findFirst("#navbar-submit-button");
            clickBtn(btnnavbarsubmitbutton);
        } else { // if not input to search go back to main page and try from there
            connect(wvImdb, SIGNAL(loadFinished(bool)), this, SLOT(nextMovie()));
            QUrl imbUrl(ini("imdbUrl","http://www.imdb.com").toString());
            wvImdb->setUrl(imbUrl);
        }

    }else {
        int i = lcdMovieProcessedOk->value();
        lcdMovieProcessedFailed->display(m_currentMovieNo-i);
        HandleStatus(tr("Finished"));
    }
}

void imdb::searchcompleted(bool)
{
    wvImdb->disconnect(SIGNAL(loadFinished(bool)));

    HandleStatus(tr("Page ready for analyzing"));
    QWebElement div_overviewtop =document(wvImdb).findFirst("#overview-top");
    if (!div_overviewtop.isNull()){
        HandleStatus(tr("Scraping page for '%1' movie detals").arg(selectedMovie.second.first));
        QWebElement hasHeader = div_overviewtop.findFirst("h1[class='header']");
        if (!hasHeader.isNull()){
            //  HandleStatus(tr("Release year"));
            QWebElement titleyear =div_overviewtop.findFirst("h1[class='header'] a");
            if (titleyear.isNull()){
                titleyear =div_overviewtop.findFirst("h1[class='header'] span");
            }
            if (!titleyear.isNull()){
                // HandleStatus(tr("Movie information"));
                QWebElement infobar =div_overviewtop.findFirst("div[class='infobar']");
                if (!infobar.isNull()){
                    //  HandleStatus(tr("Consolidate and categorize"));

                    QString movieinfo = infobar.evaluateJavaScript("this.innerText").toString().simplified();
                    QString inyear = titleyear.evaluateJavaScript("this.innerText").toString().simplified();
                    QString movieYear = inyear.toInt()!=0?inyear:(!selectedMovie.second.second.isEmpty())? selectedMovie.second.second : "Unkown";

                    QRegExp exp;
                    exp.setCaseSensitivity(Qt::CaseInsensitive);
                    exp.setPattern("[^0-9]([0-9]{4})[^0-9]|^([0-9]{4})[^0-9]");
                    int yidx ;
                    if ((yidx = exp.indexIn(inyear,0))!= -1){
                        movieYear = inyear.right(inyear.length()-yidx-1);
                        movieYear.truncate(4);
                    }

                    status_category(movieinfo);

                    //QStringlist inner = innercats.indexOf('|')!=-1? innercats.split('|'): innercats;
                    copyMovieToCategory(movieinfo,movieYear);
                    return;
                }
                else {
                    HandleStatus(tr("Information bar not avialable for %1").arg(selectedMovie.second.first));}
            } else {
                HandleStatus(tr("Movie year not avialable for %1").arg(selectedMovie.second.first));}
        } else {
            HandleStatus(tr("Page details not avialable to categorize movie, '%1'").arg(selectedMovie.second.first));}
    }
    else { // find item in grid
        HandleStatus(tr("Processing grid items, looking for '%1' movie listing").arg(selectedMovie.second.first));
        QWebElement content=  document(wvImdb).findFirst("#content-2-wide");
        if (!content.isNull()){
            QWebElement emain= content.findFirst("div[id='main']");
            if (!emain.isNull()){
                QWebElement hasTables = emain.findFirst("table");
                if(!hasTables.isNull()){
                    QWebElement hasAnchors = emain.findFirst("table a");
                    if(!hasAnchors.isNull()){
                        QWebElementCollection anchors =  emain.findAll("table a");
                        foreach(QWebElement element, anchors){
                            QString anchorText = safeMovieDescr(element.evaluateJavaScript("this.innerText").toString());//.simplified().trimmed().remove(QRegExp("[^a-zA-Z\\d\\s]"));
                            if (!anchorText.isNull() && !anchorText.isEmpty()){
                                QString descr = selectedMovie.second.first;
                                QString myear = selectedMovie.second.second;
                                HandleStatus(tr("Matching anchor... '%1' to '%2'").arg(descr).arg(anchorText));
                                if (descr.contains(anchorText,Qt::CaseInsensitive)||anchorText.contains(descr,Qt::CaseInsensitive)){
                                    if (!element.parent().isNull()){
                                        QString checkyear = element.parent().evaluateJavaScript("this.innerText").toString();
                                        if (checkyear.contains(myear)){
                                            connect(wvImdb, SIGNAL(loadFinished(bool)), this, SLOT(searchcompleted(bool)));
                                            HandleStatus(tr("Following movie link... %1 %2").arg(anchorText).arg(myear));
                                            followLink(element);
                                            return;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        HandleStatus(tr("Table search returned not anchors for '%1'").arg(selectedMovie.second.first));}
                } else {
                    HandleStatus(tr("Grid search return empty table for '%1'").arg(selectedMovie.second.first));}
            } else {
                HandleStatus(tr("Main body has empty grid for '%1'").arg(selectedMovie.second.first));}
        } else {
            HandleStatus(tr("Search result returned not vaild items in the grid for '%1'").arg(selectedMovie.second.first));}
    }
    HandleStatus(tr("No match for '%1', moving to next movie...").arg(selectedMovie.second.first));
    lstFailedFiles->addItem(selectedMovie.first);
    m_imdbtimer->startWatch(2500,this,SLOT(nextMovie()));
}

void imdb::copyMovieToCategory(const QString &info, const QString &movieYear ){

    status_year(movieYear);

    QStringList movieinfo;
    if (info.indexOf("sci-fi",0,Qt::CaseInsensitive) != -1 )
    {
        QString scifi(info);
        scifi.replace("sci-fi","sci_fi",Qt::CaseInsensitive);
        if (scifi.indexOf("-",0,Qt::CaseInsensitive) != -1 )
        {
            movieinfo << scifi.split("-");
            for(int i=0;i<movieinfo.length();i++){
                if (movieinfo.at(i).indexOf("sci_fi",0,Qt::CaseInsensitive) != -1 ){
                    QString sf = movieinfo.at(i);
                    sf.replace("sci_fi","Sci-Fi",Qt::CaseInsensitive);
                    movieinfo.replace(i,sf);
                }
            }
        } else {// first item is always gonna be time then sci-fi then nonesense 0min  - sci-fi - holy macaroni
            movieinfo << "0 min" << info;}
    } else {
        movieinfo = info.split("-");}
    QStringList categories;
    QString dstFolder= ini("targetFolder",QDir::currentPath()).toString();
    if (!dstFolder.endsWith(imdb::safepathdelimeter)) {dstFolder += imdb::safepathdelimeter;}
    bool sortbyreleaseyear = ini("sortbyreleaseyear","true").toString().compare("true",Qt::CaseInsensitive)==0;
    bool m4vtomp4 = ini("m4vtomp4","true").toString().compare("true",Qt::CaseInsensitive)==0;

    // nomally has move length in min then categories, eg 95min - action | adventure | drama - blahh
    if (movieinfo.count()-1 != -1){
        if (movieinfo.count()-1 == 0){
            //            120 min or Sci-Fi . ... . . thats it just a single label
            if (!(QString(movieinfo.at(0)).contains("min",Qt::CaseInsensitive))){
                if (QString(movieinfo.at(0)).indexOf('|')!=-1){
                    categories = QString(movieinfo.at(0)).split('|');
                } else categories.append(movieinfo.at(0));
            } else categories << "undefined";
        } else { //most comon 90 min - drama | comedy | musical, at(1) == 'drama | comedy | musical' part
            if (QString(movieinfo.at(1)).indexOf('|')!=-1){
                categories = QString(movieinfo.at(1)).split('|');
            } else if (QString(movieinfo.at(0)).indexOf('|')!=-1){
                categories = QString(movieinfo.at(0)).split('|');
            } else categories.append(movieinfo.at(1));
        }
    } else categories << "undefined";

    //make sure first letter is capital eg 1:Ant 2:Farm
    int idx = 0 ;
    foreach(QString category, categories){
        QString fcat = category.simplified().trimmed().toLower();
        categories.replace(idx,fcat.left(1).toUpper()+fcat.mid(1));
        idx++;
    }
    categories.sort();

    if (sortbyreleaseyear){
        dstFolder += movieYear+imdb::safepathdelimeter;}

    foreach(QString category, categories){
        dstFolder+=category+imdb::safepathdelimeter;
    }

    while (dstFolder.endsWith(imdb::safepathdelimeter)) {
        dstFolder.chop(1);
    }

    if (!sortbyreleaseyear){
        dstFolder += imdb::safepathdelimeter+ movieYear;}

    QString targetfolder= QDir::cleanPath(dstFolder);

    HandleStatus(tr("Starting to copy %1 to new %2").arg(selectedMovie.second.first).arg(targetfolder));

    QDir tf;
    tf.mkpath(targetfolder);

    QFile newfile(selectedMovie.first);

    QFileInfo fileInfo(selectedMovie.first);

    if (fileInfo.exists()){
        QString newFileName = m4vtomp4 && fileInfo.suffix().compare("m4v",Qt::CaseInsensitive)==0?fileInfo.fileName().replace(".m4v",".mp4"):fileInfo.fileName();

        int _uniqueId= 0;
        if (QFile::exists(targetfolder+imdb::safepathdelimeter+newFileName)){
            _uniqueId= 1;
            QString xname(newFileName);
            xname.insert(xname.lastIndexOf('.'),"_%1");
            while (QFile::exists(QString(targetfolder+imdb::safepathdelimeter+xname).arg(_uniqueId))){
                _uniqueId++;
            }
        }

        if (_uniqueId != 0){
            QString xname=newFileName.insert(newFileName.lastIndexOf('.'),"_%1");
            newfile.rename(targetfolder+imdb::safepathdelimeter+QString(xname).arg(_uniqueId));
        }
        else {
            newfile.rename(targetfolder+imdb::safepathdelimeter+newFileName);
        }


        status_location(newfile.fileName());

        downloadMovieImage(targetfolder);

        HandleStatus(tr("Copied %1 to new %2").arg(selectedMovie.second.first).arg(targetfolder));
    }
}

void imdb::downloadMovieImage(const QString &folder){
    m_selectedFolder = QString(folder);
    QWebElement hasPrimary=document(wvImdb).findFirst("#img_primary");
    if (!hasPrimary.isNull()){
        QWebElement hasAnchors=document(wvImdb).findFirst("#img_primary a");
        if (!hasAnchors.isNull()){
            QWebElement img=document(wvImdb).findFirst("#img_primary a img");
            if (!img.isNull()){
                QString href = img.attribute("src");
                if (!href.isNull() && !href.isEmpty()){
                    //img.setAttribute("imdb_img_folder",folder);
                    QUrl imgUrl(href);
                    QNetworkRequest request = QNetworkRequest(imgUrl);
                    QObject::connect(m_network,SIGNAL(finished(QNetworkReply*)),this,SLOT(networkReplyReady(QNetworkReply*)));
                    HandleStatus(tr("Requesting thumbnail for %1").arg(selectedMovie.second.first));
                    QNetworkReply *m_reply =  m_network->get(request); /// networkReplyReady will get the same pointer when finished to call deletelater on
                    if (m_reply){
                        QObject::connect(m_reply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(socketDownloadprogress(qint64,qint64)));
                        QObject::connect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(socketError(QNetworkReply::NetworkError)));

                    }

                    //QObject::connect(m_reply, SIGNAL(finished()), this, SLOT(finished_listDesc()));
                    //QObject::connect(m_reply, SIGNAL(readyRead()), this, SLOT(readyRead_listDesc()));

                    return;
                }
            }
        }
    }
    //if not gone as planned then save a dummy image for movie
    saveDefaultMoviePic();
    markProcessed();
}

void imdb::markProcessed(){
    int i = lcdMovieProcessedOk->value();
    int ni = (i==0)?1:++i;// if (i==0){i=1;}else{i++;}
    lcdMovieProcessedOk->display(ni);
    lcdMovieProcessedOk->repaint();
    m_imdbtimer->startWatch(2500,this,SLOT(nextMovie()));
}

void imdb::networkReplyReady(QNetworkReply *reply){

    m_network->disconnect(SIGNAL(finished(QNetworkReply*)));
    QImage image;
    image.load(reply, 0);
    if (!image.isNull()){
        saveMovieImage(image);
    } else {
        saveDefaultMoviePic();
    }
    reply->deleteLater();
    markProcessed();

    //qApp->processEvents();
}

void imdb::saveMovieImage(const QImage &image){
    QWebElement hasPrimary=document(wvImdb).findFirst("#img_primary");
    if (!hasPrimary.isNull()){
        QWebElement hasAnchors=document(wvImdb).findFirst("#img_primary a");
        if (!hasAnchors.isNull()){
            QWebElement img=document(wvImdb).findFirst("#img_primary a img");
            if (!img.isNull()){
                QString folder(m_selectedFolder);//img.attribute("imdb_img_folder");
                if(!folder.isNull() && !folder.isEmpty()){
                    HandleStatus(tr("Saving thumbnail for '%1'").arg(selectedMovie.second.first));
                    image.save(folder+imdb::safepathdelimeter + selectedMovie.second.first + ".jpg" );
                    HandleStatus(tr("Saved thumbnail for %1").arg(selectedMovie.second.first));
                }
            }
        }
    }
}

void imdb::saveDefaultMoviePic(){

    //qrc:///image/moviepic.png is valid, but result is same as shorthand :/
    // QUrl url(QString("qrc:///images/moviepic.png"));

    /* the code to load a image from resource
    QImage image(QString(":/images/moviepic.png"));
    QImage scaled (image.scaled(125,150, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    label_4->setPixmap(QPixmap::fromImage(scaled));

    // to convert from png to jpg -> simply change extention, and call save method
    QImage image(QString(":/images/moviepic.png"));
    if (!image.isNull()){
        image.save("c:/source/qt/b.jpg" );
    }


    */


    QImage image(QString(":/images/moviepic.png"));
    if (!image.isNull()){
        QString folder(m_selectedFolder);//img.attribute("imdb_img_folder");
        if(!folder.isNull() && !folder.isEmpty()){
            HandleStatus(tr("Saving thumbnail for '%1'").arg(selectedMovie.second.first));
            image.save(folder+imdb::safepathdelimeter + selectedMovie.second.first + ".jpg" );
            HandleStatus(tr("Saved thumbnail for %1").arg(selectedMovie.second.first));
        }
        //saveMovieImage(image);
    }
}

//follow link because scripts are disabled so window.location will not work.. have to change url
void imdb::followLink(QWebElement &link){
    focusElement(link);
    //    wvImdb->page()->mainFrame()->evaluateJavaScript("window.location="+link.evaluateJavaScript("this.href").toString());
    QString href = link.attribute("href");
    QUrl url(QString("http://www.imdb.com%1").arg(href));
    wvImdb->setUrl(url);
    //qDebug() << href;
    //qDebug() << wvImdb->page()->mainFrame()->evaluateJavaScript("window.location").toString();
    //link.evaluateJavaScript(QString("window.location=http://www.imdb.com%1").arg(href));
    //QString nop = link.evaluateJavaScript("this.document.window.location="+href).toString();
    //wvImdb->page()->mainFrame()->evaluateJavaScript(QString("window.location=%1").arg(href));
    // qDebug() << nop;
    //link.document().webFrame()->page()->event
    ///QString click = QString("this.docu");
    //btn.evaluateJavaScript(click);
}


void imdb::clickBtn(QWebElement &btn){
    focusElement(btn);
    QString click = QString("this.click()");
    btn.evaluateJavaScript(click);
}
void imdb::focusElement(QWebElement &ele){
    ele.setFocus();
    QString focusthis("this.setFocus();");
    ele.evaluateJavaScript(focusthis);
}

void imdb::inputValue(QWebElement &input, const QString &value){
    //QString setvalue = QString("this.value='%1'").arg(value);
    QString testvalue = QString("this.value");
    QString jsvalue("");

    while (jsvalue.compare(value,Qt::CaseInsensitive) != 0){
        //input.evaluateJavaScript(setvalue);
        input.setAttribute("value", value);
        jsvalue=input.evaluateJavaScript(testvalue).toString();
    }
    HandleStatus(QString("Search input value equals '%1'").arg(jsvalue));
    focusElement(input);
}

void imdb::showLogs()
{
    //HandleStatus(sender()->objectName());
    //  QAction *me = (QAction*)sender();
    //me->setChecked(stackedWidget->currentIndex()==1);
    /* QMainWindow* p = mainwin();
    foreach(QAction *action, p->actions()){
        if (action->objectName().compare(tr("actionView_Logs"))==0){
            action->setChecked(stackedWidget->currentIndex()==1);
        }
    }*/

    //stackedWidget->setCurrentIndex(stackedWidget->currentIndex()!=1?1:0);

    stackedWidget->setCurrentIndex(1);
}

void imdb::doShowRemainingMovies()
{
    //stackedWidget->setCurrentIndex(stackedWidget->currentIndex()!=2?2:0);
    stackedWidget->setCurrentIndex(2);
}

void imdb::showStatus()
{
    //stackedWidget->setCurrentIndex(stackedWidget->currentIndex()!=0?0:stackedWidget->currentIndex()!=2?2:1);
    stackedWidget->setCurrentIndex(0);
}

void imdb::cleanjunkFiles(const QString &folder,const QStringList &fileMaskExpressions){
    QDir d(folder) ;
    if (d.exists()){
        QStringList fileList = d.entryList(fileMaskExpressions, QDir::AllEntries | QDir::NoDotAndDotDot);
        for (int l = 0; l < fileList.size(); l++)
        {
            if (m_stopScan) return;
            QFileInfo fi = fileList.at(l);
            QString fname = fi.fileName();
            if (d.remove(fname)){HandleStatus(tr("Removed file: %1").arg(fname));} else{
                HandleStatus(tr("Cannot remove file: %1").arg(fname));}
        }
    }
    tryRemoveFolder(folder);
}


void imdb::tryRemoveFolder(const QString &folder){
    QDir d(folder);
    if (d.exists() && !d.isRoot() && !folder.startsWith('.',Qt::CaseInsensitive) ){
        QStringList fileList = d.entryList(QStringList("*"), QDir::AllEntries | QDir::NoDotAndDotDot);
        if (fileList.size()-1 == -1){
            d.cdUp();
            if(d.rmdir(folder)){
                HandleStatus(tr("Removed folder: %1").arg(folder));}
            else {HandleStatus(tr("Cannot remove folder: %1").arg(folder));}
        }
    }
}

void imdb::doFolderCleanup(){

    QStringList locations =  ini("MovieLocation","").toString().split(QChar::Nbsp,QString::SkipEmptyParts);
    int ret = QMessageBox::warning(this,"Confirm Permanent Changes",QString("Files are about too be deleted from the following locations.\n%1\nAre you positive that you want to continue?").arg(locations.join("\n")),QMessageBox::Yes|QMessageBox::Cancel);
    if (ret == QMessageBox::Yes){

        QStringList filematchRegExpressions = ini("reclaimfilemasks",QString("*.txt%1*.nfo%1*.ds_*%1*.tor*").arg(QChar::Nbsp)).toString().split(QChar::Nbsp,QString::SkipEmptyParts);

        foreach(QString dir, locations){
            if (m_stopScan) return;
            if (!dir.isNull() && !dir.isEmpty()) {
                QDir d(dir) ;
                if (d.exists()){
                    QDirIterator it(d, QDirIterator::Subdirectories);
                    while (it.hasNext()) {
                        //Qdir item( it.next());
                        QString sfolder = it.next();
                        if (it.fileInfo().isDir()){
                            if (!it.fileInfo().fileName().startsWith('.',Qt::CaseInsensitive) && !it.fileInfo().fileName().endsWith('/',Qt::CaseInsensitive)  )
                            {
                                cleanjunkFiles(sfolder,filematchRegExpressions);
                            }
                        }
                    }
                    cleanjunkFiles(dir,filematchRegExpressions);
                }
            }
        }



        foreach(QString dir, locations){
            if (m_stopScan) return;
            if (!dir.isNull() && !dir.isEmpty()) {
                QDir d(dir) ;
                if (d.exists()){
                    QDirIterator it(d, QDirIterator::Subdirectories);
                    while (it.hasNext()) {
                        QString sfolder = it.next();
                        if (it.fileInfo().isDir()){
                            if (!it.fileInfo().fileName().startsWith('.',Qt::CaseInsensitive) && !it.fileInfo().fileName().endsWith('/',Qt::CaseInsensitive)  )    {
                                tryRemoveFolder(sfolder);}
                        }
                    }
                    tryRemoveFolder(dir);
                }
            }
        }

    }
}

void imdb::doStopScan(){
    m_stopScan = true;
    HandleStatus(tr("Stopping"));
}

void imdb::sentToClip(QString value){
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->clear();
    clipboard->setText(value);
}

void imdb::on_lstFailedFiles_clicked(const QModelIndex &index)
{
    QStandardItemModel *model = static_cast<QStandardItemModel*>(lstFailedFiles->model());
    QString text = model->data(index, Qt::DisplayRole).toString();
    sentToClip(text);
}

void imdb::doRefreshCategoryTabs()
{
    tabCategoryGroups->clearGalleries();


    QString dir= ini("targetFolder",QDir::currentPath()).toString();


    QDir dRoot(dir) ;
    if (dRoot.exists()){

        QList < QPair<QString,QStringList*> > m_movie_categories;
        //m_movie_categories = new QList < QPair<QString,QStringList > >;


        QDirIterator it(dRoot, QDirIterator::Subdirectories);
        while (it.hasNext()) {
            QString sfolder = it.next();
            QDir p(sfolder);
            HandleStatus(tr("Categorizing folder '%1' files into tabs").arg(sfolder));
            if (it.fileInfo().isDir() && (p.cdUp() && p!=dRoot) ){
                if (!it.fileInfo().fileName().startsWith('.',Qt::CaseInsensitive) && !it.fileInfo().fileName().endsWith('/',Qt::CaseInsensitive)  )
                {
                    QString d = QDir::cleanPath(sfolder);
                    QString tmp(d);

                    tmp.remove(0,dir.length()+5); // 4 for the year + 1 seperator
                    while (tmp.startsWith('/') ){
                        tmp.remove(0,1);}

                    QStringList categories = tmp.split('/');
                    foreach(QString category, categories){
                        bool bfnd = false;
                        for(int i=0;i<m_movie_categories.count();i++){
                            QPair<QString,QStringList*> mcategory= m_movie_categories.at(i);
                            //if (it.fileInfo().fileName().compare(mcategory.first,Qt::CaseInsensitive)==0){
                            if (category.compare(mcategory.first,Qt::CaseInsensitive) ==0 ){
                                if (mcategory.second->indexOf(d)==-1 ){
                                    (*mcategory.second).append(d);
                                    bfnd = true;
                                }
                                break;
                            }
                        }
                        if (!bfnd){
                            QString f =  QDir::cleanPath(sfolder);

                            QStringList *folders = new QStringList();
                            folders->append(f);
                            QPair<QString,QStringList*>  catItem(it.fileInfo().fileName(),folders);
                            m_movie_categories.append(catItem);
                            HandleStatus(tr("Found '%1' tab").arg(catItem.first));

                        }
                    }

                }
            }
        }


        //put movies in alpabetic order
        for(int i=0;i<m_movie_categories.count()-1;i++){
            for(int j=i+1;j<m_movie_categories.count();j++){
                QPair < QString,QStringList *> first= m_movie_categories.at(i);
                QPair < QString,QStringList *> second = m_movie_categories.at(j);
                if (first.first.toUpper()>second.first.toUpper()){
                    m_movie_categories.swap(i,j);
                }
            }

        }

        //create galleries
        int sz = ini("thumbsize","100").toString().toInt();
        for(int i=0;i<m_movie_categories.count();i++){
            QPair < QString,QStringList *> catItem= m_movie_categories.at(i);
            HandleStatus(tr("Adding '%1' tab").arg(catItem.first));
            tabCategoryGroups->addGallery(QString("%1 (%2)").arg(catItem.first).arg(catItem.second->count()),sz,*catItem.second);
            HandleStatus(tr("Added '%1' tab").arg(catItem.first));


        }
    }
    HandleStatus(tr("Ready"));
}


void imdb::OnTabImageSelected(QWidget *sender, const QString &link){
    Q_UNUSED(sender);
    pageReviews->addReview(link);
}

void imdb::socketError(QNetworkReply::NetworkError code)
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    QString lerror(tr("Network Error (%2). %1"));
    HandleStatus(lerror.arg(reply->errorString()).arg(code));
    reply->disconnect(this);
    //m_selreply->deleteLater();

}

void imdb::socketDownloadprogress(qint64 bytesReceived, qint64 bytesTotal)
{
    progressBar->setMaximum(bytesTotal);
    progressBar->setValue(bytesReceived);
}

void imdb::CheckMovieHasPicInGallery()
{
    m_stopScan = false;
    lstMissingMoviePictures->clear();
    stackedWidget->setCurrentIndex(3);
    QApplication::processEvents();

    QString dir= ini("targetFolder",QDir::currentPath()).toString();
    QDir dRoot(dir) ;
    if (dRoot.exists()){
        matchImgToMovie(dir,fileMaskMatch());
        QDirIterator it(dRoot, QDirIterator::Subdirectories);
        while (it.hasNext()) {
            QString sfolder = it.next();
            QDir p(sfolder);
            HandleStatus(tr("Analysing folder '%1' files").arg(sfolder));
            if (it.fileInfo().isDir() && (p.cdUp() && p!=dRoot) ){
                if (!it.fileInfo().fileName().startsWith('.',Qt::CaseInsensitive) && !it.fileInfo().fileName().endsWith('/',Qt::CaseInsensitive)  )
                {
                    matchImgToMovie(QDir::cleanPath(sfolder),fileMaskMatch());
                }
            }
        }
    }
    if (m_stopScan == true) HandleStatus("Stopped"); else HandleStatus("Ready");
   }

void imdb::matchImgToMovie(const QString &dir, const QString &maskMatch){


    QStringList files;
    QString fileNameMatch  = maskMatch; //"*";
    QDir subdir(dir);
    files = subdir.entryList(QStringList(fileNameMatch),
                             QDir::Files | QDir::NoSymLinks);
    if (!files.isEmpty()){
        foreach(QString fmovie, files){
            if (m_stopScan ) return;
            QFileInfo info(fmovie);
            if (info.suffix().compare("jpg",Qt::CaseInsensitive) != 0)
            {
                QStringList matches;
                QString moviematchmask = QString("%1*.*");
                QString moviematch = moviematchmask.arg(f.left(f.lastIndexOf('.')));
                QDir matchdir(dir);
                matches = matchdir.entryList(QStringList(moviematch),
                                         QDir::Files | QDir::NoSymLinks);
                QStringList allfiles;
                allfiles = subdir.entryList(QStringList(fileNameMatch),

                QDir::Files | QDir::NoSymLinks);
                bool fnd = false;
                foreach(QString fjpg, allfiles){
                    QFileInfo qi(fjpg);
                    if (qi.suffix().compare("jpg",Qt::CaseInsensitive) == 0)
                    {
                        QString jpegmov = safeMovieDescr(fjpg.left(fjpg.lastIndexOf('.')));
                        QString avimov = safeMovieDescr(fmovie.left(fmovie.lastIndexOf('.')));
                        if (avimov.contains(jpegmov,Qt::CaseInsensitive)|| jpegmov.contains(avimov,Qt::CaseInsensitive))
                        {
                            fnd = true;
                            break;
                        }
                    }
                }
                if (!fnd){
                    lstMissingMoviePictures->addItem(dir + imdb::safepathdelimeter + fmovie);
                }

            }
        }
    }


}

const QString imdb::fileMaskMatch()
{
 return (QString.isNull(edtSearchFor->text())||QString.isEmpty(edtSearchFor->text()))?'*':edtSearchFor->text();
}

void imdb::on_lstMissingMoviePictures_clicked(const QModelIndex &index)
{
    QStandardItemModel *model = static_cast<QStandardItemModel*>(lstMissingMoviePictures->model());
    QString text = model->data(index, Qt::DisplayRole).toString();
    sentToClip(text);
}
