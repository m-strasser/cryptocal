#include "account.h"

Account::Account(QObject *parent) :
    ISerializable(parent)
{
    m_id = m_id.createUuid();
}

void Account::AddISerializable(ISerializable &i)
{
    m_items.append(&i);
}

void Account::RemoveISerializable(ISerializable &i)
{
    m_items.removeAll(&i);
}

void Account::RemoveAllISerializables()
{
    m_items.clear();
}

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
