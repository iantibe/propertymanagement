#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QSqlDatabase>

using namespace std;

//Database constants

const QString DATABASENAME = "database";    //name of SQLite database
const QString DATABASEDRIVER = "QSQLITE";   //SQLite database driver name

//maintenance request constants

enum Requesttype {Pluming, Electrical, Finishes, Lighting, Flooring, Other};

//item to type to exit program

const string exitWord = "exit";

#endif // CONSTANTS_H
