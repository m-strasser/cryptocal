#include "event.h"

Event::Event()
{
    repeatedIterations.append(*this);
}

/**
 * @brief Event::GetId
 * Returns the distinct ID of the Event.
 */
int Event::getId() const
{
    return id;
}

/**
 * @brief Event::GetRepeatedEvents
 * Returns a list containing Events, which are reoccuring instances
 * of one Event. (i.e. if an Event repeats weekly)
 */
QList<Event> Event::GetRepeatedEvents()
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
    repeatedIterations.append(e);
}

/**
 * @brief Event::RemoveRepeatedEvent
 * Removes an Event occurence.
 * @param e The occurence to be removed.
 */
void Event::RemoveRepeatedEvent(Event &e)
{
    repeatedIterations.removeAll(e);
}

void Event::RemoveAllRepeatedEvents()
{
    repeatedIterations.clear();
}
