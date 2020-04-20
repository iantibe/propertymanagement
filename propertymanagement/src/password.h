#ifndef PASSWORD_H
#define PASSWORD_H

#include <string>
#include "user.h"
#include "selectdata.h"
#include "QSqlQuery"


using namespace std;

class Password {
public:
    void changePassword(string, string);
    bool validatePassword(string, string);
    Password();
private:
    bool checkForValidNewPassword(string);
};

#endif // PASSWORD_H
