#ifndef GALLERYPAGES_H
#define GALLERYPAGES_H

#include <QTabWidget>
#include <QList>
#include <gallerytab.h>
#include <QStringList>

class GalleryPages : public QTabWidget
{
    Q_OBJECT
public:
    explicit GalleryPages(QWidget *parent = 0);
    ~GalleryPages();

    void DropTab(int index);

    int addGallery(const QString &galleryName, const QString &fileMatchMask , const int &thumbnailSize, const QString &dir);
    int addGallery(const QString &galleryName, const QString &fileMatchMask , const int &thumbnailSize, const QStringList &folders);


    static bool hasImages(const QString &dir);



signals:

    void TabImageSelected(QWidget *sender, const QString &link);

public slots:    

    void clearGalleries();
    void renderTab(int index);
    void OnImageSelected(QWidget *sender, const QString &link);


protected:        
    void tabInserted(int index);
    void tabRemoved(int index);
    void checkVisibility();

private:

 QList<GalleryTab*> *m_tabs;


};

#endif // GALLERYPAGES_H
