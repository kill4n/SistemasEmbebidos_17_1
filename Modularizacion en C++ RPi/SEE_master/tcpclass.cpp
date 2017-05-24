#include "tcpclass.h"
/* Developed and mantained by killan*/

/* Constructor
 * parametros de entrada:
 *  seg     -> Cada cuanto se repite el proceso en segundos
 *  *myLog  -> Apuntador al Objeto que escribe el Log
 */
TCPClass::TCPClass(unsigned long seg, LogClass *myLog)
{
    this->setObjectName("TCP");
    interval = seg;
    mLog = myLog;
    mLog->writeLog(this, "Creacion modulo " + this->objectName());
}
//Destructor
TCPClass::~TCPClass()
{
    mLog->writeLog(this, "Fin modulo " + this->objectName());
}
//Funcion que se ejecuta al iniciar el hilo
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
//Funcion para detener el proceso
void TCPClass::stop()
{
    this->mStop = true;
}
