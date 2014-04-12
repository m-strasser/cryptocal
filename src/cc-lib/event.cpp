#include "event.h"

Event::Event(QObject *parent) :
    QObject(parent)
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
 * @brief operator << writes an Event to a QDataStream
 * @param out Stream to write to
 * @param e Event to write
 * @return The QDataStream
 */
QDataStream &operator<<(QDataStream &out, const Event &e)
{
    out << e.m_id;
    out << e.name;
    out << e.description;
    out << e.location;
    out << e.start;
    out << e.end;
    out << e.m_repeats;

    return out;
}

/**
 * @brief operator >> reads an Event from a QDataStream
 * @param in Stream to read from
 * @param e Event to read into
 * @return The QDataStream
 */
QDataStream &operator>>(QDataStream &in, Event &e)
{
    in >> e.m_id;
    in >> e.name;
    in >> e.description;
    in >> e.location;
    in >> e.start;
    in >> e.end;
    in >> e.m_repeats;

    return in;
}
