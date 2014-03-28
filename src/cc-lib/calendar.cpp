#include "calendar.h"

Calendar::Calendar(QObject *parent) :
    QObject(parent)
{
    m_id = m_id.createUuid();
}

QUuid Calendar::id() const
{
    return m_id;
}

/**
 * @brief Calendar::getEvents
 * Returns the Events of the Calendar.
 */
QList<Event*> Calendar::events() const
{
    return m_events;
}

/**
 * @brief Calendar::AddEvent
 * Adds an Event to the Calendar.
 */
void Calendar::AddEvent(Event &e)
{
    m_events.append(&e);
}

/**
 * @brief Calendar::RemoveEvent
 * Removes an Event from the Calendar.
 * @param e The occurence to be removed.
 */
void Calendar::RemoveEvent(Event &e)
{
    m_events.removeAll(&e);
}

/**
 * @brief Calendar::AddEvent
 * Adds an Event to the Calendar.
 */
void Calendar::RemoveAllEvents()
{
    m_events.clear();
}

QDataStream &operator<<(QDataStream &out, const Calendar &c)
{
    out << c.property("name");
    return out;
}

QDataStream &operator>>(QDataStream &in, Calendar &c)
{
    //c = new Calendar();
    //in >> c.setProperty("name");
    return in;
}
