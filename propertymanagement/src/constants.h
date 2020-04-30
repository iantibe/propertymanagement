#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <array>
#include <QSqlDatabase>
#include <string>
#include <map>

using namespace std;

//Database constants

const QString DATABASENAME = "database";    //name of SQLite database
const QString DATABASEDRIVER = "QSQLITE";   //SQLite database driver name

//maintenance request constants

enum Requesttype {Pluming, Electrical, Finishes, Lighting, Flooring, Other};

//item to type to exit program

const string exitWord = "exit";

//landlord menu def

const array<string, 9> landlordlist {"Add Teant", "Remove Tenant","Add Building","View Maintenance Request","Update Maintenance Request","View Message","Send Message","Finance","Exit" };

//tenant menu def

const array<string, 7> tenantlist{"Pay Rent","View Rent Transactions","Maintenance Request", "View Maintenance Requests", "Send Message", "View Messasge","Exit"};

//admin menu def

const array<string,3> adminlist {"Display Error Log", "View Landlord Message user","Exit"};

//user landlord mail is send to

const string landlordMailUser = "landlorduser";

//generate month map

const array<string, 12> monthlist {"January", "Febuary","March", "April", "May","June","July","August", "September","October", "November", "December"};

#endif // CONSTANTS_H



