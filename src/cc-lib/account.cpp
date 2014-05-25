#include "account.h"

Account::Account(QObject *parent) :
    ISerializable(parent)
{
    m_id = m_id.createUuid();
}

QUuid Account::id() const
{
    return m_id;
}

void Account::serializeTo(QDataStream &out) const
{
    out << this->m_id;
    out << this->m_name;
    out << this->m_items.count();
    foreach(ISerializable* item, this->m_items)
    {
        out << *item;
    }
}

void Account::serializeFrom(QDataStream &in)
{
    in >> this->m_id;
    in >> this->m_name;
}
