#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imdbsettings.h"
#include "imdb.h"
#include <QObject>
#include <QRect>
#include <QPoint>
#include <QApplication>
#include <QDesktopWidget>
#include <QActionGroup>
#include <QLineEdit>

//const QString MainWindow::avimpg = QString("(?:[Ss])(\\d+)(?:[Ee](\\d+)(?:[Ee](\\d+))?)?");
//const QString MainWindow::allfiles = QString("(?:[Ss])(\\d+)(?:[Ee](\\d+)(?:[Ee](\\d+))?)?");


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{

    ui->setupUi(this);
    centerInDesktop();
    //ui->centralWidget->setLayout(ui->centralWidget->findChild<QVBoxLayout*>());
    m_imdb = new imdb(this);
    setCentralWidget(m_imdb);
    m_filefilter = new QLineEdit(this);


    ui->menuFile->addAction(ui->actionPreferences);

    //ui->actionPreferences->setShortcut(QKeySequence::Print);
    // ui->actionView_Logs->setShortcut(QKeySequence::HelpContents);
    ui->menuFile->addSeparator();
    ui->menuFile->addAction(ui->actionExit);


    ui->menuMovies->addAction(ui->actionScan);
    ui->menuMovies->addAction(ui->actionRefresh_Categories);
    //ui->actionScan->setShortcut(QKeySequence::New);
    ui->menuMovies->addSeparator();
    ui->menuMovies->addAction(ui->actionReclaim_Space);
    //ui->actionView_Remaining_Movies->setShortcut(QKeySequence::SaveAs);
    //ui->actionScan->setShortcut(QKeySequence::Delete);


    ui->menuInfo->addAction(ui->actionView_Status);
    ui->menuInfo->addSeparator();
    ui->menuInfo->addAction(ui->actionView_Logs);
    ui->menuInfo->addAction(ui->actionView_Remaining_Movies);
    ui->menuInfo->addAction(ui->actionMissing_Gallery_Pictures);


    m_statusGroup = new QActionGroup(this);
    m_statusGroup->addAction(ui->actionView_Status);
    m_statusGroup->addAction(ui->actionView_Logs);
    m_statusGroup->addAction(ui->actionView_Remaining_Movies);
    m_statusGroup->addAction(ui->actionMissing_Gallery_Pictures);



    //ui->menuMovies->addAction(ui->actionRefresh_Internal_Movie_List);
    //  QObject::connect(ui->actionRefresh_Internal_Movie_List,SIGNAL(triggered()),this->centralWidget(),SLOT(dorefresh()));
    ui->mainToolBar->addAction(ui->actionPreferences);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(ui->actionView_Status);
    ui->actionView_Status->setChecked(true);
    ui->mainToolBar->addAction(ui->actionView_Logs);
    ui->mainToolBar->addAction(ui->actionView_Remaining_Movies);
    ui->mainToolBar->addAction(ui->actionMissing_Gallery_Pictures);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(ui->actionReclaim_Space);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(ui->actionScan);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(ui->actionStop);
    ui->mainToolBar->addAction(ui->actionPush_Que);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(ui->actionRefresh_Categories);
    ui->mainToolBar->addSeparator();

   // QLayout *layout = new QHBoxLayout(this);
  //  layout->addWidget(m_filefilter);
   // m_filefilter->setLayout(layout);
    actLayout_filter =  ui->mainToolBar->addWidget(m_filefilter);
    ui->mainToolBar->addSeparator();


    QObject::connect(ui->actionPreferences,SIGNAL(triggered()),this,SLOT(showPreferences()));
    QObject::connect(ui->actionScan,SIGNAL(triggered()),this->centralWidget(),SLOT(dorun()));
    QObject::connect(ui->actionView_Status,SIGNAL(triggered()),this->centralWidget(),SLOT(showStatus()));
    QObject::connect(ui->actionView_Logs,SIGNAL(triggered()),this->centralWidget(),SLOT(showLogs()));
    QObject::connect(ui->actionReclaim_Space,SIGNAL(triggered()),this->centralWidget(),SLOT(doFolderCleanup()));
    QObject::connect(ui->actionView_Remaining_Movies,SIGNAL(triggered()),this->centralWidget(),SLOT(doShowRemainingMovies()));
    QObject::connect(ui->actionStop,SIGNAL(triggered()),this->centralWidget(),SLOT(doStopScan()));
    QObject::connect(ui->actionPush_Que,SIGNAL(triggered()),this->centralWidget(),SLOT(doPushQue()));
    QObject::connect(ui->actionRefresh_Categories,SIGNAL(triggered()),this->centralWidget(),SLOT(doRefreshCategoryTabs()));

    QObject::connect(ui->actionMissing_Gallery_Pictures,SIGNAL(triggered()),this->centralWidget(),SLOT(CheckMovieHasPicInGallery()));

   QObject::connect(m_filefilter,SIGNAL(textChanged(QString)),this->centralWidget(),SLOT(doSearchForTextchanged(QString)));
   QObject::connect(m_filefilter,SIGNAL(textEdited(QString)),this->centralWidget(),SLOT(doSearchForTextchanged(QString)));
   QObject::connect(m_filefilter,SIGNAL(returnPressed()),this->centralWidget(),SLOT(doSearchForEditingFinished()));

}

MainWindow::~MainWindow()
{
    delete m_filefilter;
    delete m_imdb;
    //delete m_statusGroup;
    delete ui;

}

void MainWindow::centerInDesktop(){
    QRect desktopRect = QApplication::desktop()->availableGeometry(this);
    QPoint center = desktopRect.center();
    int left = center.x();
    int width = this->geometry().width();
    left -=  width*0.5;

    int top = center.y();
    int height= this->geometry().height();
    top -= height*0.75; // was .5 but .75 looks better


    if (top < 11) {top=10;}
    if (left < 11) {left = 10;}
    move(left,top);
    resize(0,0);
    //move(QPoint(center.x()-(width*0.5), center.y()-(height*0.5)));
}

void MainWindow::showPreferences()
{
    ImDbSettings *setting = new ImDbSettings(this);
    if(  setting->exec() ==  QDialog::Accepted){
    }
}
