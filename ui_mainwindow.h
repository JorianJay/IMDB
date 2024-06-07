/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed 18. Dec 13:10:59 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QHeaderView>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QVBoxLayout>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionPreferences;
    QAction *actionScan;
    QAction *actionRefresh_Internal_Movie_List;
    QAction *actionView_Logs;
    QAction *actionReclaim_Space;
    QAction *actionView_Remaining_Movies;
    QAction *actionStop;
    QAction *actionView_Status;
    QAction *actionPush_Que;
    QAction *actionRefresh_Categories;
    QAction *actionMissing_Gallery_Pictures;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuMovies;
    QMenu *menuInfo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 550);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/movie"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/prefs"), QSize(), QIcon::Normal, QIcon::Off);
        actionPreferences->setIcon(icon1);
        actionScan = new QAction(MainWindow);
        actionScan->setObjectName(QString::fromUtf8("actionScan"));
        actionScan->setIcon(icon);
        actionRefresh_Internal_Movie_List = new QAction(MainWindow);
        actionRefresh_Internal_Movie_List->setObjectName(QString::fromUtf8("actionRefresh_Internal_Movie_List"));
        actionView_Logs = new QAction(MainWindow);
        actionView_Logs->setObjectName(QString::fromUtf8("actionView_Logs"));
        actionView_Logs->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/logs"), QSize(), QIcon::Normal, QIcon::Off);
        actionView_Logs->setIcon(icon2);
        actionReclaim_Space = new QAction(MainWindow);
        actionReclaim_Space->setObjectName(QString::fromUtf8("actionReclaim_Space"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/recycle"), QSize(), QIcon::Normal, QIcon::Off);
        actionReclaim_Space->setIcon(icon3);
        actionView_Remaining_Movies = new QAction(MainWindow);
        actionView_Remaining_Movies->setObjectName(QString::fromUtf8("actionView_Remaining_Movies"));
        actionView_Remaining_Movies->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/fix"), QSize(), QIcon::Normal, QIcon::Off);
        actionView_Remaining_Movies->setIcon(icon4);
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/Stop"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon5);
        actionView_Status = new QAction(MainWindow);
        actionView_Status->setObjectName(QString::fromUtf8("actionView_Status"));
        actionView_Status->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/info"), QSize(), QIcon::Normal, QIcon::Off);
        actionView_Status->setIcon(icon6);
        actionPush_Que = new QAction(MainWindow);
        actionPush_Que->setObjectName(QString::fromUtf8("actionPush_Que"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/Push"), QSize(), QIcon::Normal, QIcon::Off);
        actionPush_Que->setIcon(icon7);
        actionRefresh_Categories = new QAction(MainWindow);
        actionRefresh_Categories->setObjectName(QString::fromUtf8("actionRefresh_Categories"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/Categorise"), QSize(), QIcon::Normal, QIcon::Off);
        actionRefresh_Categories->setIcon(icon8);
        actionMissing_Gallery_Pictures = new QAction(MainWindow);
        actionMissing_Gallery_Pictures->setObjectName(QString::fromUtf8("actionMissing_Gallery_Pictures"));
        actionMissing_Gallery_Pictures->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/photos"), QSize(), QIcon::Normal, QIcon::Off);
        actionMissing_Gallery_Pictures->setIcon(icon9);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menuBar->setDefaultUp(false);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuMovies = new QMenu(menuBar);
        menuMovies->setObjectName(QString::fromUtf8("menuMovies"));
        menuInfo = new QMenu(menuBar);
        menuInfo->setObjectName(QString::fromUtf8("menuInfo"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuMovies->menuAction());
        menuBar->addAction(menuInfo->menuAction());

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "IMDB Categorized", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("MainWindow", "Exit", 0));
#endif // QT_NO_TOOLTIP
        actionPreferences->setText(QApplication::translate("MainWindow", "Preferences", 0));
        actionPreferences->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0));
        actionScan->setText(QApplication::translate("MainWindow", "Scan", 0));
#ifndef QT_NO_TOOLTIP
        actionScan->setToolTip(QApplication::translate("MainWindow", "Scan and Categorize", 0));
#endif // QT_NO_TOOLTIP
        actionScan->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionRefresh_Internal_Movie_List->setText(QApplication::translate("MainWindow", "Refresh Internal Movie List", 0));
#ifndef QT_NO_TOOLTIP
        actionRefresh_Internal_Movie_List->setToolTip(QApplication::translate("MainWindow", "Refresh Movie List", 0));
#endif // QT_NO_TOOLTIP
        actionView_Logs->setText(QApplication::translate("MainWindow", "View Logs", 0));
#ifndef QT_NO_TOOLTIP
        actionView_Logs->setToolTip(QApplication::translate("MainWindow", "View Logs", 0));
#endif // QT_NO_TOOLTIP
        actionView_Logs->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", 0));
        actionReclaim_Space->setText(QApplication::translate("MainWindow", "Reclaim Space", 0));
#ifndef QT_NO_TOOLTIP
        actionReclaim_Space->setToolTip(QApplication::translate("MainWindow", "Reclaim Space", 0));
#endif // QT_NO_TOOLTIP
        actionView_Remaining_Movies->setText(QApplication::translate("MainWindow", "View Remaining Movies (Manual Fix)", 0));
#ifndef QT_NO_TOOLTIP
        actionView_Remaining_Movies->setToolTip(QApplication::translate("MainWindow", "View Remaining Movies", 0));
#endif // QT_NO_TOOLTIP
        actionView_Remaining_Movies->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0));
        actionStop->setText(QApplication::translate("MainWindow", "Stop", 0));
#ifndef QT_NO_TOOLTIP
        actionStop->setToolTip(QApplication::translate("MainWindow", "Stop Scan", 0));
#endif // QT_NO_TOOLTIP
        actionStop->setShortcut(QApplication::translate("MainWindow", "Esc", 0));
        actionView_Status->setText(QApplication::translate("MainWindow", "Status", 0));
#ifndef QT_NO_TOOLTIP
        actionView_Status->setToolTip(QApplication::translate("MainWindow", "View Status", 0));
#endif // QT_NO_TOOLTIP
        actionView_Status->setShortcut(QApplication::translate("MainWindow", "Ctrl+I", 0));
        actionPush_Que->setText(QApplication::translate("MainWindow", "Jump Que", 0));
#ifndef QT_NO_TOOLTIP
        actionPush_Que->setToolTip(QApplication::translate("MainWindow", "Jump Que", 0));
#endif // QT_NO_TOOLTIP
        actionPush_Que->setShortcut(QApplication::translate("MainWindow", "Ctrl+J", 0));
        actionRefresh_Categories->setText(QApplication::translate("MainWindow", "Refresh Categories", 0));
#ifndef QT_NO_TOOLTIP
        actionRefresh_Categories->setToolTip(QApplication::translate("MainWindow", "Refresh Categories", 0));
#endif // QT_NO_TOOLTIP
        actionRefresh_Categories->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0));
        actionMissing_Gallery_Pictures->setText(QApplication::translate("MainWindow", "Missing Gallery Pictures", 0));
#ifndef QT_NO_TOOLTIP
        actionMissing_Gallery_Pictures->setToolTip(QApplication::translate("MainWindow", "Missing Gallery Pictures", 0));
#endif // QT_NO_TOOLTIP
        actionMissing_Gallery_Pictures->setShortcut(QApplication::translate("MainWindow", "Ctrl+G", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuMovies->setTitle(QApplication::translate("MainWindow", "Movies", 0));
        menuInfo->setTitle(QApplication::translate("MainWindow", "Info", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
