#include <QCoreApplication>
/* Developed and mantained by killan*/
//Incluir librerias de Qt
#include <QDebug>
#include <QThread>
//Incluir clases propias
#include "logclass.h"
#include "statusclass.h"
#include "pyrunclass.h"
#include "serialclass.h"
#include "tcpclass.h"

//Inicio funcion main
int main(int argc, char *argv[])
{
    //Creacion de aplicacion de consola de Qt
    QCoreApplication a(argc, argv);
    //Darle un nombrea a la funcion principal
    a.setObjectName("Master");
    //Definir la demora de todos los hilos
    unsigned long dem = 1;
    LogClass mLog;                  //Log para saber que y cuando pasa
    mLog.writeLog(&a,"Start app");  //Inicio de aplicacion en Log

    //Creacion de los objetos de cada clase necesaria
    StatusClass mStatus(dem, &mLog);
    PyRunClass mPyRun(dem, &mLog, "/home/pi/python/pyMongo.py");
    SerialClass mSerial(dem, &mLog);
    TCPClass mTCP(dem, &mLog);

    //Demora antes de iniciar
    QThread::sleep(5);
    //Iniciar los 5 Hilos
    mStatus.start();
    mPyRun.start();
    mSerial.start();
    mTCP.start();


    //Terminar la aplicacion
    mLog.writeLog(&a,"Finish app");
    //Salir de la aplicaion
    return a.exec();
}
