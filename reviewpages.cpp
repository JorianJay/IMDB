#include "reviewpages.h"

#include <QObject>
#include <QDebug>
#include <reviewtab.h>
#include <QDir>
#include <QDirIterator>
#include <QStringList>
#include <QTabBar>
#include <QDebug>

ReviewPages::ReviewPages(QWidget *parent) :
    QTabWidget(parent)
{
    m_tabs = new QList<ReviewTab*>();
    setMovable(true);
    setTabsClosable(true);
    QObject::connect(this,SIGNAL(tabCloseRequested(int)),this,SLOT(dropTab(int)));
}

ReviewPages::~ReviewPages(){
    qDeleteAll(*m_tabs);
     delete m_tabs;
}

void ReviewPages::clearGalleries(){
  //  while (count()-1!= -1)
  //      DropTab(count()-1);
    qDeleteAll(*m_tabs);
    m_tabs->clear();
    clear();
    //for(int i = count()-1;i> -1;--i){
    //    DropTab(i);
   // }
}

void ReviewPages::tabInserted(int index){
    checkVisibility();
    //((QTabWidget *)this)->
    QTabWidget::tabInserted(index);
}

void ReviewPages::tabRemoved(int index){
    checkVisibility();
    //((QTabWidget *)this)->
    QTabWidget::tabRemoved(index);
}

void ReviewPages::checkVisibility(){
    QTabBar *bar = this->tabBar();
    bar->setVisible(this->count()!= -1);
}

void ReviewPages::dropTab(int index){
    //int m_tabIndex = this->currentIndex();
    if (index > -1 && index < count()) {
        int idx= m_tabs->indexOf((ReviewTab*)this->widget(index));
        if (idx!= -1){
        delete m_tabs->takeAt(idx);}
       // this->removeTab(index);

    }
}

int ReviewPages::addReview(const QString &movieName){
    ReviewTab *_tab = new ReviewTab(movieName,this);
    m_tabs->append(_tab);
    int idx = this->addTab(_tab,movieName);
    setCurrentIndex(idx);
    return  idx;
}

