#include "statusclass.h"
/* Developed and mantained by killan*/

/* Constructor
 * parametros de entrada:
 *  seg     -> Cada cuanto se repite el proceso en segundos
 *  *myLog  -> Apuntador al Objeto que escribe el Log
 */
StatusClass::StatusClass(unsigned long seg, LogClass *myLog)
{
    this->setObjectName("Status");
    interval = seg;
    mLog = myLog;
    mLog->writeLog(this, "Creacion modulo " + this->objectName());
}
//Destructor
StatusClass::~StatusClass()
{
    mLog->writeLog(this, "Fin modulo " + this->objectName());
}
//Funcion que se ejecuta al iniciar el hilo
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
//Funcion para detener el proceso
void StatusClass::stop()
{
    this->mStop = true;
}
