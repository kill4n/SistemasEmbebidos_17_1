#include "mysemaphore.h"

MySemaphore::MySemaphore(const char *fichero)
{
    //
    // Igual que en cualquier recurso compartido (memoria compartida, semaforos
    // o colas) se obtien una clave a partir de un fichero existente cualquiera
    // y de un entero cualquiera. Todos los procesos que quieran compartir este
    // semaforo, deben usar el mismo fichero y el mismo entero.
    //
    Clave = ftok(fichero, 33);
    if (Clave == (key_t) - 1) {
        cout << "No puedo conseguir clave de semáforo" << endl;
    }

    //
    // Se obtiene un array de semaforos (10 en este caso, aunque solo se usara
    // uno.
    // El IPC_CREAT indica que lo  cree si no lo está ya
    // el 0600 con permisos de lectura y escritura para el usuario que lance
    // los procesos. Es importante el 0 delante para que se interprete en
    // octal.
    //
    Id_Semaforo = semget (Clave, 10, 0600 | IPC_CREAT);
    if (Id_Semaforo == -1)
    {
        cout << "No puedo crear semáforo" << endl;
    }
}

void MySemaphore::startSemaphore(int nSem)
{
    //
    //	Se inicializa el semáforo con un valor conocido. Si lo ponemos a 0,
    //	es semáforo estará "rojo". Si lo ponemos a 1, estará "verde".
    //	El 0 de la función semctl es el índice del semáforo que queremos
    //	inicializar dentro del array de 10 que hemos pedido.
    //
    arg.val = 0;
    semctl (Id_Semaforo, 0, SETVAL, nSem);
    //
    //	Para "pasar" por el semáforo parándonos si está "rojo", debemos rellenar
    //	esta estructura.
    //	sem_num es el indice del semáforo en el array por el que queremos "pasar"
    //	sem_op es -1 para hacer que el proceso espere al semáforo.
    //	sem_flg son flags de operación. De momento nos vale un 0.
    //
    Operacion.sem_num = 0;
    Operacion.sem_op = -1;
    Operacion.sem_flg = 0;


}
