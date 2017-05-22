#ifndef SERIALCLASS_H
#define SERIALCLASS_H

#include "sthread.h"

class SerialClass : public SThread
{
public:
    SerialClass(unsigned long seg, LogClass *myLog);
    ~SerialClass();
    virtual void run();
    virtual void stop();
};

#endif // SERIALCLASS_H
