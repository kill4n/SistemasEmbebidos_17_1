#ifndef SERIALCLASS_H
#define SERIALCLASS_H
/* Developed and mantained by killan*/
#include "sthread.h"
//Clase para comunicacion serial hereda de SThread
class SerialClass : public SThread
{
public:
    /* Constructor
     * parametros de entrada:
     *  seg     -> Cada cuanto se repite el proceso en segundos
     *  *myLog  -> Apuntador al Objeto que escribe el Log
     */
    SerialClass(unsigned long seg, LogClass *myLog);
    //Destructor
    ~SerialClass();
    //Funcion que se ejecuta al iniciar el hilo
    virtual void run();
    //Funcion para detener el proceso
    virtual void stop();
};

#endif // SERIALCLASS_H
