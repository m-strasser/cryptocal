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

//FIXME: Should be just a namespace, or a static class
class CryptoManager : public QObject
{
    Q_OBJECT
public:
    explicit CryptoManager(QObject *parent = 0);

    /**
     * @brief Encrypt the given DataStream
     * @param in DataStream to encrypt
     * @return Returns the encrypted DataStream
     */
    QDataStream& encrypt(QDataStream &in);

    /**
     * @brief Decrypt the given DataStream
     * @param in DataStream to decrypt
     * @return Returns the decrypted DataStream
     */
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
