#include "logclass.h"
/* Developed and mantained by killan*/

//Constructor que recibe la direccion del archivo a crear.
LogClass::LogClass(QString path):_path(path)
{
    this->setObjectName("Log...");
    _file = new QFile( _path );
    if ( !_file->open(QIODevice::ReadWrite | QIODevice::Append))
    {
        qDebug() << "No se pudo abrir el archivo";
    }
    else
    {
        writeLog(this, "Archivo de logs guardado en " + _path);
    }
}
//Destructor
LogClass::~LogClass()
{
    try {
        _file->close();
    } catch (...) {
    }
    delete this->_file;
    this->_file = nullptr;
}
/* Funcion para escribir en el archivo de texto
 * Recibe en la primera parte el nombre de quien
 * genera el mensje para el log, y en el segundo
 * parametro el mensaj que se desea enviar
 */
void LogClass::writeLog(QObject *sender,QString message){
    writeLog(sender->objectName(), message);
}
/* Funcion para escribir en el archivo de texto
 * Recibe en la primera parte el objeto que
 * genera el mensje para el log, y en el segundo
 * parametro el mensaj que se desea enviar
 */
void LogClass::writeLog(QString name, QString message)
{
    mutex.lock();
    if (_file->isOpen()) {
        QTextStream stream( _file );
        QString data = "[" + QDateTime::currentDateTime().toString() +
                "]" + name + ": " + message;
        stream << data << endl;
        qDebug() << data ;
        _file->flush();
    }
    mutex.unlock();
}
