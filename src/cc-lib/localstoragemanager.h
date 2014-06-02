#ifndef LOCALSTORAGEMANAGER_H
#define LOCALSTORAGEMANAGER_H

#include "istoragemanager.h"
#include "account.h"

class LocalStorageManager : public IStorageManager
{
    Q_OBJECT
public:
    explicit LocalStorageManager(QObject *parent = 0);

    void SaveFiles(Account &account, QFile &file);
    void UploadFiles() const;

    Account* LoadFiles(QFile &file);
    void DownloadFiles();
signals:

public slots:

private:

};
#endif // LOCALSTORAGEMANAGER_H
