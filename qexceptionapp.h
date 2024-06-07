#ifndef QEXCEPTIONAPP_H
#define QEXCEPTIONAPP_H

#include <QApplication>
#include <QObject>
#include "mainwindow.h"

class QExceptionApp : public QApplication
{
    Q_OBJECT
public:
    explicit QExceptionApp(int &argc, char **argv);
    bool notify(QObject *, QEvent *);
    MainWindow * IMDBMainWindow();
signals:

public slots:

};

#endif // QEXCEPTIONAPP_H
