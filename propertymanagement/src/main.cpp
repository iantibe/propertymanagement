#include <QCoreApplication>

using namespace std;

#include "loginout.h"
#include "session.h"
#include "iostream"
#include "Databaseconnection.h"

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    bool exitFlag = false;

    Databaseconnection connection;
    Loginout loginout;

    connection.openConnection();

    while(!exitFlag){
        User u = loginout.init_Loginout();
       if(!(u.getUserid() == 0)){
            Session session(u);
            session.init_Session();
        }else{
           exitFlag = true;
        }
    }
    cout << "Programming ending...Goodbye!!" << endl;

    //return a.exec();
    connection.closeConnection();
    return 0;
}
