#include <QString>
#include <QtTest>
#include "calendar.h"
#include "event.h"

class TestAccount : public QObject
{
    Q_OBJECT

public:
    TestAccount();
    Calendar c;
    Event e;

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testSerialization();
};

TestAccount::TestAccount()
{
}

void TestAccount::initTestCase()
{
    QFile outfile("outfile");
    outfile.remove();

    c.setProperty("name", "Test Calendar");
    c.setProperty("description", "This is a test entry");
    e.setProperty("name", "Test Event");
    e.setProperty("description", "This is also a test entry");
    c.AddEvent(e);
}

void TestAccount::cleanupTestCase()
{
}

void TestAccount::testSerialization()
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
    qDebug() << c2.property("id");
    QVERIFY2(c == c2, "Either Operator == fails or object ids are not the same");
    QCOMPARE(c2.property("id"), c.property("id"));
    QCOMPARE(c2.property("name").toString(), c.property("name").toString());
    QVERIFY2(c2.events().count() == c.events().count(), "Test event was not serialized or deserialized");
    QVERIFY2(c2.events().count() == 1, "Test event was not serialized or deserialized");
    QList<Event*> list = c.events();
    QList<Event*> list2 = c2.events();
    QVERIFY2(list.first() == list2.first(), "Events are not the same %s");
}

QTEST_APPLESS_MAIN(TestAccount)

#include "tst_testaccount.moc"
