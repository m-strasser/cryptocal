#include "calendar.h"

Calendar::Calendar(QObject *parent) :
    ISerializable(parent)
{
    m_id = m_id.createUuid();
}

void Calendar::AddEvent(Event &e)
{
    m_events.append(&e);
}

void Calendar::RemoveEvent(Event &e)
{
    m_events.removeAll(&e);
}

void Calendar::RemoveAllEvents()
{
    m_events.clear();
}

void Calendar::serializeTo (QDataStream &out) const
{
    out << this->m_id;
    out << this->m_name;
    out << this->m_description;
    out << this->m_color;
    out << this->m_synchronised;

    out << this->m_events.count();
    foreach(Event* event, this->m_events)
    {
        out << *event;
    }
}

void Calendar::serializeFrom(QDataStream &in)
{
    int count;

    in >> this->m_id;
    in >> this->m_name;
    in >> this->m_description;
    in >> this->m_color;
    in >> this->m_synchronised;

    in >> count;
    for (int i=0;i<count;++i)
    {
        Event* e = new Event();
        in >> *e;
        this->m_events.append(e);
    }
}
