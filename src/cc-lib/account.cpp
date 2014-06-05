#include "account.h"

Account::Account(QObject *parent) :
    ISerializable(parent)
{
    m_id = m_id.createUuid();
}

/**
 * @brief Account::AddISerializable
 * Adds an instance of any subclass of ISerializable to the account
 * @param i Instance of ISerializable to be added
 */
void Account::AddISerializable(ISerializable &i)
{
    m_items.append(&i);
}

/**
 * @brief Account::RemoveISerializable
 * Removes an instance of any subclass of ISerializable from the account
 * @param i Instance of ISerializable to be removed
 */
void Account::RemoveISerializable(ISerializable &i)
{
    m_items.removeAll(&i);
}

/**
 * @brief Account::RemoveISerializable
 * Removes all instance of any subclass of ISerializable from the account
 */
void Account::RemoveAllISerializables()
{
    m_items.clear();
}

/**
 * @brief Account::serializeTo
 * serializeTo writes an Account to a QDataStream
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
 * @brief Account::serializeFrom
 * Reads an Account from a QDataStream
 * @param in Stream to read from
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
        //Creating dynamically allocated object with new, because otherwise if serializeFrom is at it's end,
        //the destructor of Calendar get's called
        //TODO: should you call delete in the destructor of Account?
        //Difference heap and stack allocation
        Calendar* c = new Calendar();
        in >> *c;
        this->AddISerializable(*c);
    }
}
