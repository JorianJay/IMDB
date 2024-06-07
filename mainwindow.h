#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QActionGroup>
#include "imdbsettings.h"
#include "imdb.h"
#include <QLineEdit>


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void showPreferences();
private:
    QLineEdit *m_filefilter;
    Ui::MainWindow *ui;
    imdb *m_imdb;
    QActionGroup *m_statusGroup;
    QAction *actLayout_filter;
    void centerInDesktop();

};

#endif // MAINWINDOW_H
