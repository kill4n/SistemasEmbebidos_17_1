#ifndef LOGCLASS_H
#define LOGCLASS_H

#include <QObject>
#include <QFile>
#include <QDebug>
#include <QMutex>

class LogClass : public QObject
{
    Q_OBJECT
public:
    LogClass(QString path = "./log.txt");
    ~LogClass();
    void writeLog(QString name, QString message);
    void writeLog(QObject *sender, QString message);
private:
    QString _path;
    QFile *_file;
    QMutex mutex;
};

#endif // LOGCLASS_H
