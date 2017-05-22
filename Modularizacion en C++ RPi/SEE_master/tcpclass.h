#ifndef TCPCLASS_H
#define TCPCLASS_H

#include "sthread.h"

class TCPClass : public SThread
{
public:
    TCPClass(unsigned long seg, LogClass *myLog);
    ~TCPClass();
    virtual void run();
    virtual void stop();
};

#endif // TCPCLASS_H
