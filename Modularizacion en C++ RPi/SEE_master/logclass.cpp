#include "logclass.h"
#include <QTextStream>
#include <QDateTime>


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

LogClass::~LogClass()
{
    try {
        _file->close();
    } catch (...) {
    }
}

void LogClass::writeLog(QObject *sender,QString message){
    writeLog(sender->objectName(), message);
}

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
