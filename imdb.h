#ifndef IMDB_H
#define IMDB_H
#include "ui_imdb.h"
#include "imdbtimer.h"

#include <QVariant>
#include <QWidget>
#include <QMainWindow>
#include <QLCDNumber>
#include <QWebElement>
#include <QNetworkAccessManager>
#include <QStringList>
#include <QGridLayout>
#include <QScrollArea>
#include <QNetworkReply>

namespace Ui {
    class imdb;
}

class imdb : public QWidget, public Ui::imdb
{
    Q_OBJECT

public:
    explicit imdb(QWidget *parent = 0);
    ~imdb();
    static const QString safepathdelimeter;
    //static const QString pathdelimeterlinux;



public slots:
    void dorun();
    //void dorefresh();
    void showStatus();
    void showLogs();
    void doFolderCleanup();
    void doShowRemainingMovies();
    void doStopScan();
    void doPushQue();
    void doRefreshCategoryTabs();
    void OnTabImageSelected(QWidget *sender, const QString &link);
    void CheckMovieHasPicInGallery();
    void doSearchForEditingFinished();
    void doSearchForTextchanged(const QString &text);


signals:
    //void run();
    void reRun();


private slots:
    void HandleStatus(  QString text);
    void busyWorking();
    void imDbLoaded(bool);
    void findMovie();
    void nextMovie();
    void networkReplyReady(QNetworkReply *reply);
    void searchcompleted(bool);

    void on_lstFailedFiles_clicked(const QModelIndex &index);
    void socketError(QNetworkReply::NetworkError code);
    void socketDownloadprogress(qint64 bytesReceived,qint64 bytesTotal);
    void doReRun();

    void on_lstMissingMoviePictures_clicked(const QModelIndex &index);



private:
    //Ui::imdb *ui;
    QMainWindow * mainwin();
    QImdbTimer *m_imdbtimer ;
    //QNetworkReply *m_selreply;
    int m_logid;
    bool m_stopScan;
    int m_currentMovieNo;
    bool m_dropApostrophe;
    QString m_selectedFolder;
    QNetworkAccessManager *m_network;
    QString  m_filefilter;
    // m_movies => fullname - movie/year pair
    QList< QPair<QString, QPair<QString, QString > > > *m_movies;
    QPair<QString, QPair<QString, QString > >  selectedMovie;


    void setElementText(QWebView *view, const QString &eleName, const QString &value);
    QVariant ini(const QString &key, const QVariant &defaultValue) const;
    void setupLCDC(QLCDNumber *lcd, const bool &hasval);
    QWebElement document(QWebView *view) const;
    QWebElement document(QWebFrame *frame) const;
    void loadUnsortedFolder();
    void matchFiles(const QString &sRoot,const QStringList &filematchRegExpressions, const QStringList &choppers);
    void copyMovieToCategory(const QString &info, const QString &movieYear );


    void focusElement(QWebElement &ele);
    void inputValue(QWebElement &input, const QString &value);
    void clickBtn(QWebElement &btn);
    void followLink(QWebElement &link);
    void downloadMovieImage(const QString &folder);
    void resetStatusInfo();

    void cleanjunkFiles(const QString &folder, const QStringList &fileMaskExpressions);
    void tryRemoveFolder(const QString &folder);
    QString &safeMovieDescr(const QString &value) ;
    void sentToClip(QString value);
    void markProcessed();
    void LoadMovieIntoCategory(QGridLayout *layout, QScrollArea *scrollbk, const QString &folder);
    void saveDefaultMoviePic();
    void saveMovieImage(const QImage &image);

    void status_Movie(const QString &value);
    void status_fileName(const QString &value);
    void status_year(const QString &value);
    void status_category(const QString &value);
    void status_location(const QString &value);

    void matchImgToMovie(const QString &dir);

    const QString fileMaskMatch() ;

};

#endif // IMDB_H
