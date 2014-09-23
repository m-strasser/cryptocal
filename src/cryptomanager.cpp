#include "cryptomanager.h"

CryptoManager::CryptoManager(QObject *parent) :
    QObject(parent)
{
    qDebug() << "key length: " << AES::DEFAULT_KEYLENGTH;
    qDebug() << "key length (min): " << AES::MIN_KEYLENGTH;
    qDebug() << "key length (max): " << AES::MAX_KEYLENGTH;
    qDebug() << "block size: " << AES::BLOCKSIZE;
}

QDataStream& CryptoManager::encrypt(QDataStream &in)
{
    return in;
}

QDataStream& CryptoManager::decrypt(QDataStream &in)
{
    return in;
}

void CryptoManager::loadKey(QFile &file)
{

}

void CryptoManager::saveKey(QFile &file)
{

}

void CryptoManager::generateKey(QString passphrase)
{

}
