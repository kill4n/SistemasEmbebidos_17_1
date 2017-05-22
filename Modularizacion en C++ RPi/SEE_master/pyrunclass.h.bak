#ifndef PYRUNCLASS_H
#define PYRUNCLASS_H

#include "sthread.h"

class PyRunClass : public SThread
{
public:
    PyRunClass(unsigned long seg, LogClass *myLog);
    ~PyRunClass();
    virtual void run();
    virtual void stop();
};

#endif // PYRUNCLASS_H
