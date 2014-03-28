#ifndef CALENDAR_H
#define CALENDAR_H

#include <QObject>
#include <QUuid>
#include <QColor>
#include <QVariant>
#include "event.h"

class Calendar : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QUuid id READ id)
    Q_PROPERTY(QString name MEMBER m_name)
    Q_PROPERTY(QString description MEMBER m_description)
    Q_PROPERTY(QColor color MEMBER m_color)
    Q_PROPERTY(bool synchronised MEMBER m_synchronised)
    Q_PROPERTY(QList<Event*> events READ events)

public:
    explicit Calendar(QObject *parent = 0);

    QUuid id() const;

    QList<Event*> events() const;
    void AddEvent(Event &e);
    void RemoveEvent(Event &e);
    void RemoveAllEvents();

    friend QDataStream &operator<<(QDataStream &out, const Calendar &c);
    friend QDataStream &operator>>(QDataStream &in, Calendar &c);

    /**
     * @brief operator == Compares the ID of two Calendars.
     * @param c2 Second Calendar.
     * @return True, if the two IDs are the same, else false.
     */
    bool operator ==(const Calendar &c2) const
    {
            return this->id() == c2.id();
    }
    // TODO: Operator overloading for serialization

private:
    QUuid m_id;
    QString m_name;
    QString m_description;
    QColor m_color;
    bool m_synchronised;
    QList<Event*> m_events;

};



#endif // CALENDAR_H
