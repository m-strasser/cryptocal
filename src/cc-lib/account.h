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
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
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

    /**
     * @brief Adds the given ISerializable instance to the internal list
     * @param i Instance of ISerializable to be added
     */
    void AddISerializable(ISerializable &i);

    /**
     * @brief Removes the given ISerializable instance from the internal list.
     * @param i Instance of ISerializable to be removed
     */
    void RemoveISerializable(ISerializable &i);

    /**
     * @brief Removes all ISerializable objects from the internal list.
     */
    void RemoveAllISerializables();

    /**
     * @brief operator == compares two Accounts.
     * @details The comparison is done by comparing the id property of both Accounts.
     * If you have to instances with the same id but different content, the operator will still return true.
     * @param account Account to compare the first Account with.
     * @return True, if the two IDs are the same, else false.
     */
    bool operator ==(const Account &account) const
    {
            return this->m_id == account.id();
    }

signals:

    void nameChanged(QString arg);

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

    /**
     * @brief Writes the Account to the given QDataStream
     * @param out Stream to write to
     */
    void serializeTo(QDataStream &out) const;

    /**
     * @brief Reads an Account from the given QDataStream
     * @param in Stream to read from
     */
    void serializeFrom(QDataStream &in);
};

#endif // ACCOUNT_H
