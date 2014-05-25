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
    Account a;
    Calendar c;
    Event e;

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testObjectCreation();
    void testSerialization();
};

TestAccount::TestAccount()
{
}

void TestAccount::initTestCase()
{
    QFile outfile("outfile");
    outfile.remove();


    c.setProperty("name", "Test Cal");
    c.setProperty("description", "This is a test entry");
    e.setProperty("name", "Test Event");
    e.setProperty("description", "This is also a test entry");
    c.AddEvent(e);
}

void TestAccount::cleanupTestCase()
{
    //QFile outfile("outfile");
    //outfile.remove();
}

void TestAccount::testObjectCreation()
{
    QVERIFY2(c.property("name") == "Test Cal", "Name of Calendar not properly set");
    QVERIFY2(e.property("name") == "Test Event", "Name of Event not properly set");
    qDebug() << c.events().first()->name;
    QVERIFY2(c.events().first()->name == "Test Event", "Event not properly added");

}

void TestAccount::testSerialization()
{
    QFile outfile("outfile");
    if (!outfile.open(QIODevice::WriteOnly | QIODevice::Text))
            return;


    QDataStream out(&outfile);
    out << c;
    out.~QDataStream();
    outfile.close();

    if (!outfile.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    QDataStream in(&outfile);
    Calendar c2;
    in >> c2;
    QVERIFY2(c == c2, "Either Operator == fails or object ids are not the same");
    qDebug() << "First id" << c.id();
    qDebug() << "Second id" << c2.id();
    QCOMPARE(c2.property("id"), c.property("id"));
    QCOMPARE(c2.property("name").toString(), c.property("name").toString());
    QVERIFY2(c2.events().count() == c.events().count(), "Test event was not serialized or deserialized");
    QVERIFY2(c2.events().count() == 1, "No Event deserialized");
    QVERIFY2(c2.events().count() == 1, "Test event was not serialized or deserialized");
    qDebug() << "First Element id" << c.events().first()->id();
    qDebug() << "Second Element id" << c2.events().first()->id();
    qDebug() << "Event in Calendar name: " << c.events().first()->name;
    qDebug() << "Event in Calendar property name: " << c.events().first()->property("name");
    //Problem is that in this case ->name and ->property("name") are not the same, look at QProperties again
    QVERIFY2(c.events().first() == c2.events().first(), "Either Operator == fails or object ids are not the same");

}

QTEST_APPLESS_MAIN(TestAccount)

#include "tst_testaccount.moc"
