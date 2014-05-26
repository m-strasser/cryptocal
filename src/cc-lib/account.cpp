#include "account.h"

Account::Account(QObject *parent) :
    ISerializable(parent)
{
    m_id = m_id.createUuid();
}

/**
 * @brief serializeTo writes an Account to a QDataStream
 * @param out Stream to write to
 */
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

/**
 * @brief serializeFrom reads an Account from a QDataStream
 * @param out Stream to read from
 */
void Account::serializeFrom(QDataStream &in)
{
    in >> this->m_id;
    in >> this->m_name;
}
