#include <QString>
#include <QtTest>
#include "account.h"
#include "calendar.h"
#include "event.h"


class TestAccount : public QObject
{
    Q_OBJECT

public:
    TestAccount();
    QFile outfile;
    Account a;
    Calendar c;
    Event e;

private Q_SLOTS:
    void cleanup();
    void initTestCase();
    void cleanupTestCase();
    void testObjectCreation();
    void testAccountSerialization();
    void testCalendarSerialization();
    void testEventSerialization();
    void testWholeSerialization();
};

TestAccount::TestAccount()
{
}

void TestAccount::cleanup()
{
    outfile.remove();
}

void TestAccount::initTestCase()
{
    outfile.setFileName("outfile");
    outfile.remove();

    a.setName("Test Account");
    c.setName("Test Cal");
    c.setDescription("This is a test entry");
    e.setName("Test Event");
    e.setDescription("This is also a test entry");
    c.AddEvent(e);
    QList<ISerializable*> tmp;
    tmp = a.items();
    tmp.append(&c);
    a.setItems(tmp);

}


void TestAccount::cleanupTestCase()
{
    outfile.remove();
}

void TestAccount::testObjectCreation()
{
    //Test object properties
    QVERIFY(c.name() == "Test Cal");
    QVERIFY2(c.property("name") == "Test Cal", "Name of Calendar not properly set");
    QVERIFY2(e.property("name") == "Test Event", "Name of Event not properly set");
    QVERIFY2(c.events().first()->property("name") == "Test Event", "Event not properly added");

}

void TestAccount::testAccountSerialization()
{

}

void TestAccount::testCalendarSerialization()
{
    //Serialize objects
    if (!outfile.open(QIODevice::WriteOnly))
            return;

    QDataStream out(&outfile);
    out << c;
    out.~QDataStream();
    outfile.close();

    //Deserialize objects
    if (!outfile.open(QIODevice::ReadOnly))
            return;
    QDataStream in(&outfile);
    Calendar c2;
    in >> c2;
    in.~QDataStream();
    outfile.close();

    //Test == Operator
    QCOMPARE(c2.property("id"), c.property("id"));
    QVERIFY2(c == c2, "Either Operator == fails or object ids are not the same");

    //Test if calendars are the same
    QCOMPARE(c2.property("name").toString(), c.property("name").toString());
    QVERIFY2(c2.events().count() == c.events().count(), "Test event was not serialized or deserialized");
    QVERIFY2(c2.events().count() == 1, "No Event deserialized");
    QVERIFY2(c2.events().count() == 1, "Test event was not serialized or deserialized");
}

void TestAccount::testEventSerialization()
{
    //Serialize objects
    if (!outfile.open(QIODevice::WriteOnly))
            return;

    QDataStream out(&outfile);
    out << e;
    out.~QDataStream();
    outfile.close();

    //Deserialize objects
    if (!outfile.open(QIODevice::ReadOnly))
            return;
    QDataStream in(&outfile);
    Event e2;
    in >> e2;
    in.~QDataStream();
    outfile.close();

    //Test == Operator
    QCOMPARE(e2.property("id"), e.property("id"));
    QVERIFY2(e == e2, "Either Operator == fails or object ids are not the same");

    //Test if events are the same
    QCOMPARE(e2.property("name").toString(), e.property("name").toString());
    QVERIFY2(e2.repeatedEvents().count() == e.repeatedEvents().count(), "Test event was not serialized or deserialized");
    QVERIFY2(e2.repeatedEvents().count() == 1, "No Event deserialized");
    QVERIFY2(e2.repeatedEvents().count() == 1, "Test event was not serialized or deserialized");
}

void TestAccount::testWholeSerialization()
{
    //Serialize objects
    if (!outfile.open(QIODevice::WriteOnly))
            return;

    QDataStream out(&outfile);
    out << a;
    out.~QDataStream();
    outfile.close();

    //Deserialize objects
    if (!outfile.open(QIODevice::ReadOnly))
            return;
    QDataStream in(&outfile);
    Account a2;
    in >> a2;
    in.~QDataStream();
    outfile.close();


    //Test if events in calendars in account are the same


    ISerializable* pi = a.items().first();
    ISerializable* pi2 = a2.items().first();
    qDebug() << "Original id" << e.id();
    Calendar* pc = qobject_cast<Calendar*>(pi);
    Calendar* pc2 = qobject_cast<Calendar*>(pi2);
    Event* pe = qobject_cast<Event*>(pc->events().first());
    Event* pe2 = qobject_cast<Event*>(pc2->events().first());

    qDebug() << "First Element id" << pe->id();
    qDebug() << "Second Element id" << pe2->id();
    QVERIFY2(*(pc->events().first()) == *(pc2->events().first()), "Either Operator == fails or object ids are not the same");
    qDebug() << "Event in Calendar name: " << pc->events().first()->name();
    qDebug() << "Event in Calendar2 name: " << pc2->events().first()->name();
    //QVERIFY2(c.events().first()->name() == c2.events().first()->name(), "Names are not the same");


}

QTEST_APPLESS_MAIN(TestAccount)

#include "tst_testaccount.moc"
