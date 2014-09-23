#include "localstoragemanager.h"

LocalStorageManager::LocalStorageManager(QObject *parent) :
    IStorageManager(parent)
{
}

/**
 * @brief LocalStorageManager::SaveFiles
 * Writes an Account and all it's content to the given file.
 * @param account Account to save
 * @param in File to save
 */
void LocalStorageManager::SaveFiles(const Account &account, QFile &file)
{
    if (!file.open(QIODevice::WriteOnly))
            return;

    QDataStream out(&file);
    out << account;
    file.close();
}

/**
 * @brief not implemented by LocalStorageManager
 */
void LocalStorageManager::UploadFiles() const
{
}

/**
 * @brief LocalStorageManager::LoadFiles
 * Loads an Account and all it's content from the given file.
 * @param in File to save
 * @return The Account instance with all it's content
 */
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

/**
 * @brief not implemented by LocalStorageManager
 */
void LocalStorageManager::DownloadFiles()
{
}
