#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H

#include <QObject>

class ISerializable : public QObject
{
    Q_OBJECT
public:
    explicit ISerializable(QObject *parent = 0) : QObject(parent) {}

    virtual void serializeTo(QDataStream &out) const = 0;
    virtual void serializeFrom(QDataStream &in) = 0;

    friend QDataStream &operator<<(QDataStream &out, ISerializable &s)
    {
        //FIXME: Encrypt here
        s.serializeTo(out);
        return out;
    }
    friend QDataStream &operator>>(QDataStream &in, ISerializable &s)
    {
        //FIXME: Decrypt here
        s.serializeFrom(in);
        return in;
    }

signals:

public slots:

};

#endif // ISERIALIZABLE_H
