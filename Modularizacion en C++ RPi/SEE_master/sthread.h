#ifndef STHREAD_H
#define STHREAD_H

#include <QThread>
#include <QDebug>
#include <QMutex>
#include "logclass.h"


class SThread : public QThread
{
    Q_OBJECT
public:
    //SThread(long msInterval) = 0;
    virtual void run() =  0;
    virtual void stop() = 0;
protected:
    QMutex mutex;
    bool mStop = false;
    LogClass *mLog;
    unsigned long interval;
   //virtual long _msInterval;
};

#endif // STHREAD_H
