#include <QCoreApplication>
#include <QDebug>
#include <QThread>

#include "logclass.h"
#include "statusclass.h"
#include "pyrunclass.h"
#include "serialclass.h"
#include "tcpclass.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    a.setObjectName("Main");
    unsigned long dem = 1;
    LogClass mLog;                  //Log para saber que y cuando pasa
    mLog.writeLog(&a,"Start app");

    StatusClass mStatus(dem, &mLog);
    PyRunClass mPyRun(dem, &mLog);
    SerialClass mSerial(dem, &mLog);
    TCPClass mTCP(dem, &mLog);

    //Demora antes de iniciar
    QThread::sleep(5);
    mStatus.start();
    mPyRun.start();
    mSerial.start();
    mTCP.start();

    mStatus.wait();

    mLog.writeLog(&a,"Finish app");
    return a.exec();
}
