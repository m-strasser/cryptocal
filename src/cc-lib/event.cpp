#include "event.h"

Event::Event(QObject *parent) :
    ISerializable(parent)
{
    m_id = m_id.createUuid();
    m_repeatedEvents.append(this);
}

void Event::AddRepeatedEvent(Event &e)
{
    m_repeatedEvents.append(&e);
}

void Event::RemoveRepeatedEvent(Event &e)
{
    m_repeatedEvents.removeAll(&e);
}

void Event::RemoveAllRepeatedEvents()
{
    m_repeatedEvents.clear();
}

void Event::serializeTo (QDataStream &out) const
{
    out << this->m_id;
    out << this->m_name;
    out << this->m_description;
    out << this->m_location;
    out << this->m_start;
    out << this->m_end;
    out << this->m_repeats;
}

void Event::serializeFrom(QDataStream &in)
{
    in >> this->m_id;
    in >> this->m_name;
    in >> this->m_description;
    in >> this->m_location;
    in >> this->m_start;
    in >> this->m_end;
    in >> this->m_repeats;
}
