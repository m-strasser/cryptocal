#include "localstoragemanager.h"

LocalStorageManager::LocalStorageManager(QObject *parent) :
    IStorageManager(parent)
{
    m_file->setFileName("storage");
}

void IStorageManager::SaveFiles(const Account &account, QFile &file)
{
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

    QDataStream out(&file);
    out << &account;
    file.close();
}

void IStorageManager::UploadFiles() const
{
}

Account* IStorageManager::LoadFiles(QFile &file)
{
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return NULL;

    //QDataStream in(&file);
    //Account* a = this->property("returnacc");
    //in >> a;
    //return a;
    file.close();
    return NULL;
}

void IStorageManager::DownloadFiles()
{
}
