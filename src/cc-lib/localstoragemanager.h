#ifndef LOCALSTORAGEMANAGER_H
#define LOCALSTORAGEMANAGER_H

#include "istoragemanager.h"
#include "account.h"

class LocalStorageManager : public IStorageManager
{
    Q_OBJECT
public:
    explicit LocalStorageManager(QObject *parent = 0);

    Q_PROPERTY(QFile* file MEMBER m_file)
    Q_PROPERTY(Account* account MEMBER m_account)
signals:

public slots:

private:
    QFile* m_file;
    Account* m_account;
    Account* returnacc;
};
#endif // LOCALSTORAGEMANAGER_H
