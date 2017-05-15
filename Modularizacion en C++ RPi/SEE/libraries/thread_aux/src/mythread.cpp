#include "mythread.h"

MyThread::MyThread()
{
}

MyThread::~MyThread()
{

}

bool MyThread::StartInternalThread()
{
    return (pthread_create(&_thread, NULL, InternalThreadEntryFunc, this) == 0);
}

void *MyThread::InternalThreadEntryFunc(void *This) {
    ((MyThread *)This)->InternalThreadEntry(); return NULL;
}
