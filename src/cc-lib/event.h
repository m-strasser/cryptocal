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
    Q_PROPERTY(QString name MEMBER m_name)
    Q_PROPERTY(QString description MEMBER m_description)
    Q_PROPERTY(QDateTime start MEMBER m_start)
    Q_PROPERTY(QDateTime end MEMBER m_end)
    Q_PROPERTY(bool synchronised MEMBER m_repeats)
    Q_PROPERTY(QList<Event*> repeatedEvents READ GetRepeatedEvents)

public:
    explicit Event(QObject *parent = 0);

    QUuid id() const;

    QString name;
    QString description;
    QString location;
    QDateTime start;
    QDateTime end;

    // Functions
    int getId() const;

    // Functions for reoccuring events
    QList<Event*> GetRepeatedEvents();
    void AddRepeatedEvent(Event &e);
    void RemoveRepeatedEvent(Event &e);
    void RemoveAllRepeatedEvents();

    void serializeTo (QDataStream &out) const;

    friend QDataStream &operator>>(QDataStream &in, Event &e);
    /**
     * @brief operator == Compares the ID of two Events.
     * @param e2 Second Event.
     * @return True, if the two IDs are the same, else false.
     */
    bool operator ==(const Event &e2)const
    {
            return this->id()==e2.id();
    }

    private:
        QUuid m_id;
        QString m_name;
        QString m_description;
        QDateTime m_start;
        QDateTime m_end;
        bool m_repeats;
        QList<Event*> repeatedIterations;
};

#endif // EVENT_H
