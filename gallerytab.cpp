#include "gallerytab.h"

#include <QObject>
#include <QStringList>
#include <QFutureWatcher>
#include <QList>
#include <QImage>
#include <QLabel>
#include <QDir>
#include <QDirIterator>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPalette>
#include <QScrollArea>
#include <QGroupBox>
#include "imagelabel.h"
#include <QtConcurrent/QtConcurrent>
#include "math.h"


//const int imageSize = 100;

GalleryTab::GalleryTab(const QString &dir, const QString &fileMatchMask ,const int &thumbnailSize, QWidget *parent) :
    QWidget(parent),m_thumbnailSize(thumbnailSize), m_fileMatchMask(fileMatchMask)
{   
    init();
    m_folders << dir;    
    //buildGallery(dir);
}

GalleryTab::GalleryTab(const QStringList &folders, const QString &fileMatchMask , const int &thumbnailSize, QWidget *parent) :
    QWidget(parent),m_thumbnailSize(thumbnailSize), m_fileMatchMask (fileMatchMask)
{
    init();
    m_folders << folders;
    //buildGallery(folders);
}

GalleryTab::~GalleryTab() {
    cancel();
    QObject::disconnect(m_imageScaling, SIGNAL(resultReadyAt(int)));
    delete m_imageScaling ;
    //delete m_grid;
    //delete m_groupBox;
    //delete m_scrollArea;
    //delete m_layout;
}

void GalleryTab::resizeEvent(QResizeEvent *evt){
    renderImages();
    QWidget::resizeEvent(evt);
}

void GalleryTab::renderImages()
{
    if (m_folders.count()-1 != -1)
    {
        buildGallery(m_folders);
        //    m_folders.clear();
    }
}


void GalleryTab::init() {

    m_scrollArea = new QScrollArea(this);

    m_groupBox = new QGroupBox(m_scrollArea);
    m_groupBox->setTitle("Thumbnails");
    m_grid = new QGridLayout(m_groupBox);
    m_groupBox->setLayout(m_grid);


    m_layout = new QVBoxLayout(this);
    m_layout->addWidget(m_scrollArea);
    this->setLayout(m_layout);

    m_scrollArea->setWidget(m_groupBox);
    m_scrollArea->viewport()->setBackgroundRole(QPalette::Dark);
    m_scrollArea->viewport()->setAutoFillBackground(true);
    m_scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    m_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    m_scrollArea->setBackgroundRole(QPalette::Dark);
    m_scrollArea->setWidgetResizable(true);

    m_imageScaling = new QFutureWatcher<QImage>(this);
    QObject::connect(m_imageScaling, SIGNAL(resultReadyAt(int)), SLOT(showImage(int)));
}


void GalleryTab::cancel(){
    if (m_imageScaling->isRunning()) {
        m_imageScaling->cancel();
        m_imageScaling->waitForFinished();
    }
    qDeleteAll(m_labels);
    m_labels.clear();
    m_files.clear();

    //m_grid->setSpacing(imageSize );
    //m_grid->setSizeConstraint(QLayout::SetNoConstraint);

}

void GalleryTab::showImage(int num)
{
    if(m_labels.count()-1 != -1 && num < m_labels.count()){
        m_labels[num]->setPixmap(QPixmap::fromImage(m_imageScaling->resultAt(num)));
    }
}

int img_size = 100;
QImage scale(const QString &imageFileName)
{
    QImage image(imageFileName);
    return image.scaled(QSize(img_size, img_size), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}

void GalleryTab::rollOutImages(){
    if (m_files.count()-1 != -1){
        img_size = m_thumbnailSize;
        m_imageScaling->setFuture(QtConcurrent::mapped(m_files, scale));
    }
}
/*
void GalleryTab::buildGallery(const QString &dir){
    cancel();
    int m_grid_row =0;
    int m_grid_col=0;
    addFolder(dir,m_grid_row,m_grid_col);
    rollOutImages();
}
*/
void GalleryTab::buildGallery(const QStringList &folders){
    cancel();
    int m_grid_row =0;
    int m_grid_col=0;
    foreach(QString dir,folders){
        addFolder(dir,m_grid_row,m_grid_col);
    }
    rollOutImages();
}

void GalleryTab::addFolder(const QString &dir, int &m_grid_row, int &m_grid_col){
    QDir d(dir) ;
    if (d.exists()){
        loadImages(QString("%1").arg(dir),m_grid_row,m_grid_col);
        QDirIterator it(d, QDirIterator::Subdirectories);
        while (it.hasNext()) {
            QString sfolder = it.next();
            QDir p(sfolder);
            if (it.fileInfo().isDir() && (p.cdUp() && p!=d) ){
                if (!it.fileInfo().fileName().startsWith('.',Qt::CaseInsensitive) && !it.fileInfo().fileName().endsWith('/',Qt::CaseInsensitive)  )
                {
                    loadImages(QString("%1").arg(sfolder),m_grid_row,m_grid_col);
                }
            }
        }
    }
}

void GalleryTab::loadImages(const QString &dir, int &m_grid_row , int &m_grid_col){

    QStringList files;
    QDir adir(dir);
    QSize sz_thumb(m_thumbnailSize,m_thumbnailSize);
    QSize sz_full(m_thumbnailSize<<1,m_thumbnailSize<<1);//imdb pic 214px × 317px
    if (sz_full.width() < 214 ){sz_full.setWidth(214);}
    if (sz_full.height() < 317 ){sz_full.setHeight(317);}
    QString fileNameMatch  = QString("%1.jpg").arg((m_fileMatchMask.isNull() || m_fileMatchMask.isEmpty())?"*":m_fileMatchMask.endsWith('*')?m_fileMatchMask:QString("%1*").arg(m_fileMatchMask));
    files = adir.entryList(QStringList(fileNameMatch),
                           QDir::Files | QDir::NoSymLinks );

    if (!files.isEmpty()){
        files.sort();
        int imagesperline = ((this->width()-214)/m_thumbnailSize)-1;
        if (imagesperline<2) imagesperline = 2;
        //int x = m_grid_col;
        //int y = m_grid_row ;
        for (int i=0;i<files.count();++i){
            QString fname = QString("%1/%2").arg(dir).arg(files.at(i));
            if (!m_files.contains(fname,Qt::CaseInsensitive)){
                ImageLabel *imagelink = new ImageLabel(fname, sz_thumb,sz_full, this);
                m_grid->addWidget(imagelink,m_grid_row,m_grid_col);
                m_grid_col++;
                if (m_grid_col == imagesperline){
                    m_grid_col = 0;
                    m_grid_row++;
                }

                QObject::connect(imagelink,SIGNAL(MovieReview(QString)),this,SLOT(OnImageSelected(QString)));
                m_labels.append(imagelink);
                m_files.append(fname);
            }}


        /* int dim = sqrt(qreal(files.count())) + 1;
        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                QLabel *imageLabel = new QLabel;
                imageLabel->setFixedSize(imageSize,imageSize);
                //m_grid->setRowMinimumHeight(m_grid_row+i,imageSize);
                //m_grid->setColumnMinimumWidth(m_grid_col+j,imageSize );
                m_grid->addWidget(imageLabel,m_grid_row,m_grid_col);
                m_grid_col++;



                //imageLabel->setText(QString("%1/%2").arg(m_grid_row+i).arg(m_grid_col+j));
                m_labels.append(imageLabel);
            }

        }*/


        //m_grid_row += dim;
        //m_grid_col += dim;
        // foreach(QString file, files){
        //     m_files.append(dir + "/" + file);
        // }
    }
}

void GalleryTab::OnImageSelected(const QString &link){
 emit ImageSelected(this,link);
}

/*
void GalleryTab::OnMouseOverImage(const QString &link)
{
    qDebug()<<link;
}
*/

