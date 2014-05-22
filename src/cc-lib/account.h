#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QObject>
#include <QUuid>
#include <QList>
#include <iserializable.h>

class Account : public ISerializable

{
    Q_OBJECT
public:
    explicit Account(QObject *parent = 0);

    QUuid id() const;

    Q_PROPERTY(QUuid id READ id)
    Q_PROPERTY(QString name MEMBER m_name)
    Q_PROPERTY(QList<ISerializable*> items MEMBER m_items)
signals:

public slots:

private:
    QUuid m_id;
    QString m_name;
    QList<ISerializable*> m_items;
};

#endif // ACCOUNT_H
