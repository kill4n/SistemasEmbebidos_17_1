#include "serialclass.h"
/* Developed and mantained by killan*/

/* Constructor
 * parametros de entrada:
 *  seg     -> Cada cuanto se repite el proceso en segundos
 *  *myLog  -> Apuntador al Objeto que escribe el Log
 */
SerialClass::SerialClass(unsigned long seg, LogClass *myLog)
{
    this->setObjectName("Serial");
    interval = seg;
    mLog = myLog;
    mLog->writeLog(this, "Creacion modulo " + this->objectName());
}
//Destructor
SerialClass::~SerialClass()
{
    mLog->writeLog(this, "Fin modulo " + this->objectName());
}
//Funcion que se ejecuta al iniciar el hilo
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
//Funcion para detener el proceso
void SerialClass::stop()
{
    this->mStop = true;
}
