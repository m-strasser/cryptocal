#include "calendar.h"

Calendar::Calendar(QObject *parent) :
    ISerializable(parent)
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

/**
 * @brief operator << writes a Calendar to a QDataStream
 * @param out Stream to write to
 * @param c Calendar to write.
 * @return Returns the QDataStream
 */
void Calendar::serializeTo (QDataStream &out) const
{
    out << this->m_id;
    out << this->m_name;
    out << this->m_description;
    out << this->m_color;
    out << this->m_synchronised;
    out << this->m_events;
}

/**
 * @brief operator >> reads a Calendar from a QDataStream
 * @param out Stream to read from
 * @param c Calendar to read into.
 * @return Returns the QDataStream
 */
QDataStream &operator>>(QDataStream &in, Calendar &c)
{
    in >> c.m_id;
    in >> c.m_name;
    in >> c.m_description;
    in >> c.m_color;
    in >> c.m_synchronised;

    return in;
}
