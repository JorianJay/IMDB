#include "imagelabel.h"
#include <QWidget>
#include <QObject>
#include <QLabel>
#include <QDir>
#include <QUrl>
#include <QFileInfo>
#include <QDesktopServices>
#include <QMenu>
#include <QMouseEvent>
#include <QAction>
#include <QTimer>


ImageLabel::ImageLabel(const QString &imgFile, const QSize &thumbSize, const QSize &fullSize, QWidget *parent) :
    QLabel(parent),m_file(imgFile),m_thumbSize(thumbSize),m_fullSize(fullSize)
{
    m_ZoomEvent = new QTimer();
    QObject::connect(m_ZoomEvent,SIGNAL(timeout()),this,SLOT(zoomOver()));
    setFixedSize(m_thumbSize);
    setToolTip(QString("%1").arg(imgFile));
    setStatusTip(imgFile);
    setText(imgFile);
    setMouseTracking(true);
    setTextInteractionFlags(Qt::LinksAccessibleByMouse);

}

ImageLabel::~ImageLabel(){
    delete m_ZoomEvent;
}

void ImageLabel::mouseMoveEvent(QMouseEvent *ev)
{
    m_ZoomEvent->setInterval(1250);
    m_ZoomEvent->setSingleShot(true);
    m_ZoomEvent->start();
    QLabel::mouseMoveEvent(ev);
    //imdb pic 214px × 317px
}

void ImageLabel::zoomOver(){
    setFixedSize(m_fullSize);
    QString imageFileName = this->statusTip();
    QImage image(imageFileName);
    QImage scaled (image.scaled(m_fullSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    setPixmap(QPixmap::fromImage(scaled));
}

void ImageLabel::leaveEvent(QEvent *event)
{
    m_ZoomEvent->stop();
    setFixedSize(m_thumbSize);
    QString imageFileName = this->statusTip();
    QImage image(imageFileName);
    QImage scaled (image.scaled(m_thumbSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    setPixmap(QPixmap::fromImage(scaled));
    QLabel::leaveEvent(event);
}

void ImageLabel::mouseDoubleClickEvent(QMouseEvent *event){

 OpenFileLocation();
 QLabel::mouseDoubleClickEvent(event);

}

void ImageLabel::mousePressEvent(QMouseEvent *event)
{

    if (event->button() == Qt::RightButton){
        QMenu menu(this);
        QAction openfolder(this);
        openfolder.setText("Open Location");
        QObject::connect(&openfolder,SIGNAL(triggered()),this,SLOT(OpenFileLocation()));
        menu.addAction(&openfolder);

        QAction IMDBReviews(this);
        IMDBReviews.setText("IMDB Review");
        QObject::connect(&IMDBReviews,SIGNAL(triggered()),this,SLOT(IMDBWebPageReviews()));
        menu.addAction(&IMDBReviews);

        menu.popup(mapToGlobal(QPoint(0,0)));
        menu.exec();
    }
    QLabel::mousePressEvent(event);
}

void ImageLabel::OpenFileLocation()
{
    QFileInfo info(m_file);
    QDesktopServices::openUrl(QUrl(info.absolutePath()));

}

void ImageLabel::IMDBWebPageReviews()
{
    QFileInfo info(m_file);
    QString moviename = info.fileName().left(info.fileName().lastIndexOf('.'));
    emit MovieReview(moviename);
}
