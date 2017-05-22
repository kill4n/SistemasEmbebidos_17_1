#include "pyrunclass.h"

PyRunClass::PyRunClass(unsigned long seg, LogClass *myLog)
{
    this->setObjectName("PyRunner");
    interval = seg;
    mLog = myLog;
    mLog->writeLog(this, "Creacion modulo " + this->objectName());
}

PyRunClass::~PyRunClass()
{
    mLog->writeLog(this, "Fin modulo " + this->objectName());
}

void PyRunClass::run()
{
    mLog->writeLog(this, "Inicio modulo "+ this->objectName());
    this->mStop = false;

    for (int i = 0; i < 10; ++i) {
        mLog->writeLog(this, this->objectName() +
                       " is Alive: " + QString::number(i));
        this->mutex.lock();
        if(this->mStop == true)
        {
            this->mutex.unlock();
            break;
        }
        this->mutex.unlock();
        sleep(interval);
    }
    mLog->writeLog(this, "Fin modulo "+ this->objectName());
}

void PyRunClass::stop()
{
    this->mStop = true;
}
