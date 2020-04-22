#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>


class Databaseconnection {
public:
    void openConnection();
    void closeConnection();
    bool checkConnectionOpen();
    Databaseconnection();
    ~Databaseconnection();
    QSqlDatabase db;
private:

    void createDatabase();
};

#endif // DATABASECONNECTION_H
