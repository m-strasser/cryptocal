#ifndef CRYPTOMANAGER_H
#define CRYPTOMANAGER_H

#include <QObject>
#include <QVariant>
#include <QFile>
#include <QDebug>
#include <cryptopp/aes.h>
#include <cryptopp/ccm.h>
#include <cryptopp/osrng.h>

using CryptoPP::AES;
using CryptoPP::CTR_Mode;
using CryptoPP::AutoSeededRandomPool;

class CryptoManager : public QObject
{
    Q_OBJECT
public:
    explicit CryptoManager(QObject *parent = 0);

    QDataStream& encrypt(QDataStream &in);
    QDataStream& decrypt(QDataStream &in);
    void loadKey(QFile &file);
    void saveKey(QFile &file);
    void generateKey(QString passphrase);

signals:

public slots:

private:
    AutoSeededRandomPool prng;
    byte key[AES::MAX_KEYLENGTH];
    byte iv[AES::IV_LENGTH];
};

#endif // CRYPTOMANAGER_H
