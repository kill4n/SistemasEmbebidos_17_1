#ifndef STATUSCLASS_H
#define STATUSCLASS_H
/* Developed and mantained by killan*/
#include "sthread.h"
//Clase para el status general hereda de SThread
class StatusClass : public SThread
{
public:
    /* Constructor
     * parametros de entrada:
     *  seg     -> Cada cuanto se repite el proceso en segundos
     *  *myLog  -> Apuntador al Objeto que escribe el Log
     */
    StatusClass(unsigned long seg, LogClass *myLog);
    //Destructor
    ~StatusClass();
    //Funcion que se ejecuta al iniciar el hilo
    virtual void run();
    //Funcion para detener el proceso
    virtual void stop();
};

#endif // STATUSCLASS_H
