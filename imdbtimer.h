#ifndef QDEMONTIMER_H
#define QDEMONTIMER_H

#include <QTimer>
#include <QTime>

class QImdbTimer : public QTimer
{
    Q_OBJECT
public:
    explicit QImdbTimer(int feedbackInterval = 1000, QObject *parent = 0);
    ~QImdbTimer();
     void startWatch(int msec, QObject *receiver, const char *member);
     void execute();
    void stopWatch();
    int timeRemaing();
    QString remaining();
    //QString timeRemaing();

signals:
    void DoFeeBack();

public slots:

private slots:
    void timer_timeout();

private:
     QTimer *m_feedbackInterval;
     QTimer *m_futureEvent;
     QTime *m_elapsedTimer;
     int m_interval;
};



#endif // QDEMONTIMER_H
