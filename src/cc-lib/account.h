#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QObject>
#include <QUuid>
#include <QList>
#include <QVariant>
#include <iserializable.h>
#include <calendar.h>


class Account : public ISerializable

{
    Q_OBJECT
    Q_PROPERTY(QUuid id READ id)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QList<ISerializable*> items READ items WRITE setItems)
public:
    explicit Account(QObject *parent = 0);


    QUuid id() const
    {
        return m_id;
    }

    QString name() const
    {
        return m_name;
    }

    QList<ISerializable*> items() const
    {
        return m_items;
    }

    void AddISerializable(ISerializable &i);
    void RemoveISerializable(ISerializable &i);
    void RemoveAllISerializables();

    /**
     * @brief operator == Compares the ID of two Accounts.
     * @param account Second Account.
     * @return True, if the two IDs are the same, else false.
     */
    bool operator ==(const Account &account) const
    {
            return this->m_id == account.id();
    }

signals:

public slots:

    void setName(QString arg)
    {
        m_name = arg;
    }

    void setItems(QList<ISerializable*> arg)
    {
        m_items = arg;
    }

private:
    QUuid m_id;
    QString m_name;
    QList<ISerializable*> m_items;

    void serializeTo(QDataStream &out) const;
    void serializeFrom(QDataStream &in);
};

#endif // ACCOUNT_H
