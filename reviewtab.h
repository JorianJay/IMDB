#ifndef REVIEWTAB_H
#define REVIEWTAB_H

#include <QWidget>
#include <QWebView>
#include <QVBoxLayout>
#include <QVariant>
#include <QWebElement>

class ReviewTab : public QWidget
{
    Q_OBJECT
public:
    explicit ReviewTab(const QString &movieName,QWidget *parent = 0);
    ~ReviewTab();


signals:

public slots:
    void WebBrowserLoaded(bool ok);
    void searchcompleted(bool ok);
private:
 QString m_movie;
 QWebView *m_browser;
 QVBoxLayout *m_layout;
 void inputValue(QWebElement &input, const QString &value);
 void focusElement(QWebElement &ele);
 void clickBtn(QWebElement &btn);
 QVariant ini(const QString &key, const QVariant &defaultValue) const;
 QWebElement document(QWebView *view) const;
 QWebElement document(QWebFrame *frame) const;

};

#endif // REVIEWTAB_H
