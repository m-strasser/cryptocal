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
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(bool synchronised READ synchronised WRITE setSynchronised NOTIFY synchronisedChanged)
    Q_PROPERTY(QList<Event*> events READ events)

public:
    explicit Calendar(QObject *parent = 0);

    /**
     * @brief Adds the given Event to the internal list
     * @param e Event to be added
     */
    void AddEvent(Event &e);

    /**
     * @brief Removes the given Event from the internal list
     * @param e Event to be removed
     */
    void RemoveEvent(Event &e);

    /**
     * @brief Removes all the Events from the internal list
     */
    void RemoveAllEvents();

    /**
     * @brief operator == compares two Calendar.
     * @details The comparison is done by comparing the id property of both Calendars.
     * If you have to instances with the same id but different content,
     * the operator will still return true.
     * @param Calendar Instance of Calendar to compare the first Calendar with.
     * @return True, if the two IDs are the same, else false.
     */
    bool operator ==(const Calendar &calendar) const
    {
            return this->m_id == calendar.id();
    }

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

public slots:
    void setName(QString arg)
    {
        if (m_name == arg)
            return;

        m_name = arg;
        emit nameChanged(arg);
    }

    void setDescription(QString arg)
    {
        if (m_description == arg)
            return;

        m_description = arg;
        emit descriptionChanged(arg);
    }

    void setColor(QColor arg)
    {
        if (m_color == arg)
            return;

        m_color = arg;
        emit colorChanged(arg);
    }

    void setSynchronised(bool arg)
    {
        if (m_synchronised == arg)
            return;

        m_synchronised = arg;
        emit synchronisedChanged(arg);
    }

signals:
    void nameChanged(QString arg);

    void descriptionChanged(QString arg);

    void colorChanged(QColor arg);

    void synchronisedChanged(bool arg);

private:
    /**
     * @brief Writes the Calendar to the given QDataStream
     * @param out Stream to write to
     */
    void serializeTo(QDataStream &out) const;

    /**
     * @brief Reads the Calendar to the given QDataStream
     * @param in Stream to read from
     */
    void serializeFrom(QDataStream &in);

    QUuid m_id;
    QString m_name;
    QString m_description;
    QColor m_color;
    bool m_synchronised;
    QList<Event*> m_events;
};

#endif // CALENDAR_H
