#ifndef ISTORAGEMANAGER_H
#define ISTORAGEMANAGER_H

#include <QObject>

class IStorageManager : public QObject
{
    Q_OBJECT
public:
    explicit IStorageManager(QObject *parent = 0);

signals:

public slots:

};

#endif // ISTORAGEMANAGER_H
