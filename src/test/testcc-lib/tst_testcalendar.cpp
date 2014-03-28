#include <QString>
#include <QtTest>
#include "calendar.h"
#include "event.h"

class TestCalendar : public QObject
{
    Q_OBJECT

public:
    TestCalendar();
    Calendar c;

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testSerialization();
};

TestCalendar::TestCalendar()
{
}

void TestCalendar::initTestCase()
{
    c.setProperty("name", "Test Calendar");
    c.setProperty("description", "This is e test entry");
}

void TestCalendar::cleanupTestCase()
{
    QFile outfile("outfile");
    outfile.remove();
}

void TestCalendar::testSerialization()
{
    QFile outfile("outfile");
    if (!outfile.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

    QDataStream out(&outfile);
    out << c;
    out.~QDataStream();

    if (!outfile.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    QDataStream in(&outfile);
    Calendar c2;
    in >> c2;
    QString want = c.property("name").toString();
    QCOMPARE(c2.property("name").toString(), want);
}

QTEST_APPLESS_MAIN(TestCalendar)

#include "tst_testcalendar.moc"
