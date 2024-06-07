/********************************************************************************
** Form generated from reading UI file 'imdbsettings.ui'
**
** Created: Wed 18. Dec 13:10:59 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMDBSETTINGS_H
#define UI_IMDBSETTINGS_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QCheckBox>
#include <QDial>
#include <QDialog>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QListView>
#include <QPushButton>
#include <QSpacerItem>
#include <QSpinBox>
#include <QToolBox>
#include <QVBoxLayout>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImDbSettings
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *edtDemonoidUrl;
    QLabel *sortedFolderLabel;
    QHBoxLayout *horizontalLayout_12;
    QLineEdit *edtSortedFolder;
    QPushButton *pushButton_2;
    QLabel *sortByReleaseYearFirstLabel;
    QCheckBox *sortByReleaseYearFirstCheckBox;
    QLabel *dropApostrophesLabel;
    QCheckBox *DropApostrophe;
    QLabel *label_2;
    QCheckBox *chkm4vTompg;
    QLabel *thumbnailSizeLabel;
    QSpinBox *thumbnailSizeSpinBox;
    QLabel *label_3;
    QLabel *label_4;
    QToolBox *toolBox_2;
    QWidget *page_5;
    QVBoxLayout *verticalLayout_15;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_14;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLabel *lblScrapeInterval;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_7;
    QDial *dialScrapeInterval;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *edtDeleteFileMatch;
    QPushButton *btnAddDelFileFilter;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_9;
    QListView *lstDeleteFileTypes;
    QDialogButtonBox *buttonBox_4;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_14;
    QLineEdit *edtChop;
    QPushButton *btnAddDelFileFilter_2;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_11;
    QListView *lstChoppers;
    QDialogButtonBox *buttonBox_5;
    QWidget *page_4;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout;
    QLineEdit *edtRegExp;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_7;
    QListView *lstRegExp;
    QDialogButtonBox *buttonBox_3;
    QWidget *page_3;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *edtSeriesFolder;
    QPushButton *btnSelFolder;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnAddFolder;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_4;
    QListView *lstFoldersToScan;
    QDialogButtonBox *buttonBox_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ImDbSettings)
    {
        if (ImDbSettings->objectName().isEmpty())
            ImDbSettings->setObjectName(QString::fromUtf8("ImDbSettings"));
        ImDbSettings->setWindowModality(Qt::WindowModal);
        ImDbSettings->resize(733, 600);
        ImDbSettings->setWindowOpacity(0.95);
        ImDbSettings->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"     border-width: 2px;\n"
"     border-radius: 8px;\n"
"     color:rgb(0, 0, 0);\n"
"     margin:2px;\n"
"	font: 10pt \"MS Shell Dlg 2\";\n"
"}\n"
"\n"
"QLabel {\n"
"	font: 75 9pt \"MS Shell Dlg 2\";\n"
"}\n"
"QPushButton{\n"
"color: rgb(255,255,255);\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgb(0, 0, 255),  stop:1 rgb(0, 0, 0));\n"
"   border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 8px;\n"
"     border-color: beige;\n"
"     font: bold 12px;\n"
"     min-width: 5em;\n"
"     padding: 2px;\n"
" }\n"
" QPushButton:pressed {\n"
"	background-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 2"
                        "55), stop:0.75 rgba(218, 202, 86, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255));\n"
"     border-style: inset;\n"
" }\n"
"\n"
""));
        ImDbSettings->setSizeGripEnabled(true);
        ImDbSettings->setModal(true);
        verticalLayout = new QVBoxLayout(ImDbSettings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetMinimumSize);
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setHorizontalSpacing(10);
        formLayout->setVerticalSpacing(0);
        formLayout->setContentsMargins(-1, -1, 0, 0);
        label = new QLabel(ImDbSettings);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        edtDemonoidUrl = new QLineEdit(ImDbSettings);
        edtDemonoidUrl->setObjectName(QString::fromUtf8("edtDemonoidUrl"));

        formLayout->setWidget(0, QFormLayout::FieldRole, edtDemonoidUrl);

        sortedFolderLabel = new QLabel(ImDbSettings);
        sortedFolderLabel->setObjectName(QString::fromUtf8("sortedFolderLabel"));
        sortedFolderLabel->setWordWrap(true);

        formLayout->setWidget(1, QFormLayout::LabelRole, sortedFolderLabel);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(10);
        horizontalLayout_12->setContentsMargins(10, 10, 10, 10);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        edtSortedFolder = new QLineEdit(ImDbSettings);
        edtSortedFolder->setObjectName(QString::fromUtf8("edtSortedFolder"));

        horizontalLayout_12->addWidget(edtSortedFolder);

        pushButton_2 = new QPushButton(ImDbSettings);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_12->addWidget(pushButton_2);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_12);

        sortByReleaseYearFirstLabel = new QLabel(ImDbSettings);
        sortByReleaseYearFirstLabel->setObjectName(QString::fromUtf8("sortByReleaseYearFirstLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, sortByReleaseYearFirstLabel);

        sortByReleaseYearFirstCheckBox = new QCheckBox(ImDbSettings);
        sortByReleaseYearFirstCheckBox->setObjectName(QString::fromUtf8("sortByReleaseYearFirstCheckBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, sortByReleaseYearFirstCheckBox);

        dropApostrophesLabel = new QLabel(ImDbSettings);
        dropApostrophesLabel->setObjectName(QString::fromUtf8("dropApostrophesLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, dropApostrophesLabel);

        DropApostrophe = new QCheckBox(ImDbSettings);
        DropApostrophe->setObjectName(QString::fromUtf8("DropApostrophe"));

        formLayout->setWidget(3, QFormLayout::FieldRole, DropApostrophe);

        label_2 = new QLabel(ImDbSettings);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_2);

        chkm4vTompg = new QCheckBox(ImDbSettings);
        chkm4vTompg->setObjectName(QString::fromUtf8("chkm4vTompg"));

        formLayout->setWidget(4, QFormLayout::FieldRole, chkm4vTompg);

        thumbnailSizeLabel = new QLabel(ImDbSettings);
        thumbnailSizeLabel->setObjectName(QString::fromUtf8("thumbnailSizeLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, thumbnailSizeLabel);

        thumbnailSizeSpinBox = new QSpinBox(ImDbSettings);
        thumbnailSizeSpinBox->setObjectName(QString::fromUtf8("thumbnailSizeSpinBox"));
        thumbnailSizeSpinBox->setMinimum(10);
        thumbnailSizeSpinBox->setMaximum(500);
        thumbnailSizeSpinBox->setValue(100);

        formLayout->setWidget(5, QFormLayout::FieldRole, thumbnailSizeSpinBox);

        label_3 = new QLabel(ImDbSettings);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(6, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(ImDbSettings);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(7, QFormLayout::LabelRole, label_4);

        toolBox_2 = new QToolBox(ImDbSettings);
        toolBox_2->setObjectName(QString::fromUtf8("toolBox_2"));
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        verticalLayout_15 = new QVBoxLayout(page_5);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setContentsMargins(10, 10, 10, 10);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(15);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_13->setContentsMargins(15, 5, 15, -1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_6 = new QLabel(page_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setScaledContents(false);
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_6);

        lblScrapeInterval = new QLabel(page_5);
        lblScrapeInterval->setObjectName(QString::fromUtf8("lblScrapeInterval"));
        lblScrapeInterval->setMinimumSize(QSize(250, 0));
        lblScrapeInterval->setMaximumSize(QSize(250, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        lblScrapeInterval->setFont(font);
        lblScrapeInterval->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lblScrapeInterval);

        horizontalSpacer_4 = new QSpacerItem(250, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_13->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_7->setContentsMargins(-1, 0, -1, 0);
        dialScrapeInterval = new QDial(page_5);
        dialScrapeInterval->setObjectName(QString::fromUtf8("dialScrapeInterval"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dialScrapeInterval->sizePolicy().hasHeightForWidth());
        dialScrapeInterval->setSizePolicy(sizePolicy);
        dialScrapeInterval->setMinimumSize(QSize(100, 100));
        dialScrapeInterval->setMaximumSize(QSize(250, 250));
        QPalette palette;
        QRadialGradient gradient(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(255, 255, 255, 255));
        gradient.setColorAt(0.1, QColor(255, 255, 255, 255));
        gradient.setColorAt(0.2, QColor(255, 176, 176, 167));
        gradient.setColorAt(0.3, QColor(255, 151, 151, 92));
        gradient.setColorAt(0.4, QColor(255, 125, 125, 51));
        gradient.setColorAt(0.5, QColor(255, 76, 76, 205));
        gradient.setColorAt(0.52, QColor(255, 76, 76, 205));
        gradient.setColorAt(0.6, QColor(255, 180, 180, 84));
        gradient.setColorAt(1, QColor(255, 255, 255, 0));
        QBrush brush(gradient);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QRadialGradient gradient1(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(255, 255, 255, 255));
        gradient1.setColorAt(0.1, QColor(255, 255, 255, 255));
        gradient1.setColorAt(0.2, QColor(255, 176, 176, 167));
        gradient1.setColorAt(0.3, QColor(255, 151, 151, 92));
        gradient1.setColorAt(0.4, QColor(255, 125, 125, 51));
        gradient1.setColorAt(0.5, QColor(255, 76, 76, 205));
        gradient1.setColorAt(0.52, QColor(255, 76, 76, 205));
        gradient1.setColorAt(0.6, QColor(255, 180, 180, 84));
        gradient1.setColorAt(1, QColor(255, 255, 255, 0));
        QBrush brush1(gradient1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QRadialGradient gradient2(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(255, 255, 255, 255));
        gradient2.setColorAt(0.1, QColor(255, 255, 255, 255));
        gradient2.setColorAt(0.2, QColor(255, 176, 176, 167));
        gradient2.setColorAt(0.3, QColor(255, 151, 151, 92));
        gradient2.setColorAt(0.4, QColor(255, 125, 125, 51));
        gradient2.setColorAt(0.5, QColor(255, 76, 76, 205));
        gradient2.setColorAt(0.52, QColor(255, 76, 76, 205));
        gradient2.setColorAt(0.6, QColor(255, 180, 180, 84));
        gradient2.setColorAt(1, QColor(255, 255, 255, 0));
        QBrush brush2(gradient2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        QRadialGradient gradient3(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(255, 255, 255, 255));
        gradient3.setColorAt(0.1, QColor(255, 255, 255, 255));
        gradient3.setColorAt(0.2, QColor(255, 176, 176, 167));
        gradient3.setColorAt(0.3, QColor(255, 151, 151, 92));
        gradient3.setColorAt(0.4, QColor(255, 125, 125, 51));
        gradient3.setColorAt(0.5, QColor(255, 76, 76, 205));
        gradient3.setColorAt(0.52, QColor(255, 76, 76, 205));
        gradient3.setColorAt(0.6, QColor(255, 180, 180, 84));
        gradient3.setColorAt(1, QColor(255, 255, 255, 0));
        QBrush brush3(gradient3);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        QRadialGradient gradient4(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(255, 255, 255, 255));
        gradient4.setColorAt(0.1, QColor(255, 255, 255, 255));
        gradient4.setColorAt(0.2, QColor(255, 176, 176, 167));
        gradient4.setColorAt(0.3, QColor(255, 151, 151, 92));
        gradient4.setColorAt(0.4, QColor(255, 125, 125, 51));
        gradient4.setColorAt(0.5, QColor(255, 76, 76, 205));
        gradient4.setColorAt(0.52, QColor(255, 76, 76, 205));
        gradient4.setColorAt(0.6, QColor(255, 180, 180, 84));
        gradient4.setColorAt(1, QColor(255, 255, 255, 0));
        QBrush brush4(gradient4);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        QRadialGradient gradient5(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(255, 255, 255, 255));
        gradient5.setColorAt(0.1, QColor(255, 255, 255, 255));
        gradient5.setColorAt(0.2, QColor(255, 176, 176, 167));
        gradient5.setColorAt(0.3, QColor(255, 151, 151, 92));
        gradient5.setColorAt(0.4, QColor(255, 125, 125, 51));
        gradient5.setColorAt(0.5, QColor(255, 76, 76, 205));
        gradient5.setColorAt(0.52, QColor(255, 76, 76, 205));
        gradient5.setColorAt(0.6, QColor(255, 180, 180, 84));
        gradient5.setColorAt(1, QColor(255, 255, 255, 0));
        QBrush brush5(gradient5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        QRadialGradient gradient6(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(255, 255, 255, 255));
        gradient6.setColorAt(0.1, QColor(255, 255, 255, 255));
        gradient6.setColorAt(0.2, QColor(255, 176, 176, 167));
        gradient6.setColorAt(0.3, QColor(255, 151, 151, 92));
        gradient6.setColorAt(0.4, QColor(255, 125, 125, 51));
        gradient6.setColorAt(0.5, QColor(255, 76, 76, 205));
        gradient6.setColorAt(0.52, QColor(255, 76, 76, 205));
        gradient6.setColorAt(0.6, QColor(255, 180, 180, 84));
        gradient6.setColorAt(1, QColor(255, 255, 255, 0));
        QBrush brush6(gradient6);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        QRadialGradient gradient7(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(255, 255, 255, 255));
        gradient7.setColorAt(0.1, QColor(255, 255, 255, 255));
        gradient7.setColorAt(0.2, QColor(255, 176, 176, 167));
        gradient7.setColorAt(0.3, QColor(255, 151, 151, 92));
        gradient7.setColorAt(0.4, QColor(255, 125, 125, 51));
        gradient7.setColorAt(0.5, QColor(255, 76, 76, 205));
        gradient7.setColorAt(0.52, QColor(255, 76, 76, 205));
        gradient7.setColorAt(0.6, QColor(255, 180, 180, 84));
        gradient7.setColorAt(1, QColor(255, 255, 255, 0));
        QBrush brush7(gradient7);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        QRadialGradient gradient8(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(255, 255, 255, 255));
        gradient8.setColorAt(0.1, QColor(255, 255, 255, 255));
        gradient8.setColorAt(0.2, QColor(255, 176, 176, 167));
        gradient8.setColorAt(0.3, QColor(255, 151, 151, 92));
        gradient8.setColorAt(0.4, QColor(255, 125, 125, 51));
        gradient8.setColorAt(0.5, QColor(255, 76, 76, 205));
        gradient8.setColorAt(0.52, QColor(255, 76, 76, 205));
        gradient8.setColorAt(0.6, QColor(255, 180, 180, 84));
        gradient8.setColorAt(1, QColor(255, 255, 255, 0));
        QBrush brush8(gradient8);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        dialScrapeInterval->setPalette(palette);
        dialScrapeInterval->setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 255, 255, 255), stop:0.1 rgba(255, 255, 255, 255), stop:0.2 rgba(255, 176, 176, 167), stop:0.3 rgba(255, 151, 151, 92), stop:0.4 rgba(255, 125, 125, 51), stop:0.5 rgba(255, 76, 76, 205), stop:0.52 rgba(255, 76, 76, 205), stop:0.6 rgba(255, 180, 180, 84), stop:1 rgba(255, 255, 255, 0));"));
        dialScrapeInterval->setMinimum(1);
        dialScrapeInterval->setMaximum(300);
        dialScrapeInterval->setWrapping(false);
        dialScrapeInterval->setNotchTarget(25);
        dialScrapeInterval->setNotchesVisible(true);

        horizontalLayout_7->addWidget(dialScrapeInterval);


        verticalLayout_13->addLayout(horizontalLayout_7);

        verticalLayout_13->setStretch(0, 100);
        verticalLayout_13->setStretch(1, 100);

        verticalLayout_14->addLayout(verticalLayout_13);


        horizontalLayout_5->addLayout(verticalLayout_14);


        verticalLayout_15->addLayout(horizontalLayout_5);

        toolBox_2->addItem(page_5, QString::fromUtf8("Scrape Delay"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 622, 299));
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setContentsMargins(10, 10, 10, 10);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setContentsMargins(10, 10, 10, 10);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        edtDeleteFileMatch = new QLineEdit(page);
        edtDeleteFileMatch->setObjectName(QString::fromUtf8("edtDeleteFileMatch"));

        horizontalLayout_8->addWidget(edtDeleteFileMatch);

        btnAddDelFileFilter = new QPushButton(page);
        btnAddDelFileFilter->setObjectName(QString::fromUtf8("btnAddDelFileFilter"));

        horizontalLayout_8->addWidget(btnAddDelFileFilter);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);


        verticalLayout_8->addLayout(horizontalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setContentsMargins(10, 10, 10, 10);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        lstDeleteFileTypes = new QListView(page);
        lstDeleteFileTypes->setObjectName(QString::fromUtf8("lstDeleteFileTypes"));
        lstDeleteFileTypes->setAlternatingRowColors(true);
        lstDeleteFileTypes->setSelectionMode(QAbstractItemView::ExtendedSelection);
        lstDeleteFileTypes->setSelectionRectVisible(true);

        verticalLayout_9->addWidget(lstDeleteFileTypes);

        buttonBox_4 = new QDialogButtonBox(page);
        buttonBox_4->setObjectName(QString::fromUtf8("buttonBox_4"));
        buttonBox_4->setOrientation(Qt::Horizontal);
        buttonBox_4->setStandardButtons(QDialogButtonBox::Discard|QDialogButtonBox::Reset|QDialogButtonBox::RestoreDefaults);
        buttonBox_4->setCenterButtons(false);

        verticalLayout_9->addWidget(buttonBox_4);


        verticalLayout_8->addLayout(verticalLayout_9);


        horizontalLayout_6->addLayout(verticalLayout_8);


        verticalLayout_3->addLayout(horizontalLayout_6);

        toolBox_2->addItem(page, QString::fromUtf8("Reclaim Space"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 622, 299));
        verticalLayout_12 = new QVBoxLayout(page_2);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setContentsMargins(10, 10, 10, 10);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setContentsMargins(10, 10, 10, 10);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        edtChop = new QLineEdit(page_2);
        edtChop->setObjectName(QString::fromUtf8("edtChop"));

        horizontalLayout_14->addWidget(edtChop);

        btnAddDelFileFilter_2 = new QPushButton(page_2);
        btnAddDelFileFilter_2->setObjectName(QString::fromUtf8("btnAddDelFileFilter_2"));

        horizontalLayout_14->addWidget(btnAddDelFileFilter_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_5);


        verticalLayout_10->addLayout(horizontalLayout_14);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setContentsMargins(10, 10, 10, 10);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        lstChoppers = new QListView(page_2);
        lstChoppers->setObjectName(QString::fromUtf8("lstChoppers"));
        lstChoppers->setAlternatingRowColors(true);
        lstChoppers->setSelectionMode(QAbstractItemView::ExtendedSelection);
        lstChoppers->setSelectionRectVisible(true);

        verticalLayout_11->addWidget(lstChoppers);

        buttonBox_5 = new QDialogButtonBox(page_2);
        buttonBox_5->setObjectName(QString::fromUtf8("buttonBox_5"));
        buttonBox_5->setOrientation(Qt::Horizontal);
        buttonBox_5->setStandardButtons(QDialogButtonBox::Discard|QDialogButtonBox::Reset|QDialogButtonBox::RestoreDefaults);
        buttonBox_5->setCenterButtons(false);

        verticalLayout_11->addWidget(buttonBox_5);


        verticalLayout_10->addLayout(verticalLayout_11);


        horizontalLayout_13->addLayout(verticalLayout_10);


        verticalLayout_12->addLayout(horizontalLayout_13);

        toolBox_2->addItem(page_2, QString::fromUtf8("Chopper"));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        page_4->setGeometry(QRect(0, 0, 622, 299));
        horizontalLayout_10 = new QHBoxLayout(page_4);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setContentsMargins(10, 10, 10, 10);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setContentsMargins(10, 10, 10, 10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        edtRegExp = new QLineEdit(page_4);
        edtRegExp->setObjectName(QString::fromUtf8("edtRegExp"));

        horizontalLayout->addWidget(edtRegExp);

        pushButton = new QPushButton(page_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_6->addLayout(horizontalLayout);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setContentsMargins(10, 10, 10, 10);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        lstRegExp = new QListView(page_4);
        lstRegExp->setObjectName(QString::fromUtf8("lstRegExp"));
        lstRegExp->setAlternatingRowColors(true);
        lstRegExp->setSelectionMode(QAbstractItemView::ExtendedSelection);
        lstRegExp->setSelectionRectVisible(true);

        verticalLayout_7->addWidget(lstRegExp);

        buttonBox_3 = new QDialogButtonBox(page_4);
        buttonBox_3->setObjectName(QString::fromUtf8("buttonBox_3"));
        buttonBox_3->setOrientation(Qt::Horizontal);
        buttonBox_3->setStandardButtons(QDialogButtonBox::Discard|QDialogButtonBox::Reset|QDialogButtonBox::RestoreDefaults);
        buttonBox_3->setCenterButtons(false);

        verticalLayout_7->addWidget(buttonBox_3);


        verticalLayout_6->addLayout(verticalLayout_7);


        horizontalLayout_3->addLayout(verticalLayout_6);


        horizontalLayout_10->addLayout(horizontalLayout_3);

        toolBox_2->addItem(page_4, QString::fromUtf8("File Matching Expressions"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 622, 263));
        horizontalLayout_9 = new QHBoxLayout(page_3);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setContentsMargins(10, 10, 10, 10);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, -1, 0);
        edtSeriesFolder = new QLineEdit(page_3);
        edtSeriesFolder->setObjectName(QString::fromUtf8("edtSeriesFolder"));

        horizontalLayout_4->addWidget(edtSeriesFolder);

        btnSelFolder = new QPushButton(page_3);
        btnSelFolder->setObjectName(QString::fromUtf8("btnSelFolder"));
        btnSelFolder->setFlat(false);

        horizontalLayout_4->addWidget(btnSelFolder);

        horizontalSpacer = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        btnAddFolder = new QPushButton(page_3);
        btnAddFolder->setObjectName(QString::fromUtf8("btnAddFolder"));

        horizontalLayout_4->addWidget(btnAddFolder);

        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout_5->addLayout(horizontalLayout_4);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setContentsMargins(10, 10, 10, 10);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        lstFoldersToScan = new QListView(page_3);
        lstFoldersToScan->setObjectName(QString::fromUtf8("lstFoldersToScan"));
        lstFoldersToScan->setAlternatingRowColors(true);
        lstFoldersToScan->setSelectionMode(QAbstractItemView::ExtendedSelection);
        lstFoldersToScan->setSelectionRectVisible(true);

        verticalLayout_4->addWidget(lstFoldersToScan);

        buttonBox_2 = new QDialogButtonBox(page_3);
        buttonBox_2->setObjectName(QString::fromUtf8("buttonBox_2"));
        buttonBox_2->setOrientation(Qt::Horizontal);
        buttonBox_2->setStandardButtons(QDialogButtonBox::Discard|QDialogButtonBox::Reset);
        buttonBox_2->setCenterButtons(true);

        verticalLayout_4->addWidget(buttonBox_2);


        verticalLayout_5->addLayout(verticalLayout_4);


        horizontalLayout_9->addLayout(verticalLayout_5);

        toolBox_2->addItem(page_3, QString::fromUtf8("Scan Folders"));

        formLayout->setWidget(7, QFormLayout::FieldRole, toolBox_2);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(ImDbSettings);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 0, 0, 255), stop:1 rgba(0, 0, 0,255));\n"
"     border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: beige;\n"
"     font: bold 14px;\n"
"     min-width: 5em;\n"
"     padding: 3px;\n"
" }\n"
" QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 0), stop:0.52 rgba(0, 0, 0, 0), stop:0.565 rgba(82, 121, 76, 33), stop:0.65 rgba(159, 235, 148, 64), stop:0.721925 rgba(255, 238, 150, 129), stop:0.77 rgba(255, 128, 128, 204), stop:0.89 rgba(191, 128, 255, 64), stop:1 rgba(0, 0, 0, 0));\n"
"     border-style: inset;\n"
" }\n"
""));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ImDbSettings);
        QObject::connect(buttonBox, SIGNAL(accepted()), ImDbSettings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ImDbSettings, SLOT(reject()));

        toolBox_2->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(ImDbSettings);
    } // setupUi

    void retranslateUi(QDialog *ImDbSettings)
    {
        ImDbSettings->setWindowTitle(QApplication::translate("ImDbSettings", "Preferences", 0));
        label->setText(QApplication::translate("ImDbSettings", "IMDB Url", 0));
        edtDemonoidUrl->setText(QApplication::translate("ImDbSettings", "http://www.imdb.com/", 0));
        sortedFolderLabel->setText(QApplication::translate("ImDbSettings", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Sorted Folder (Target)</span></p></body></html>", 0));
        pushButton_2->setText(QApplication::translate("ImDbSettings", "Browse", 0));
        sortByReleaseYearFirstLabel->setText(QApplication::translate("ImDbSettings", "Sorting", 0));
        sortByReleaseYearFirstCheckBox->setText(QApplication::translate("ImDbSettings", "Folders are sorted first by the release date then categories", 0));
        dropApostrophesLabel->setText(QApplication::translate("ImDbSettings", "Apostrophes", 0));
        DropApostrophe->setText(QApplication::translate("ImDbSettings", "Drop Apostrophes from movies name when searching IMDB", 0));
        label_2->setText(QApplication::translate("ImDbSettings", "Compatibility", 0));
        chkm4vTompg->setText(QApplication::translate("ImDbSettings", "Rename m4v (Apple) to mp4 (Windows)", 0));
        thumbnailSizeLabel->setText(QApplication::translate("ImDbSettings", "Thumbnail Size", 0));
        label_3->setText(QApplication::translate("ImDbSettings", "Delay Interval", 0));
        label_4->setText(QApplication::translate("ImDbSettings", "Files", 0));
        label_6->setText(QApplication::translate("ImDbSettings", "Next Action", 0));
        lblScrapeInterval->setText(QApplication::translate("ImDbSettings", "0 Seconds", 0));
        toolBox_2->setItemText(toolBox_2->indexOf(page_5), QApplication::translate("ImDbSettings", "Scrape Delay", 0));
        btnAddDelFileFilter->setText(QApplication::translate("ImDbSettings", "Add", 0));
        toolBox_2->setItemText(toolBox_2->indexOf(page), QApplication::translate("ImDbSettings", "Reclaim Space", 0));
        btnAddDelFileFilter_2->setText(QApplication::translate("ImDbSettings", "Add", 0));
        toolBox_2->setItemText(toolBox_2->indexOf(page_2), QApplication::translate("ImDbSettings", "Chopper", 0));
        pushButton->setText(QApplication::translate("ImDbSettings", "Add", 0));
        toolBox_2->setItemText(toolBox_2->indexOf(page_4), QApplication::translate("ImDbSettings", "File Matching Expressions", 0));
        btnSelFolder->setText(QApplication::translate("ImDbSettings", "Browse", 0));
        btnSelFolder->setShortcut(QApplication::translate("ImDbSettings", "Ctrl+B", 0));
        btnAddFolder->setText(QApplication::translate("ImDbSettings", "Add", 0));
        toolBox_2->setItemText(toolBox_2->indexOf(page_3), QApplication::translate("ImDbSettings", "Scan Folders", 0));
    } // retranslateUi

};

namespace Ui {
    class ImDbSettings: public Ui_ImDbSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMDBSETTINGS_H
