#include "imdbtimer.h"
#include <QTimer>
#include <QTime>

//QTimer QDemonTimer::m_timer = new QTimer();
//QTimer QDemonTimer::m_time = new QTime();

QImdbTimer::QImdbTimer(int feedbackInterval , QObject *parent) :
    QTimer(parent)
{
    m_feedbackInterval = new QTimer();
    m_futureEvent = new QTimer();
    m_elapsedTimer = new QTime();
    QImdbTimer::m_feedbackInterval->setInterval(feedbackInterval);
}

QImdbTimer::~QImdbTimer(){
    delete m_feedbackInterval;
    delete m_futureEvent;
    delete m_elapsedTimer;
}

void QImdbTimer::timer_timeout()
{
    //m_time->();
    //QDemonTimer::m_time->restart();
//m_time->restart();
    emit DoFeeBack();
}

void QImdbTimer::startWatch(int msec, QObject *receiver, const char *member)
{
    stopWatch();
    m_interval = msec;    
    QObject::connect(m_feedbackInterval, SIGNAL(timeout()), this, SLOT(timer_timeout()));

    m_futureEvent->setInterval(m_interval);
    m_futureEvent->setSingleShot(true);
    QObject::connect(m_futureEvent,SIGNAL(timeout()),receiver,member);

    m_feedbackInterval->start();
    m_futureEvent->start();
    m_elapsedTimer->start();

    //cant stop singleshot so created m_event timer and set setSingleShot to true
    //QTimer::singleShot(m_interval,receiver,member);
}

void QImdbTimer::stopWatch()
{
    m_feedbackInterval->stop();
    m_futureEvent->stop();
    m_feedbackInterval->disconnect( SIGNAL(timeout()));
    m_futureEvent->disconnect( SIGNAL(timeout()));
    //QDemonTimer::m_time->stop();
    //QTimer::stop();
}


int QImdbTimer::timeRemaing(){    
    //int used = m_elapsedTimer->elapsed();
    int _lefttime = m_interval-m_elapsedTimer->elapsed();
    return _lefttime;
}

QString QImdbTimer::remaining(){
    QString _togo = "%1:%2:%3:%4";
    int _ms = 0;
    int _sec = 0;
    int _min = 0;
    int _hour = 0;
    _ms = timeRemaing();
    if (_ms > 1000){
        _sec  = _ms / 1000;
        _ms = _ms % 1000;
        if (_sec > 60) {
            _min=_sec / 60;
            _sec= _sec % 60;
            if (_min > 60) {
                _hour = _min / 60;
                _min = _min % 60;
            }
        }
    }
    return _togo.arg(QString::number(_hour),QString::number(_min),QString::number(_sec),QString::number(_ms));
    //                                _togo.arg(_hour,0,'f',0,'0').arg(_min,0,'f',0,'0').arg(_sec,0,'f',0,'0').arg(_ms,0,'f',0,'0');

}

//any pending events will fire within a millisec
void QImdbTimer::execute()
{
    m_futureEvent->setInterval(1);
}

/*QString QDemonTimer::timeRemaing(){
    return QString.number( m_timer->interval()- m_time->elapsed());
}*/

        // QRadioButton *radioButton = qobject_cast<QRadioButton*>(sender());
