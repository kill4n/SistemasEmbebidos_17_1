#include "statusclass.h"

StatusClass::StatusClass(unsigned long seg, LogClass *myLog)
{
    this->setObjectName("Status");
    interval = seg;
    mLog = myLog;
    mLog->writeLog(this, "Creacion modulo " + this->objectName());
}

StatusClass::~StatusClass()
{
    mLog->writeLog(this, "Fin modulo " + this->objectName());
}

void StatusClass::run()
{
    mLog->writeLog(this, "Inicio modulo " + this->objectName());
    this->mStop = false;

    for (int i = 0; i < 10; ++i) {
        this->mutex.lock();
        mLog->writeLog(this, this->objectName() +
                       " is Alive: " + QString::number(i));
        if(this->mStop == true)
        {
            this->mutex.unlock();
            break;
        }
        this->mutex.unlock();
        sleep(interval);
    }
    this->mutex.lock();
    mLog->writeLog(this, "Fin modulo " + this->objectName());
    this->mutex.unlock();
}

void StatusClass::stop()
{
    this->mStop = true;
}
