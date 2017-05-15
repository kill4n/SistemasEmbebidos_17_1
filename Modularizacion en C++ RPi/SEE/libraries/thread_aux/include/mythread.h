#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <pthread.h>

class MyThread
{
public:
    MyThread();
    virtual ~MyThread() = 0;
    /** Returns true if the thread was successfully started, false if there was an error starting the thread */
    bool StartInternalThread();

    /** Will not return until the internal thread has exited. */
    void WaitForInternalThreadToExit()
    {
        (void) pthread_join(_thread, NULL);
    }

protected:
    /** Implement this method in your subclass with the code you want your thread to run. */
    virtual void InternalThreadEntry() = 0;

private:
    static void * InternalThreadEntryFunc(void * This);
    pthread_t _thread;
};

#endif // MYTHREAD_H
