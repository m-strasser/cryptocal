#include "event.h"

Event::Event(QObject *parent) :
    ISerializable(parent)
{
    m_id = m_id.createUuid();
    repeatedIterations.append(this);
}

/**
 * @brief Event::GetId
 * Returns the distinct ID of the Event.
 */
QUuid Event::id() const
{
    return m_id;
}

/**
 * @brief Event::GetRepeatedEvents
 * Returns a list containing Events, which are reoccuring instances
 * of one Event. (i.e. if an Event repeats weekly)
 */
QList<Event*> Event::GetRepeatedEvents()
{
    return repeatedIterations;
}

/**
 * @brief Event::AddRepeatedEvent
 * Adds an Event as a reoccuring instance of this one.
 * @param e The Event to be added.
 */
void Event::AddRepeatedEvent(Event &e)
{
    repeatedIterations.append(&e);
}

/**
 * @brief Event::RemoveRepeatedEvent
 * Removes an Event occurence.
 * @param e The occurence to be removed.
 */
void Event::RemoveRepeatedEvent(Event &e)
{
    repeatedIterations.removeAll(&e);
}

void Event::RemoveAllRepeatedEvents()
{
    repeatedIterations.clear();
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
    out << this->location;
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
    in >> this->location;
    in >> this->m_start;
    in >> this->m_end;
    in >> this->m_repeats;
}
