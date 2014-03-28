#ifndef ISTORAGEMANAGER_H
#define ISTORAGEMANAGER_H

#include <QObject>
#include <QFile>


class IStorageManager : public QObject
{
    Q_OBJECT
public:
    virtual void SaveFiles(const QDataStream &stream, QFile &file) = 0;
    virtual void UploadFiles() const = 0;

    virtual QObject LoadFiles(QFile &file) = 0;
    virtual void downloadFiles() = 0;
};

#endif // ISTORAGEMANAGER_H
