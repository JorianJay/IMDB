#include "reviewtab.h"

#include <QWebView>
#include <QSettings>
#include <QUrl>
#include <QWebElement>
#include <QVBoxLayout>
#include <QCoreApplication>
#include <QWebFrame>
#include <QWebSettings>

ReviewTab::ReviewTab(const QString &movieName, QWidget *parent) :
    QWidget(parent), m_movie(movieName)
{ 
    m_layout = new QVBoxLayout(this);
    m_browser = new QWebView(this);
    m_layout->addWidget(m_browser);
    this->setLayout(m_layout);


#if defined(DEBUG)
    m_browser->page()->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled,true);
#endif

    m_browser->page()->settings()->setAttribute(QWebSettings::PluginsEnabled, false);
    m_browser->page()->settings()->setAttribute(QWebSettings::JavascriptEnabled, false);
    m_browser->page()->settings()->setAttribute(QWebSettings::AutoLoadImages, false);


    QObject::connect(m_browser, SIGNAL(loadFinished(bool)), this, SLOT(WebBrowserLoaded(bool)));
    QUrl imbUrl(ini("imdbUrl","http://www.imdb.com").toString());
    m_browser->setUrl(imbUrl);

}

ReviewTab::~ReviewTab(){
    delete m_browser;
    delete m_layout;
}

QVariant ReviewTab::ini(const QString &key, const QVariant &defaultValue) const
{
    QCoreApplication::setOrganizationName("HardcoreSoftware");
    QCoreApplication::setApplicationName("imdb");
    QSettings settings("catalog",QSettings::IniFormat);
    return settings.value(key, defaultValue);
}

QWebElement ReviewTab::document(QWebView *view) const {
    return  document(view->page()->currentFrame());
}

QWebElement ReviewTab::document(QWebFrame *frame) const {
    return  frame->documentElement();
}

void ReviewTab::WebBrowserLoaded(bool ok){
    Q_UNUSED(ok);
    m_browser->disconnect(SIGNAL(loadFinished(bool)));

    QWebElement edtnavbarquery =document(m_browser).findFirst("#navbar-query");
    if (!edtnavbarquery.isNull()){
        inputValue(edtnavbarquery,m_movie);
        connect(m_browser, SIGNAL(loadFinished(bool)), this, SLOT(searchcompleted(bool)));

        QWebElement btnnavbarsubmitbutton =document(m_browser).findFirst("#navbar-submit-button");
        clickBtn(btnnavbarsubmitbutton);
    } else { // if not input to search go back to main page and try from there
        QObject::connect(m_browser, SIGNAL(loadFinished(bool)), this, SLOT(WebBrowserLoaded(bool)));
        QUrl imbUrl(ini("imdbUrl","http://www.imdb.com").toString());
        m_browser->setUrl(imbUrl);
    }

}

void ReviewTab::searchcompleted(bool ok){
    Q_UNUSED(ok);
    m_browser->disconnect(SIGNAL(loadFinished(bool)));
}

void ReviewTab::inputValue(QWebElement &input, const QString &value){
    //QString setvalue = QString("this.value='%1'").arg(value);
    QString testvalue = QString("this.value");
    QString jsvalue("");

    while (jsvalue.compare(value,Qt::CaseInsensitive) != 0){
        //input.evaluateJavaScript(setvalue);
        input.setAttribute("value", value);
        jsvalue=input.evaluateJavaScript(testvalue).toString();
    }
    focusElement(input);
}


void ReviewTab::clickBtn(QWebElement &btn){
    focusElement(btn);
    QString click = QString("this.click()");
    btn.evaluateJavaScript(click);
}


void ReviewTab::focusElement(QWebElement &ele){
    ele.setFocus();
    QString focusthis("this.setFocus();");
    ele.evaluateJavaScript(focusthis);
}

