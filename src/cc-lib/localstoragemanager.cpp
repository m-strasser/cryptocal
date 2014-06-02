#include "localstoragemanager.h"

LocalStorageManager::LocalStorageManager(QObject *parent) :
    IStorageManager(parent)
{
}

void LocalStorageManager::SaveFiles(Account &account, QFile &file)
{
    if (!file.open(QIODevice::WriteOnly))
            return;

    QDataStream out(&file);
    out << account;
    file.close();
}

void LocalStorageManager::UploadFiles() const
{
}

Account* LocalStorageManager::LoadFiles(QFile &file)
{
    if (!file.open(QIODevice::ReadOnly))
            return NULL;

    QDataStream in(&file);
    Account* a = new Account();
    in >> *a;
    file.close();

    return a;
}

void LocalStorageManager::DownloadFiles()
{
}
