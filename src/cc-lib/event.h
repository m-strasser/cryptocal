#ifndef EVENT_H
#define EVENT_H

#include <QObject>
#include <QUuid>
#include <QDateTime>
#include <QList>
#include <QVariant>

#include "iserializable.h"

class Event: public ISerializable
{
    Q_OBJECT
    Q_PROPERTY(QUuid id READ id)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString description READ description WRITE setDescription)
    Q_PROPERTY(QDateTime start READ start WRITE setStart)
    Q_PROPERTY(QDateTime end READ end WRITE setEnd)
    Q_PROPERTY(QString location READ location WRITE setLocation)
    Q_PROPERTY(bool synchronised READ repeats WRITE setRepeats)
    Q_PROPERTY(QList<Event*> repeatedEvents READ repeatedEvents)

public:
    explicit Event(QObject *parent = 0);

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

    QDateTime start() const
    {
        return m_start;
    }

    QDateTime end() const
    {
        return m_end;
    }

    QString location() const
    {
        return m_location;
    }

    bool repeats() const
    {
        return m_synchronised;
    }

    QList<Event*> repeatedEvents() const
    {
        return m_repeatedEvents;
    }

    // Functions for reoccuring events
    void AddRepeatedEvent(Event &e);
    void RemoveRepeatedEvent(Event &e);
    void RemoveAllRepeatedEvents();

    void serializeTo (QDataStream &out) const;
    void serializeFrom(QDataStream &in);

    /**
     * @brief operator == Compares the ID of two Events.
     * @param event Second Event.
     * @return True, if the two IDs are the same, else false.
     */
    bool operator ==(const Event &event)const
    {
            return this->id()==event.id();
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

    void setStart(QDateTime arg)
    {
        m_start = arg;
    }

    void setEnd(QDateTime arg)
    {
        m_end = arg;
    }

    void setLocation(QString arg)
    {
        m_location = arg;
    }

    void setRepeats(bool arg)
    {
        m_synchronised = arg;
    }

signals:

private:
        QUuid m_id;
        QString m_name;
        QString m_description;
        QDateTime m_start;
        QDateTime m_end;
        bool m_repeats;
        bool m_synchronised;
        QList<Event*> m_repeatedEvents;
        QString m_location;
};

#endif // EVENT_H
