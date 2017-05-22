#include "pyrunclass.h"

PyRunClass::PyRunClass(unsigned long seg, LogClass *myLog, QString path):
    _path(path)
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
        //Correr script de python
        std::string command = "python ";
        command += _path.toUtf8().constData();
        system(command.c_str());
    }
    mLog->writeLog(this, "Fin modulo "+ this->objectName());
}

void PyRunClass::stop()
{
    this->mStop = true;
}
