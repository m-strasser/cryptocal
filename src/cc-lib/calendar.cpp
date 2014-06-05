#include "calendar.h"

Calendar::Calendar(QObject *parent) :
    ISerializable(parent)
{
    m_id = m_id.createUuid();
}

/**
 * @brief Calendar::AddEvent
 * Adds an Event to the Calendar.
 * @param e The event to be added
 */
void Calendar::AddEvent(Event &e)
{
    m_events.append(&e);
}

/**
 * @brief Calendar::RemoveEvent
 * Removes an Event from the Calendar.
 * @param e The Event to be removed.
 */
void Calendar::RemoveEvent(Event &e)
{
    m_events.removeAll(&e);
}

/**
 * @brief Calendar::RemoveAllEvents()
 * Removes all the Events.
 */
void Calendar::RemoveAllEvents()
{
    m_events.clear();
}

/**
 * @brief Calendar::serializeTo
 * Writes a Calendar to a QDataStream
 * @param in Stream to write to
 */
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

/**
 * @brief Calendar::serializeFrom
 * Reads a Calendar from a QDataStream
 * @param in Stream to read from
 */
void Calendar::serializeFrom(QDataStream &in)
{
    int count;

    in >> this->m_id;
    in >> this->m_name;
    in >> this->m_description;
    in >> this->m_color;
    in >> this->m_synchronised;

    in >> count;
    for(int i=0;i<count;++i)
    {
        Event* e = new Event();
        in >> *e;
        this->m_events.append(e);
    }
}


