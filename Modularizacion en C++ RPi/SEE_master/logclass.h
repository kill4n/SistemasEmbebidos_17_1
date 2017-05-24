#ifndef LOGCLASS_H
#define LOGCLASS_H
/* Developed and mantained by killan*/
#include <QObject>
#include <QFile>
#include <QDebug>
#include <QMutex>
#include <QTextStream>
#include <QDateTime>

//Clase para crear los logs de informacion hereda de QObject
class LogClass : public QObject
{
    Q_OBJECT
public:
    //Constructor que recibe la direccion del archivo a crear.
    LogClass(QString path = "./log.txt");
    //Destructor
    ~LogClass();
    /* Funciones para escribir en el archivo de texto
     * Recibe en la primera parte el nombre de quien
     * genera el mensje para el log, y en el segundo
     * parametro el mensaj que se desea enviar
     */
    void writeLog(QString name, QString message);
    void writeLog(QObject *sender, QString message);
private:
    //Direccion del archivo para el Log
    QString _path;
    //Apuntador al archivo del Log
    QFile *_file;
    //Variable para hacer el programa ThreadSafe
    QMutex mutex;
};

#endif // LOGCLASS_H
