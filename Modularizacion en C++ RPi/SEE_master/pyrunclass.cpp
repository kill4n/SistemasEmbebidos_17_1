#include "pyrunclass.h"
/* Developed and mantained by killan*/

/* Constructor
 * parametros de entrada:
 *  seg     -> Cada cuanto se repite el proceso en segundos
 *  *myLog  -> Apuntador al Objeto que escribe el Log
 *  path    -> Direccion del script de Python
 */
PyRunClass::PyRunClass(unsigned long seg, LogClass *myLog, QString path):_path(path)
{
    this->setObjectName("PyRunner");
    interval = seg;
    mLog = myLog;
    mLog->writeLog(this, "Creacion modulo " + this->objectName());
}
//Destructor
PyRunClass::~PyRunClass()
{
    mLog->writeLog(this, "Fin modulo " + this->objectName());
}
//Funcion que se ejecuta al iniciar el hilo
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
//Funcion para detener el proceso
void PyRunClass::stop()
{
    this->mStop = true;
}
