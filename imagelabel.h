#ifndef IMAGELABEL_H
#define IMAGELABEL_H

#include <QLabel>
#include <QWidget>
#include <QTimer>

class ImageLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ImageLabel(const QString &imgFile, const QSize &thumbSize, const QSize &fullSize, QWidget *parent = 0);
    ~ImageLabel();

signals:

    void MovieReview(const QString &MovieName);

public slots:
    void zoomOver();
    void IMDBWebPageReviews();
    void OpenFileLocation();

protected:

    void mouseMoveEvent(QMouseEvent *ev);
    void leaveEvent ( QEvent * event );
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
 QString m_file;
 QSize m_thumbSize;
 QSize m_fullSize;
 QTimer *m_ZoomEvent;

};

#endif // IMAGELABEL_H
