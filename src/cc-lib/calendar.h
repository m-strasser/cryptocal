#ifndef CALENDAR_H
#define CALENDAR_H

#include <QObject>
#include <QUuid>
#include <QColor>
#include <QVariant>
#include <QList>

#include "iserializable.h"
#include "event.h"

class Calendar : public ISerializable
{
    Q_OBJECT
    Q_PROPERTY(QUuid id READ id)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString description READ description WRITE setDescription)
    Q_PROPERTY(QColor color READ color WRITE setColor)
    Q_PROPERTY(bool synchronised READ synchronised WRITE setSynchronised)
    Q_PROPERTY(QList<Event*> events READ events)

public:
    explicit Calendar(QObject *parent = 0);

    QUuid id() const
    {
        return m_id;
    }

    QString name() const
    {
        return m_name;
    }

    QString description() const
    {
        return m_description;
    }

    QColor color() const
    {
        return m_color;
    }

    bool synchronised() const
    {
        return m_synchronised;
    }

    QList<Event*> events() const
    {
        return m_events;
    }

    void AddEvent(Event &e);
    void RemoveEvent(Event &e);
    void RemoveAllEvents();

    /**
     * @brief operator == Compares the ID of two Calendars.
     * @param calendar Second Calendar.
     * @return True, if the two IDs are the same, else false.
     */
    bool operator ==(const Calendar &calendar) const
    {
            return this->m_id == calendar.id();
    }

public slots:
    void setName(QString arg)
    {
        m_name = arg;
    }

    void setDescription(QString arg)
    {
        m_description = arg;
    }

    void setColor(QColor arg)
    {
        m_color = arg;
    }

    void setSynchronised(bool arg)
    {
        m_synchronised = arg;
    }

private:
    QUuid m_id;
    QString m_name;
    QString m_description;
    QColor m_color;
    bool m_synchronised;
    QList<Event*> m_events;

    void serializeTo(QDataStream &out) const;
    void serializeFrom(QDataStream &in);
};



#endif // CALENDAR_H
