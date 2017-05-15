#include "mysocket.h"

MySocket::MySocket(TCP_TYPE tipo, int puerto, string IP)
{
    portno = puerto;
    if(tipo == SERVER)
    {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0)
            cout<<"ERROR opening socket";
        bzero((char *) &serv_addr, sizeof(serv_addr));
        portno = puerto;
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(portno);
        if (bind(sockfd, (struct sockaddr *) &serv_addr,
                 sizeof(serv_addr)) < 0)
            printf("ERROR on binding");
    }
}

MySocket::~MySocket()
{

}

bool MySocket::Conectar()
{
    isRunning = true;
    return true;
}

void MySocket::closeSock()
{
    close(newsockfd);
    close(sockfd);
}

void MySocket::setCallback(void (*cb)(MensajesEventArgs))
{
    callback = cb;
}

void MySocket::InternalThreadEntry()
{
    printf("Hola  sd desde Hilo {%d}\r\n",isRunning);


    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd,
                       (struct sockaddr *) &cli_addr,
                       &clilen);
    if (newsockfd < 0)
    {
        isRunning = false;
    }
    printf("Cliente Aceptado \r\n");
    while (isRunning) {
        char *d= new char[1];
        readData(d,1);
        switch ((int)d[0]) {
        case 0x10://seleccion modo operacion
            d= new char[1];
            readData(d,1);
            printf("Cambiar Modo \r\n");

            e.setData(0x10, 1, d);
            break;
        case 0x11:
            d= new char[1];
            readData(d,1);
            printf("Pedir foto \r\n");

            e.setData(0x11, 1, d);
            break;
        default:
            break;
        }

        this->callback(e);
        usleep(10000);
    }
    this->closeSock();
}

int MySocket::SendData(char* data, int sizeData){
    int n = write(newsockfd,data,sizeData);
    if (n < 0) printf("ERROR writing to socket");
    return n;
}

int MySocket::readData(char* data, int sizeData){
    int n = read(newsockfd,data,sizeData);
    if (n < 0) printf("ERROR reading from socket");
    //printf("Here is the message: %s\n",data);
    return n;
}
