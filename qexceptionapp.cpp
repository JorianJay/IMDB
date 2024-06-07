#include "qexceptionapp.h"

#include <exception>
#include <QMessageBox>
#include <QWidget>
#include <QMainWindow>
#include <QStatusBar>
#include <QDebug>

QExceptionApp::QExceptionApp(int &argc, char **argv):
    QApplication(argc,argv)
{
}

// throw std::runtime_error("myFile.cpp:255"); to generate an exception without  a new Qt class
bool QExceptionApp::notify(QObject *rec, QEvent *ev)
{
    try
    {
        return QApplication::notify(rec,ev);
    }
    catch(const std::exception &ex)
    {
        MainWindow *top = IMDBMainWindow();
        if (top )
        {
            top->statusBar()->showMessage(QString("error : %1").arg(ex.what()));
        }
        else
        {
            QMessageBox::warning(0,
                                 tr("An unexpected error occurred"),
                                 tr(ex.what()));
        }
    }
    return false;
}

MainWindow * QExceptionApp::IMDBMainWindow(){    
    MainWindow *mainform = 0;
    foreach (QWidget *widget, QApplication::topLevelWidgets()) {
        if (widget->inherits("MainWindow")){
            MainWindow *mainform = ((MainWindow*)widget);
            return mainform;
        }
    }
    return mainform;
}
