/********************************************************************************
** Form generated from reading UI file 'imdb.ui'
**
** Created: Wed 18. Dec 13:10:59 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMDB_H
#define UI_IMDB_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLCDNumber>
#include <QLabel>
#include <QListWidget>
#include <QMdiArea>
#include <QPlainTextEdit>
#include <QProgressBar>
#include <QSpacerItem>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QWidget>
#include <QWebView>
#include "gallerypages.h"
#include "reviewpages.h"

QT_BEGIN_NAMESPACE

class Ui_imdb
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QLCDNumber *lcdMovieProcessedOk;
    QLCDNumber *lcdMovieProcessedFailed;
    QLabel *label_3;
    QLCDNumber *lcdTotalMovies;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLCDNumber *lcdHour;
    QLCDNumber *lcdMinute;
    QLCDNumber *lcdSecond;
    QLCDNumber *lcdMilisec;
    QMdiArea *mdiArea;
    QWidget *subwindow;
    QHBoxLayout *horizontalLayout_2;
    QWebView *wvImdb;
    QWidget *subwindow_2;
    QVBoxLayout *verticalLayout_9;
    GalleryPages *tabCategoryGroups;
    QWidget *subwindow_3;
    QVBoxLayout *verticalLayout_10;
    ReviewPages *pageReviews;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QWebView *wvStatus;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QPlainTextEdit *edtLog;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_8;
    QListWidget *lstFailedFiles;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_12;
    QListWidget *lstMissingMoviePictures;
    QProgressBar *progressBar;

    void setupUi(QWidget *imdb)
    {
        if (imdb->objectName().isEmpty())
            imdb->setObjectName(QString::fromUtf8("imdb"));
        imdb->resize(800, 550);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(imdb->sizePolicy().hasHeightForWidth());
        imdb->setSizePolicy(sizePolicy);
        imdb->setMinimumSize(QSize(800, 550));
        verticalLayout_2 = new QVBoxLayout(imdb);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 11, 10, 10);
        label_2 = new QLabel(imdb);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        lcdMovieProcessedOk = new QLCDNumber(imdb);
        lcdMovieProcessedOk->setObjectName(QString::fromUtf8("lcdMovieProcessedOk"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lcdMovieProcessedOk->sizePolicy().hasHeightForWidth());
        lcdMovieProcessedOk->setSizePolicy(sizePolicy1);
        lcdMovieProcessedOk->setMaximumSize(QSize(40, 16777215));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 255, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(127, 255, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(63, 255, 63, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(0, 127, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(0, 170, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        lcdMovieProcessedOk->setPalette(palette);
        lcdMovieProcessedOk->setFrameShape(QFrame::NoFrame);
        lcdMovieProcessedOk->setFrameShadow(QFrame::Sunken);
        lcdMovieProcessedOk->setLineWidth(0);

        horizontalLayout->addWidget(lcdMovieProcessedOk);

        lcdMovieProcessedFailed = new QLCDNumber(imdb);
        lcdMovieProcessedFailed->setObjectName(QString::fromUtf8("lcdMovieProcessedFailed"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lcdMovieProcessedFailed->sizePolicy().hasHeightForWidth());
        lcdMovieProcessedFailed->setSizePolicy(sizePolicy2);
        lcdMovieProcessedFailed->setMaximumSize(QSize(40, 16777215));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush8(QColor(255, 0, 0, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush8);
        QBrush brush9(QColor(255, 127, 127, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush9);
        QBrush brush10(QColor(255, 63, 63, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush10);
        QBrush brush11(QColor(127, 0, 0, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush11);
        QBrush brush12(QColor(170, 0, 0, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        lcdMovieProcessedFailed->setPalette(palette1);
        lcdMovieProcessedFailed->setFrameShape(QFrame::NoFrame);
        lcdMovieProcessedFailed->setFrameShadow(QFrame::Sunken);
        lcdMovieProcessedFailed->setLineWidth(0);

        horizontalLayout->addWidget(lcdMovieProcessedFailed);

        label_3 = new QLabel(imdb);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        lcdTotalMovies = new QLCDNumber(imdb);
        lcdTotalMovies->setObjectName(QString::fromUtf8("lcdTotalMovies"));
        sizePolicy1.setHeightForWidth(lcdTotalMovies->sizePolicy().hasHeightForWidth());
        lcdTotalMovies->setSizePolicy(sizePolicy1);
        lcdTotalMovies->setMaximumSize(QSize(40, 16777215));
        lcdTotalMovies->setFrameShape(QFrame::NoFrame);
        lcdTotalMovies->setFrameShadow(QFrame::Sunken);
        lcdTotalMovies->setLineWidth(0);

        horizontalLayout->addWidget(lcdTotalMovies);

        label = new QLabel(imdb);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        lcdHour = new QLCDNumber(imdb);
        lcdHour->setObjectName(QString::fromUtf8("lcdHour"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lcdHour->sizePolicy().hasHeightForWidth());
        lcdHour->setSizePolicy(sizePolicy3);
        lcdHour->setMaximumSize(QSize(40, 16777215));
        lcdHour->setFrameShape(QFrame::NoFrame);
        lcdHour->setFrameShadow(QFrame::Sunken);
        lcdHour->setLineWidth(0);
        lcdHour->setMidLineWidth(0);
        lcdHour->setSmallDecimalPoint(false);
        lcdHour->setSegmentStyle(QLCDNumber::Filled);

        horizontalLayout->addWidget(lcdHour);

        lcdMinute = new QLCDNumber(imdb);
        lcdMinute->setObjectName(QString::fromUtf8("lcdMinute"));
        sizePolicy3.setHeightForWidth(lcdMinute->sizePolicy().hasHeightForWidth());
        lcdMinute->setSizePolicy(sizePolicy3);
        lcdMinute->setMaximumSize(QSize(40, 16777215));
        lcdMinute->setFrameShape(QFrame::NoFrame);
        lcdMinute->setFrameShadow(QFrame::Sunken);
        lcdMinute->setLineWidth(0);
        lcdMinute->setMidLineWidth(0);
        lcdMinute->setSmallDecimalPoint(false);
        lcdMinute->setSegmentStyle(QLCDNumber::Filled);

        horizontalLayout->addWidget(lcdMinute);

        lcdSecond = new QLCDNumber(imdb);
        lcdSecond->setObjectName(QString::fromUtf8("lcdSecond"));
        sizePolicy3.setHeightForWidth(lcdSecond->sizePolicy().hasHeightForWidth());
        lcdSecond->setSizePolicy(sizePolicy3);
        lcdSecond->setMaximumSize(QSize(40, 16777215));
        lcdSecond->setFrameShape(QFrame::NoFrame);
        lcdSecond->setFrameShadow(QFrame::Sunken);
        lcdSecond->setLineWidth(0);
        lcdSecond->setMidLineWidth(0);
        lcdSecond->setSmallDecimalPoint(false);
        lcdSecond->setSegmentStyle(QLCDNumber::Filled);

        horizontalLayout->addWidget(lcdSecond);

        lcdMilisec = new QLCDNumber(imdb);
        lcdMilisec->setObjectName(QString::fromUtf8("lcdMilisec"));
        sizePolicy3.setHeightForWidth(lcdMilisec->sizePolicy().hasHeightForWidth());
        lcdMilisec->setSizePolicy(sizePolicy3);
        lcdMilisec->setMaximumSize(QSize(40, 16777215));
        lcdMilisec->setFrameShape(QFrame::NoFrame);
        lcdMilisec->setFrameShadow(QFrame::Sunken);
        lcdMilisec->setLineWidth(0);
        lcdMilisec->setMidLineWidth(0);
        lcdMilisec->setSmallDecimalPoint(false);
        lcdMilisec->setSegmentStyle(QLCDNumber::Filled);

        horizontalLayout->addWidget(lcdMilisec);


        verticalLayout->addLayout(horizontalLayout);

        mdiArea = new QMdiArea(imdb);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setViewMode(QMdiArea::SubWindowView);
        mdiArea->setTabPosition(QTabWidget::North);
        subwindow = new QWidget();
        subwindow->setObjectName(QString::fromUtf8("subwindow"));
        horizontalLayout_2 = new QHBoxLayout(subwindow);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        wvImdb = new QWebView(subwindow);
        wvImdb->setObjectName(QString::fromUtf8("wvImdb"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(wvImdb->sizePolicy().hasHeightForWidth());
        wvImdb->setSizePolicy(sizePolicy4);
        wvImdb->setMinimumSize(QSize(400, 200));
        wvImdb->setUrl(QUrl(QString::fromUtf8("about:blank")));

        horizontalLayout_2->addWidget(wvImdb);

        mdiArea->addSubWindow(subwindow);
        subwindow_2 = new QWidget();
        subwindow_2->setObjectName(QString::fromUtf8("subwindow_2"));
        verticalLayout_9 = new QVBoxLayout(subwindow_2);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        tabCategoryGroups = new GalleryPages(subwindow_2);
        tabCategoryGroups->setObjectName(QString::fromUtf8("tabCategoryGroups"));
        tabCategoryGroups->setMinimumSize(QSize(400, 200));

        verticalLayout_9->addWidget(tabCategoryGroups);

        mdiArea->addSubWindow(subwindow_2);
        subwindow_3 = new QWidget();
        subwindow_3->setObjectName(QString::fromUtf8("subwindow_3"));
        verticalLayout_10 = new QVBoxLayout(subwindow_3);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        pageReviews = new ReviewPages(subwindow_3);
        pageReviews->setObjectName(QString::fromUtf8("pageReviews"));
        pageReviews->setMinimumSize(QSize(400, 200));
        pageReviews->setTabsClosable(true);
        pageReviews->setMovable(true);

        verticalLayout_10->addWidget(pageReviews);

        mdiArea->addSubWindow(subwindow_3);

        verticalLayout->addWidget(mdiArea);

        stackedWidget = new QStackedWidget(imdb);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy5);
        stackedWidget->setMinimumSize(QSize(0, 137));
        stackedWidget->setMaximumSize(QSize(16777215, 195));
        stackedWidget->setFrameShape(QFrame::StyledPanel);
        stackedWidget->setFrameShadow(QFrame::Sunken);
        stackedWidget->setMidLineWidth(0);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_4 = new QVBoxLayout(page);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, 14, -1, -1);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 0, -1, -1);
        wvStatus = new QWebView(page);
        wvStatus->setObjectName(QString::fromUtf8("wvStatus"));
        sizePolicy4.setHeightForWidth(wvStatus->sizePolicy().hasHeightForWidth());
        wvStatus->setSizePolicy(sizePolicy4);
        wvStatus->setMinimumSize(QSize(0, 0));
        wvStatus->setMaximumSize(QSize(16777215, 195));
        wvStatus->setUrl(QUrl(QString::fromUtf8("qrc:/html/html/Status.html")));

        verticalLayout_3->addWidget(wvStatus);


        verticalLayout_4->addLayout(verticalLayout_3);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_6 = new QVBoxLayout(page_2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(-1, 14, -1, -1);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(-1, 0, -1, -1);
        edtLog = new QPlainTextEdit(page_2);
        edtLog->setObjectName(QString::fromUtf8("edtLog"));

        verticalLayout_5->addWidget(edtLog);


        verticalLayout_6->addLayout(verticalLayout_5);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        verticalLayout_7 = new QVBoxLayout(page_3);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(-1, 14, -1, -1);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        lstFailedFiles = new QListWidget(page_3);
        lstFailedFiles->setObjectName(QString::fromUtf8("lstFailedFiles"));

        verticalLayout_8->addWidget(lstFailedFiles);


        verticalLayout_7->addLayout(verticalLayout_8);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        verticalLayout_11 = new QVBoxLayout(page_4);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(-1, 14, -1, -1);
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        lstMissingMoviePictures = new QListWidget(page_4);
        lstMissingMoviePictures->setObjectName(QString::fromUtf8("lstMissingMoviePictures"));

        verticalLayout_12->addWidget(lstMissingMoviePictures);


        verticalLayout_11->addLayout(verticalLayout_12);

        stackedWidget->addWidget(page_4);

        verticalLayout->addWidget(stackedWidget);

        progressBar = new QProgressBar(imdb);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(imdb);

        tabCategoryGroups->setCurrentIndex(-1);
        pageReviews->setCurrentIndex(-1);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(imdb);
    } // setupUi

    void retranslateUi(QWidget *imdb)
    {
        imdb->setWindowTitle(QApplication::translate("imdb", "Form", 0));
        label_2->setText(QApplication::translate("imdb", "Processed", 0));
#ifndef QT_NO_TOOLTIP
        lcdMovieProcessedOk->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lcdMovieProcessedOk->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lcdMovieProcessedOk->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        lcdMovieProcessedFailed->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lcdMovieProcessedFailed->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lcdMovieProcessedFailed->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_3->setText(QApplication::translate("imdb", "/", 0));
#ifndef QT_NO_TOOLTIP
        lcdTotalMovies->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lcdTotalMovies->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lcdTotalMovies->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("imdb", "Next Action", 0));
        subwindow->setWindowTitle(QApplication::translate("imdb", "IMDB", 0));
        subwindow_2->setWindowTitle(QApplication::translate("imdb", "Categories", 0));
        subwindow_3->setWindowTitle(QApplication::translate("imdb", "Movie Reviews", 0));
    } // retranslateUi

};

namespace Ui {
    class imdb: public Ui_imdb {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMDB_H
