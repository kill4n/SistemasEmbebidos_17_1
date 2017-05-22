#ifndef STATUSCLASS_H
#define STATUSCLASS_H

#include "sthread.h"

class StatusClass : public SThread
{
public:
    StatusClass(unsigned long seg, LogClass *myLog);
    ~StatusClass();
    virtual void run();
    virtual void stop();
};

#endif // STATUSCLASS_H
