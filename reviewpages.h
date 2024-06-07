#ifndef REVIEWPAGES_H
#define REVIEWPAGES_H

#include <QTabWidget>
#include <QList>
#include "reviewtab.h"


class ReviewPages : public QTabWidget
{
    Q_OBJECT
public:
    explicit ReviewPages(QWidget *parent = 0);
    ~ReviewPages();
    void clearGalleries();
    int addReview(const QString &movieName);
public slots:
    void dropTab(int index);
protected:
    void tabInserted(int index);
    void tabRemoved(int index);
    void checkVisibility();

private:
  QList<ReviewTab*> *m_tabs;
};

#endif // REVIEWPAGES_H
