#include <QString>
#include <QtTest>
#include "account.h"
#include "calendar.h"
#include "event.h"
#include "localstoragemanager.h"


class TestAccount : public QObject
{
    Q_OBJECT

public:
    TestAccount();
    QFile outfile;
    Account a;
    Calendar c;
    Event e;
    LocalStorageManager lsm;

private Q_SLOTS:
    void cleanup();
    void initTestCase();
    void cleanupTestCase();
    void testObjectCreation();
    void testAccountSerialization();
    void testCalendarSerialization();
    void testEventSerialization();
    void testWholeSerialization();
    void testLocalStorageManager();
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
    a.AddISerializable(c);

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

    //Test == Operator
    QCOMPARE(a2.property("id"), a.property("id"));
    QVERIFY2(a == a2, "Either Operator == fails or object ids are not the same");

    //Test if accounts are the same
    QCOMPARE(a2.property("name").toString(), a.property("name").toString());
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
    QCOMPARE(*(e.repeatedEvents().first()), *(e2.repeatedEvents().first()));
    QCOMPARE((*(e.repeatedEvents().first())).name(), (*(e2.repeatedEvents().first())).name());
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
    ISerializable* pi2 = a2.items().first();
    Calendar* pc2 = qobject_cast<Calendar*>(pi2);
    Event* pe2 = qobject_cast<Event*>(pc2->events().first());

    QVERIFY2(e == *pe2, "Either Operator == fails or object ids are not the same");
    QCOMPARE(c.events().first()->name(), pc2->events().first()->name());


}

void TestAccount::testLocalStorageManager()
{
    lsm.SaveFiles(a, outfile);
    Account* a2;
    a2 = lsm.LoadFiles(outfile);

    //Test if deserialized Objects are the same
    QVERIFY2(a == *a2, "Either Operator == fails or object ids are not the same");
    Calendar* c2 = qobject_cast<Calendar*>(a2->items().first());
    QVERIFY2(c == *c2, "Either Operator == fails or object ids are not the same");
}

QTEST_APPLESS_MAIN(TestAccount)

#include "tst_testaccount.moc"
