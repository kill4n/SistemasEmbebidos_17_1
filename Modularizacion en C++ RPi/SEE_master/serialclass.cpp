#include "serialclass.h"

SerialClass::SerialClass(unsigned long seg, LogClass *myLog)
{
    this->setObjectName("Serial");
    interval = seg;
    mLog = myLog;
    mLog->writeLog(this, "Creacion modulo " + this->objectName());
}

SerialClass::~SerialClass()
{
    mLog->writeLog(this, "Fin modulo " + this->objectName());
}

void SerialClass::run()
{
    mLog->writeLog(this, "Inicio modulo " + this->objectName());
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
    mLog->writeLog(this, "Fin modulo " + this->objectName());
}

void SerialClass::stop()
{
    this->mStop = true;
}
