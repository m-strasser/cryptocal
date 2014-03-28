#ifndef CALENDAR_H
#define CALENDAR_H

#include <QObject>
#include <QUuid>
#include <QColor>
#include "event.h"

class Calendar : public QObject
{
    Q_OBJECT
public:
    explicit Calendar(QObject *parent = 0);

    QString name;
    QString description;
    QColor color;
    bool synchronised;

    QUuid getId() const;
    QList<Event*> getEvents() const;
    void AddEvent(Event &e);
    void RemoveEvent(Event &e);
    void RemoveAllEvents();

    /**
     * @brief operator == Compares the ID of two Calendars.
     * @param c2 Second Calendar.
     * @return True, if the two IDs are the same, else false.
     */
    bool operator ==(const Calendar &c2) const
    {
            return getId()==c2.getId();
    }
    // TODO: Operator overloading for serialization

private:
    QUuid id;
    QList<Event*> events;

};

#endif // CALENDAR_H
