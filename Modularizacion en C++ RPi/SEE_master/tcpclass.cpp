#include "tcpclass.h"

TCPClass::TCPClass(unsigned long seg, LogClass *myLog)
{
    this->setObjectName("TCP");
    interval = seg;
    mLog = myLog;
    mLog->writeLog(this, "Creacion modulo " + this->objectName());
}

TCPClass::~TCPClass()
{
    mLog->writeLog(this, "Fin modulo " + this->objectName());
}

void TCPClass::run()
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
        //put your code here
    }
    mLog->writeLog(this, "Fin modulo " + this->objectName());
}

void TCPClass::stop()
{
    this->mStop = true;
}
