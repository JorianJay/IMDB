#ifndef GALLERYTAB_H
#define GALLERYTAB_H
#include <QList>
#include <QLabel>

#include <QWidget>
#include <QFutureWatcher>
#include <QImage>
#include <QList>
#include <QLabel>
#include <QStringList>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QScrollArea>
#include <QGroupBox>
#include <QEvent>
#include <QImage>

class GalleryTab : public QWidget
{
    Q_OBJECT
public:
    explicit GalleryTab(const QString &dir,const QString &fileMatchMask , const int &thumbnailSize, QWidget *parent = 0);
    explicit GalleryTab(const QStringList &folders, const QString &fileMatchMask ,const int &thumbnailSize, QWidget *parent = 0);
    ~GalleryTab();

    void cancel();
    void renderImages();

    //QImage scale(const QString &imageFileName);


protected:
    void resizeEvent(QResizeEvent *evt);
    void buildGallery(const QStringList &folders);
    //void buildGallery(const QString &dir);

signals:
        void ImageSelected(QWidget *sender, const QString &link);

public slots:
    void showImage(int num);
    void OnImageSelected(const QString &link);
    //void OnMouseOverImage(const QString& link);

private:
    int m_thumbnailSize;
    QString m_fileMatchMask;
    QStringList m_folders;
    QFutureWatcher<QImage> *m_imageScaling ;
    QList<QLabel*> m_labels;
    QStringList m_files;
    QVBoxLayout *m_layout;
    QGridLayout *m_grid;
    QScrollArea *m_scrollArea;
    QGroupBox *m_groupBox;

    //int m_grid_row;
    //int m_grid_col;


    void init();
    void rollOutImages();
    void addFolder(const QString &dir, int &m_grid_row, int &m_grid_col);
    void loadImages(const QString &dir, int &m_grid_row, int &m_grid_col);

};

#endif // GALLERYTAB_H
