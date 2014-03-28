#include "calendar.h"

Calendar::Calendar(QObject *parent) :
    QObject(parent)
{
    id = id.createUuid();
}

/**
 * @brief Celander::getId
 * Returns the distinct ID of the Calendar.
 */
QUuid Calendar::getId() const
{
    return id;
}

/**
 * @brief Calendar::getEvents
 * Returns the Events of the Calendar.
 */
QList<Event*> Calendar::getEvents() const
{
    return events;
}

/**
 * @brief Calendar::AddEvent
 * Adds an Event to the Calendar.
 */
void Calendar::AddEvent(Event &e)
{
    events.append(&e);
}

/**
 * @brief Calendar::RemoveEvent
 * Removes an Event from the Calendar.
 * @param e The occurence to be removed.
 */
void Calendar::RemoveEvent(Event &e)
{
    events.removeAll(&e);
}

/**
 * @brief Calendar::AddEvent
 * Adds an Event to the Calendar.
 */
void Calendar::RemoveAllEvents()
{
    events.clear();
}
