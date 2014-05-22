#ifndef ISTORAGEMANAGER_H
#define ISTORAGEMANAGER_H

#include <QObject>
#include <QFile>
#include <QDataStream>


class IStorageManager : public QObject
{
    Q_OBJECT
public:
    explicit IStorageManager(QObject *parent = 0);

    virtual void SaveFiles(const QDataStream &stream, QFile &file) = 0;
    virtual void UploadFiles() const = 0;

    virtual QObject* LoadFiles(QFile &file) = 0;
    virtual void DownloadFiles() = 0;
};

#endif // ISTORAGEMANAGER_H
