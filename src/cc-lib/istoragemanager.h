#ifndef ISTORAGEMANAGER_H
#define ISTORAGEMANAGER_H

#include <QObject>
#include <QFile>
#include <QDataStream>
#include <account.h>


class IStorageManager : public QObject
{
    Q_OBJECT
public:
    explicit IStorageManager(QObject *parent = 0) : QObject(parent) {}

    virtual void SaveFiles(Account &account, QFile &file) = 0;
    virtual void UploadFiles() const = 0;

    virtual Account* LoadFiles(QFile &file) = 0;
    virtual void DownloadFiles() = 0;
};

#endif // ISTORAGEMANAGER_H
