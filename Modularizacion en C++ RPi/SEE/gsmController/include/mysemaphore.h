#ifndef MYSEMAPHORE_H
#define MYSEMAPHORE_H

#include <sys/ipc.h>
#include <sys/sem.h>

#include <stdio.h>
#include <iostream>

using namespace std;

//
// Esta union hay que definirla o no según el valor de los defines aqui
// indicados.
//
#if defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)
// La union ya está definida en sys/sem.h
#else
// Tenemos que definir la union
union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
    struct seminfo *__buf;
};
#endif

class MySemaphore
{
public:
    MySemaphore(const char *fichero = "/bin/ls");
    void startSemaphore(int nSem);
private:
    key_t Clave;
    int Id_Semaforo;
    struct sembuf Operacion;
    union semun arg;

};

#endif // MYSEMAPHORE_H
