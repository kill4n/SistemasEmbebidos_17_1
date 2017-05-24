#ifndef PYRUNCLASS_H
#define PYRUNCLASS_H
/* Developed and mantained by killan*/
#include "sthread.h"

//Clase para correr los scripts de python hereda de SThread
class PyRunClass : public SThread
{
public:
    /* Constructor
     * parametros de entrada:
     *  seg     -> Cada cuanto se repite el proceso en segundos
     *  *myLog  -> Apuntador al Objeto que escribe el Log
     *  path    -> Direccion del script de Python
     */
    PyRunClass(unsigned long seg, LogClass *myLog, QString path = "/home/abc/xyz/script.py");
    //Destructor
    ~PyRunClass();
    //Funcion que se ejecuta al iniciar el hilo
    virtual void run();
    //Funcion para detener el proceso
    virtual void stop();
private:
    //Direccion del script de python
    QString _path;
};

#endif // PYRUNCLASS_H
