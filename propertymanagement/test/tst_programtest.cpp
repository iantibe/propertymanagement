#include <QtTest>
#include "Databaseconnection.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <iostream>


class programtest : public QObject
{
    Q_OBJECT

public:
    programtest();
    ~programtest();


private slots:
    void test_connection();


};

programtest::programtest()
{

}

programtest::~programtest()
{

}

void programtest::test_connection()
{
    //test if connection can be make with Databaseconnection class
   // Databaseconnection database;
    Databaseconnection database;
    database.openConnection();
    QVERIFY(database.checkConnectionOpen());

}


QTEST_APPLESS_MAIN(programtest)

#include "tst_programtest.moc"
