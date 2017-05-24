#ifndef STHREAD_H
#define STHREAD_H
/* Developed and mantained by killan*/
#include <QThread>
#include <QDebug>
#include <QMutex>
#include "logclass.h"

//Interface para crear hilos hereda de QThread
class SThread : public QThread
{
    Q_OBJECT
public:
    //SThread(long msInterval) = 0;
    //Funcion virtual como es la funcion que se ejecuta al iniciar el hilo
    virtual void run() =  0;
    //Funcion virtual como detener el hilo
    virtual void stop() = 0;
protected:
    //Variable para hacer operaciones "Thread safe"
    QMutex mutex;
    //Variable para detener el hilo
    bool mStop = false;
    //Apuntador para almacenar El objeto que gneera los Log
    LogClass *mLog;
    //Intervalo al que se repera el hilo.
    unsigned long interval;
   //virtual long _msInterval;
};

#endif // STHREAD_H
