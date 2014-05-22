#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H

#include <QObject>

class ISerializable : public QObject
{
    Q_OBJECT
public:
    explicit ISerializable(QObject *parent = 0);

    virtual void serializeTo(QDataStream &out) const = 0;
    friend QDataStream &operator<<(QDataStream &out, const ISerializable &s)
    {
        s.serializeTo(out);
        return out;
    }

signals:

public slots:

};

#endif // ISERIALIZABLE_H
