#ifndef PYRUNCLASS_H
#define PYRUNCLASS_H

#include "sthread.h"

class PyRunClass : public SThread
{
public:
    PyRunClass(unsigned long seg, LogClass *myLog, QString path = "/home/abc/xyz/script.py");
    ~PyRunClass();
    virtual void run();
    virtual void stop();
private:
    QString _path;
};

#endif // PYRUNCLASS_H
