#ifndef TCPCLASS_H
#define TCPCLASS_H
/* Developed and mantained by killan*/
#include "sthread.h"
//Clase para comunicacion por sockets hereda de SThread
class TCPClass : public SThread
{
public:
    /* Constructor
     * parametros de entrada:
     *  seg     -> Cada cuanto se repite el proceso en segundos
     *  *myLog  -> Apuntador al Objeto que escribe el Log
     */
    TCPClass(unsigned long seg, LogClass *myLog);
    //Destructor
    ~TCPClass();
    //Funcion que se ejecuta al iniciar el hilo
    virtual void run();
    //Funcion para detener el proceso
    virtual void stop();
};

#endif // TCPCLASS_H
