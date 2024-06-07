#include "imdbsettings.h"
#include "ui_imdbsettings.h"
#include <QSettings>
#include <QtGui>
#include <QString>
#include <QChar>
#include <QListView>
#include <QListIterator>
#include <QStandardItem>
#include "mainwindow.h"
#include <QFileDialog>

//const QString TabWidget::rxSeriesEpisodes = QString("(?:[Ss])(\\d+)(?:[Ee](\\d+)(?:[Ee](\\d+))?)?");

ImDbSettings::ImDbSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImDbSettings)
{
    ui->setupUi(this);

    actCloseApp = new QAction(tr("&Close"),this);
    actCloseApp->setShortcuts(QKeySequence::Close);
    actCloseApp->setStatusTip(tr("Close"));
    connect(actCloseApp,SIGNAL(triggered()), this, SLOT(close()));



    ui->edtDemonoidUrl->setText(  ini("imdbUrl","http://www.imdb.com").toString());
    ui->edtSortedFolder->setText(  ini("targetFolder",QDir::currentPath()).toString());
    ui->dialScrapeInterval->setValue(  ini("DelayInterval",QString::number(ui->dialScrapeInterval->maximum()/4)).toInt());

    ui->chkm4vTompg->setChecked(ini("m4vtomp4","true").toString().compare("true",Qt::CaseInsensitive)==0);
    ui->sortByReleaseYearFirstCheckBox->setChecked(ini("sortbyreleaseyear","true").toString().compare("true",Qt::CaseInsensitive)==0);
    ui->DropApostrophe->setChecked( ini("dropapostrophe","true").toString().compare("true",Qt::CaseInsensitive)==0);


    QStringList locations =  ini("MovieLocation","").toString().split(QChar::Nbsp,QString::SkipEmptyParts);
    QStandardItemModel *modelLocations = new QStandardItemModel();
    foreach(QString folder,locations){

        QStandardItem *item = new QStandardItem(folder);
        modelLocations->appendRow(item);
    }
    ui->lstFoldersToScan->setModel(modelLocations);
    ui->edtSeriesFolder->setText("");

    //ui->edtRegExp->setText(ini("filematchRegExp",TabWidget::rxSeriesEpisodes).toString());

    QStringList filematchRegExp =  ini("filematchRegExp","*.*").toString().split(QChar::Nbsp,QString::SkipEmptyParts);
    QStandardItemModel *modelRegExp = new QStandardItemModel();
    foreach(QString regexp,filematchRegExp){
        QStandardItem *item = new QStandardItem(regexp);
        modelRegExp->appendRow(item);
    }
    ui->lstRegExp->setModel(modelRegExp);
    ui->edtRegExp->setText("");


    QStringList reclaimMasks =  ini("reclaimfilemasks","").toString().split(QChar::Nbsp,QString::SkipEmptyParts);
    QStandardItemModel *modelMasks = new QStandardItemModel();
    foreach(QString mask,reclaimMasks){

        QStandardItem *item = new QStandardItem(mask);
        modelMasks->appendRow(item);
    }
    ui->lstDeleteFileTypes->setModel(modelMasks);
    ui->edtDeleteFileMatch->setText("");


    QStringList choppers =  ini("choppers","").toString().split(QChar::Nbsp,QString::SkipEmptyParts);
    QStandardItemModel *modelChop = new QStandardItemModel();
    foreach(QString chop,choppers){

        QStandardItem *item = new QStandardItem(chop);
        modelChop->appendRow(item);
    }
    ui->lstChoppers->setModel(modelChop);
    ui->edtChop->setText("");


    ui->thumbnailSizeSpinBox->setValue(ini("thumbsize","100").toString().toInt());

    connect(ui->dialScrapeInterval,SIGNAL(valueChanged(int)),this,SLOT(ScrapeIntervalChanged(int)));
    ScrapeIntervalChanged(ui->dialScrapeInterval->value());


}

ImDbSettings::~ImDbSettings()
{
    delete ui;
}

void ImDbSettings::ScrapeIntervalChanged(int value){

    QString d = "n/a";
    const int secs_in_min = 60;
    if (value < secs_in_min) {
        d = QString("%1 seconds(s)").arg( QString::number(value  ));
    } else {
        int minutes=value / 60;
        d = QString("%1 minute(s) %2 second(s)").arg(QString::number(  minutes ),QString::number(value % 60  ));
    }

    ui->lblScrapeInterval->setText(d);
    ui->lblScrapeInterval->repaint();
}



void ImDbSettings::saveini(const QString &name, const QVariant &value)
{
    QCoreApplication::setOrganizationName("HardcoreSoftware");
    QCoreApplication::setApplicationName("imdb");
    QSettings settings("catalog",QSettings::IniFormat);
    settings.setValue(name,value);
}

QVariant ImDbSettings::ini(const QString &key, const QVariant &defaultValue) const
{
    QCoreApplication::setOrganizationName("HardcoreSoftware");
    QCoreApplication::setApplicationName("imdb");
    QSettings settings("catalog",QSettings::IniFormat);
    return settings.value(key, defaultValue);
}


void ImDbSettings::on_buttonBox_accepted()
{   
    saveini("imdbUrl",ui->edtDemonoidUrl->text());
    saveini("targetFolder",ui->edtSortedFolder->text());
    saveini("DelayInterval",ui->dialScrapeInterval->value());

    QString locations ;
    QStandardItemModel *modelLocation = static_cast<QStandardItemModel*>(ui->lstFoldersToScan->model());

    int mcnt = modelLocation->rowCount();
    for(int i=0;i<mcnt;i++){
        QStandardItem *item= modelLocation->item(i);
        QString val = modelLocation->data(item->index(), Qt::DisplayRole).toString();
        locations += locations.isEmpty()?val: (char)QChar::Nbsp +val;
    }
    saveini("MovieLocation",locations);


    QString regx ;
    QStandardItemModel *modelregexp = static_cast<QStandardItemModel*>(ui->lstRegExp->model());
    int rcnt = modelregexp->rowCount();
    for(int i=0;i<rcnt;i++){
        QStandardItem *item= modelregexp->item(i);
        QString val = modelregexp->data(item->index(), Qt::DisplayRole).toString();
        regx += regx.isEmpty()?val: (char)QChar::Nbsp+val;
    }
    saveini("filematchRegExp",regx);

    QString delmasks ;
    QStandardItemModel *modelmasks = static_cast<QStandardItemModel*>(ui->lstDeleteFileTypes->model());
    int fcnt = modelmasks->rowCount();
    for(int i=0;i<fcnt;i++){
        QStandardItem *item= modelmasks->item(i);
        QString val = modelmasks->data(item->index(), Qt::DisplayRole).toString();
        delmasks += delmasks.isEmpty()?val: (char)QChar::Nbsp+val;
    }
    saveini("reclaimfilemasks",delmasks);

    saveini("m4vtomp4",ui->chkm4vTompg->isChecked()?"true":"false");

    saveini("sortbyreleaseyear",ui->sortByReleaseYearFirstCheckBox->isChecked()?"true":"false");

    QString delchops ;
    QStandardItemModel *modelchops= static_cast<QStandardItemModel*>(ui->lstChoppers->model());
    int pcnt = modelchops->rowCount();
    for(int i=0;i<pcnt;i++){
        QStandardItem *item= modelchops->item(i);
        QString val = modelchops->data(item->index(), Qt::DisplayRole).toString();
        delchops += delchops.isEmpty()?val: (char)QChar::Nbsp+val;
    }
    saveini("choppers",delchops);

    saveini("dropapostrophe",ui->DropApostrophe->isChecked()?"true":"false");

    saveini("thumbsize",ui->thumbnailSizeSpinBox->value());


    this->close();
}



void ImDbSettings::on_btnSelFolder_clicked()
{
    QString sname =ui->edtSeriesFolder->text();
    if (sname.isEmpty() || sname.isNull()){
        sname = QDir::current().path();
    }
    //QVariant pdefault = ini("MovieLocation",!sname.isEmpty() ?sname:QDir::current().path());
    QString folder= QFileDialog::getExistingDirectory(this,"Select Folder",sname);
    if (!folder.isEmpty() && !folder.isNull()){
        ui->edtSeriesFolder->setText(folder);
        on_btnAddFolder_clicked();
    }
    //if (folder.isEmpty() ) return;
    //saveini("MovieLocation",folder);

}

void ImDbSettings::on_btnAddFolder_clicked()
{
    QString folder=ui->edtSeriesFolder->text();
    if (!folder.isEmpty() && !folder.isNull()){
        QStandardItemModel *model = static_cast<QStandardItemModel*>(ui->lstFoldersToScan->model());
        QStandardItem *item = new QStandardItem(folder);
        model->appendRow(item);
    }
}

/*
void ImDbSettings::selectedFolderChanged(const QModelIndexList &indexes){
    QStandardItemModel *model = static_cast<QStandardItemModel*>(ui->lstFoldersToScan->model());
    int i = indexes.first().row();
    QModelIndex index = indexes.at(i);
    QString text = model->data(index, Qt::DisplayRole).toString();
    ui->edtSeriesFolder->setText(text);

}
*/

void ImDbSettings::on_buttonBox_2_clicked(QAbstractButton *button)
{
    QStandardItemModel *model = static_cast<QStandardItemModel*>(ui->lstFoldersToScan->model());

    if (button->text().contains("Discard",Qt::CaseInsensitive)){
        QModelIndexList indexes;
        while((indexes = ui->lstFoldersToScan->selectionModel()->selectedIndexes()).size()) {
            model->removeRow(indexes.first().row());
        }

        /*
        foreach(index, indexes) {
            QString text = model->data(index, Qt::DisplayRole).toString();
            QDebug() << text;
          //  QString text = QString("(%1,%2)").arg(index.row()).arg(index.column());
          //  index.parent().
        }

        //QString text = model->data(index, Qt::DisplayRole).toString();

*/

    }
    else
    {
        model->clear();
    }


}


void ImDbSettings::on_lstFoldersToScan_clicked(const QModelIndex &index)
{
    QStandardItemModel *model = static_cast<QStandardItemModel*>(ui->lstFoldersToScan->model());
    //int i = indexes.first().row();
    //   QModelIndex index = indexes.at(i);
    QString text = model->data(index, Qt::DisplayRole).toString();
    ui->edtSeriesFolder->setText(text);
}

void ImDbSettings::on_buttonBox_3_clicked(QAbstractButton *button)
{
    if (button->text().contains("Restore",Qt::CaseInsensitive)){
        addDefaultRegExp();
    } else  if (button->text().contains("Discard",Qt::CaseInsensitive)){
        QStandardItemModel *model = static_cast<QStandardItemModel*>(ui->lstRegExp->model());
        QModelIndexList indexes;
        while((indexes = ui->lstRegExp->selectionModel()->selectedIndexes()).size()) {
            model->removeRow(indexes.first().row());
        }
    } else { //reset
        QStandardItemModel *model = static_cast<QStandardItemModel*>(ui->lstRegExp->model());
        model->clear();
    }
}

void ImDbSettings::addDefaultRegExp(){
    QStandardItemModel *model = static_cast<QStandardItemModel*>(ui->lstRegExp->model());
    model->clear();
    QStandardItem *item = new QStandardItem("(.*\\.[mp4|mpg|avi|m4v|div|mkv]{3}$)");
    model->appendRow(item);
}

void ImDbSettings::on_pushButton_clicked()
{
    QString regexp = ui->edtRegExp->text();
    if (!regexp.isEmpty()){
        QStandardItemModel *model = static_cast<QStandardItemModel*>(ui->lstRegExp->model());
        QStandardItem *item = new QStandardItem(regexp);
        model->appendRow(item);
    }
}

void ImDbSettings::on_lstRegExp_clicked(const QModelIndex &index)
{
    QStandardItemModel *model = static_cast<QStandardItemModel*>(ui->lstRegExp->model());
    //int i = indexes.first().row();
    //   QModelIndex index = indexes.at(i);
    QString text = model->data(index, Qt::DisplayRole).toString();
    ui->edtRegExp->setText(text);
}

void ImDbSettings::on_pushButton_2_clicked()
{
    QString sname =ui->edtSortedFolder->text();
    if (sname.isEmpty() || sname.isNull()){
        sname = QDir::current().path();
    }
    QString folder= QFileDialog::getExistingDirectory(this,"Select Folder",sname);
    if (!folder.isEmpty() && !folder.isNull()){
        ui->edtSortedFolder->setText(folder);
    }
}



void ImDbSettings::on_btnAddDelFileFilter_clicked()
{
    QString todelMask = ui->edtDeleteFileMatch->text();
    if (!todelMask.isEmpty()){
        QStandardItemModel *model = static_cast<QStandardItemModel*>(ui->lstDeleteFileTypes->model());
        QStandardItem *item = new QStandardItem(todelMask);
        model->appendRow(item);
    }
}

void ImDbSettings::on_lstDeleteFileTypes_clicked(const QModelIndex &index)
{
    QStandardItemModel *model = static_cast<QStandardItemModel*>(ui->lstDeleteFileTypes->model());
    //int i = indexes.first().row();
    //   QModelIndex index = indexes.at(i);
    QString text = model->data(index, Qt::DisplayRole).toString();
    ui->edtDeleteFileMatch->setText(text);
}

void ImDbSettings::on_buttonBox_4_clicked(QAbstractButton *button)
{
    if (button->text().contains("Restore",Qt::CaseInsensitive)){
        addDefaultDeleteMasks();
    } else  if (button->text().contains("Discard",Qt::CaseInsensitive)){
        QStandardItemModel *model = static_cast<QStandardItemModel*>(ui->lstDeleteFileTypes->model());
        QModelIndexList indexes;
        while((indexes = ui->lstDeleteFileTypes->selectionModel()->selectedIndexes()).size()) {
            model->removeRow(indexes.first().row());
        }
    } else { //reset
        QStandardItemModel *model = static_cast<QStandardItemModel*>(ui->lstDeleteFileTypes->model());
        model->clear();
    }
}


void ImDbSettings::addDefaultDeleteMasks(){
    QStandardItemModel *model = static_cast<QStandardItemModel*>(ui->lstDeleteFileTypes->model());
    model->clear();
    model->appendRow(new QStandardItem("*.db"));
    model->appendRow(new QStandardItem("*.txt"));
    model->appendRow(new QStandardItem("*.ini"));
    model->appendRow(new QStandardItem("*.nfo"));
    model->appendRow(new QStandardItem("*.DS_Store"));
    model->appendRow(new QStandardItem("*.gif"));
    model->appendRow(new QStandardItem("*.jpg"));
    model->appendRow(new QStandardItem("*.ico"));
    model->appendRow(new QStandardItem("*.bmp"));
    model->appendRow(new QStandardItem("*.png"));
    model->appendRow(new QStandardItem("*.srt"));
    model->appendRow(new QStandardItem("*.tor*"));



}

void ImDbSettings::on_btnAddDelFileFilter_2_clicked()
{

    QString tochop = ui->edtChop->text();
    if (!tochop.isEmpty()){
        QStandardItemModel *model = static_cast<QStandardItemModel*>(ui->lstChoppers->model());
        QStandardItem *item = new QStandardItem(tochop);
        model->appendRow(item);
    }
}

void ImDbSettings::on_buttonBox_5_clicked(QAbstractButton *button)
{
    if (button->text().contains("Restore",Qt::CaseInsensitive)){
        addDefaultChoppers();
    } else  if (button->text().contains("Discard",Qt::CaseInsensitive)){
        QStandardItemModel *model = static_cast<QStandardItemModel*>(ui->lstChoppers->model());
        QModelIndexList indexes;
        while((indexes = ui->lstChoppers->selectionModel()->selectedIndexes()).size()) {
            model->removeRow(indexes.first().row());
        }
    } else { //reset
        QStandardItemModel *model = static_cast<QStandardItemModel*>(ui->lstChoppers->model());
        model->clear();
    }
}

//the sequence counts , eg dvdrip will be chopped before [ etc
void ImDbSettings::addDefaultChoppers(){
    QStandardItemModel *model = static_cast<QStandardItemModel*>(ui->lstChoppers->model());
    model->clear();
    model->appendRow(new QStandardItem("dvdrip"));
    model->appendRow(new QStandardItem("pvrip"));
    model->appendRow(new QStandardItem("brrip"));
    model->appendRow(new QStandardItem("bdrip"));
    model->appendRow(new QStandardItem("dvdscr"));
    model->appendRow(new QStandardItem("cam xvid"));
    model->appendRow(new QStandardItem("xvid"));
    model->appendRow(new QStandardItem("["));
    model->appendRow(new QStandardItem("("));
    model->appendRow(new QStandardItem("{"));
}

void ImDbSettings::on_lstChoppers_clicked(const QModelIndex &index)
{

    QStandardItemModel *model = static_cast<QStandardItemModel*>(ui->lstChoppers->model());
    QString text = model->data(index, Qt::DisplayRole).toString();
    ui->edtChop->setText(text);

}
