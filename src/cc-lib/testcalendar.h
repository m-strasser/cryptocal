#ifndef TESTCALENDAR_H
#define TESTCALENDAR_H

#include <QObject>
#include <QtTest>
#include "calendar.h"
#include "event.h"

class TestCalendar : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
};

#endif // TESTCALENDAR_H
