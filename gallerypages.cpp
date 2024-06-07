#include "gallerypages.h"

#include <QObject>
#include <QDebug>
#include <gallerytab.h>
#include <QDir>
#include <QDirIterator>
#include <QStringList>
#include <QTabBar>


GalleryPages::GalleryPages(QWidget *parent) :
    QTabWidget(parent)
{    
    //   QTabBar *bar = this->tabBar();
    //   bar->setVisible(false);
    m_tabs = new QList<GalleryTab*>();
    QObject::connect(this,SIGNAL(currentChanged(int)),this,SLOT(renderTab(int)));
}

GalleryPages::~GalleryPages(){
    QObject::disconnect(this,SIGNAL(currentChanged(int)));
    qDeleteAll(*m_tabs);
    delete m_tabs;
}

void GalleryPages::clearGalleries(){
  //  while (count()-1!= -1)
  //      DropTab(count()-1);
    qDeleteAll(*m_tabs);
    m_tabs->clear();
    clear();
    //for(int i = count()-1;i> -1;--i){
    //    DropTab(i);
   // }
}

void GalleryPages::tabInserted(int index){
    checkVisibility();
    //((QTabWidget *)this)->
    QTabWidget::tabInserted(index);
}

void GalleryPages::tabRemoved(int index){
    checkVisibility();
    //((QTabWidget *)this)->    
    QTabWidget::tabRemoved(index);
}

void GalleryPages::checkVisibility(){
    QTabBar *bar = this->tabBar();
    bar->setVisible(this->count()!= -1);
}

void GalleryPages::DropTab(int index){
    //int m_tabIndex = this->currentIndex();
    if (index > -1 && index < count()) this->removeTab(index);
}

int GalleryPages::addGallery(const QString &galleryName, const QString &fileMatchMask ,const int &thumbnailSize, const QString &dir){

    GalleryTab *_tab = new GalleryTab(dir, fileMatchMask ,thumbnailSize,this);
    m_tabs->append(_tab);
    return this->addTab(_tab,galleryName);
}

int GalleryPages::addGallery(const QString &galleryName, const QString &fileMatchMask ,const int &thumbnailSize, const QStringList &folders){
    GalleryTab *_tab = new GalleryTab(folders,fileMatchMask,thumbnailSize,this);
    QObject::connect(_tab,SIGNAL(ImageSelected(QWidget*,QString)),this,SLOT(OnImageSelected(QWidget*,QString)));
    m_tabs->append(_tab);
    return this->addTab(_tab,galleryName);
}

void GalleryPages::renderTab(int index){
    Q_UNUSED(index);
    if (currentWidget()!= NULL){
        ((GalleryTab*)currentWidget())->renderImages();}
}

bool GalleryPages::hasImages(const QString &dir){
    QStringList files;
    QString fileNameMatch  = "*.jpg";
    QDir adir(dir);
    files = adir.entryList(QStringList(fileNameMatch),
                           QDir::Files | QDir::NoSymLinks );
    return files.count()-1 !=-1;
}

void GalleryPages::OnImageSelected(QWidget *sender, const QString &link){
    emit TabImageSelected(sender,link);
}
