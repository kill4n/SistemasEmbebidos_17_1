#ifndef MYSOCKET_H
#define MYSOCKET_H

#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "librerias/thread_aux/include/mythread.h"
#include "librerias/mensajes_aux/include/mimensaje.h"

using namespace std;

enum TCP_TYPE{
    SERVER,
    CLIENT
};

class MensajesEventArgs
{
public:
    MensajesEventArgs() {
        _datos= new char[230400];
    }
    void setData(char cmd, int nData,char* dat){
        _comando = cmd;
        _numDatos = nData;
        _datos= dat;
    }
public:
    char _comando;
    int _numDatos;
    char *_datos;
};

class MySocket : public MyThread
{
public:
    MySocket(TCP_TYPE tipo, int puerto=3333, string IP="127.0.0.1");
    ~MySocket();
    bool Conectar();
    int SendData(char* data, int sizeData);
    int readData(char* data, int sizeData);

    void closeSock();

    void setCallback(void (*cb)(MensajesEventArgs));

    virtual void InternalThreadEntry();
private:
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[5000];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    bool isRunning;
    MensajesEventArgs e;

    void (*callback)(MensajesEventArgs);


};

#endif // MYSOCKET_H
