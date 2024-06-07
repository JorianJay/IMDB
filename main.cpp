#include <QApplication>
#include "mainwindow.h"
#include "qexceptionapp.h"

int main(int argc, char *argv[])
{
    QExceptionApp a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
