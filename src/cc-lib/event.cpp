#include "event.h"

Event::Event(QObject *parent) :
    ISerializable(parent)
{
    m_id = m_id.createUuid();
    m_repeatedEvents.append(this);
}

/**
 * @brief Event::AddRepeatedEvent
 * Adds an Event as a reoccuring instance of this one.
 * @param e The Event to be added.
 */
void Event::AddRepeatedEvent(Event &e)
{
    m_repeatedEvents.append(&e);
}

/**e
 * @brief Event::RemoveRepeatedEvent
 * Removes an Event occurence.
 * @param e The occurence to be removed.
 */
void Event::RemoveRepeatedEvent(Event &e)
{
    m_repeatedEvents.removeAll(&e);
}

/**
 * @brief Event::RemoveAllRepeatedEvents()
 * Removes all Events occurences.
 */
void Event::RemoveAllRepeatedEvents()
{
    m_repeatedEvents.clear();
}

/**
 * @brief serializeTo writes an Event to a QDataStream
 * @param out Stream to write to
 */
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

/**
 * @brief serializeFrom reads an Event from a QDataStream
 * @param in Stream to read from
 */
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
