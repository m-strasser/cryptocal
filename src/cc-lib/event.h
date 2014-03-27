#ifndef EVENT_H
#define EVENT_H

#include <QObject>
#include <QDateTime>
#include <QList>

class Event: public QObject
{
    Q_OBJECT
public:
    Event();

    QString name;
    QString description;
    QString location;
    QDateTime start;
    QDateTime end;
    QBool repeats;

    // Functions
    int getId() const;

    // Functions for reoccuring events
    QList<Event> GetRepeatedEvents();
    void AddRepeatedEvent(Event &e);
    void RemoveRepeatedEvent(Event &e);
    void RemoveAllRepeatedEvents();

    /**
     * @brief operator == Compares the ID of two Events.
     * @param e2 Second Event.
     * @return True, if the two IDs are the same, else false.
     */
    bool operator ==(const Event &e2)const
    {
            return getId()==e2.getId();
    }
    // TODO: Operator overloading for serialization

    private:
        long id;
        QList<Event> repeatedIterations;
};

#endif // EVENT_H
