#include <QString>
#include <QtTest>
#include "calendar.h"
#include "event.h"

class TestCalendar : public QObject
{
    Q_OBJECT

public:
    TestCalendar();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
};

TestCalendar::TestCalendar()
{
}

void TestCalendar::initTestCase()
{
    Calendar c;
    c.setProperty("name", "First Calendar");
}

void TestCalendar::cleanupTestCase()
{
}

void TestCalendar::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TestCalendar)

#include "tst_testcalendar.moc"
