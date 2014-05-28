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
    foreach(ISerializable* i, this->m_items)
    {
        out << *i;
    }
}

/**
 * @brief serializeFrom reads an Account from a QDataStream
 * @param out Stream to read from
 */
void Account::serializeFrom(QDataStream &in)
{
    int count;
    in >> this->m_id;
    in >> this->m_name;

    in >> count;
    //TODO: Make generic
    for(int i=0;i<count;++i)
    {
        Calendar c;
        in >> c;
        this->m_items.append(&c);
    }
}
