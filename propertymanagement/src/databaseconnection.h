#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QSqlDatabase>

class Databaseconnection {
public:
    void openConnection();
    void closeConnection();
    bool checkConnectionOpen();
    Databaseconnection();
    ~Databaseconnection();
private:
    QSqlDatabase db;
};

#endif // DATABASECONNECTION_H
