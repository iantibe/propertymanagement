#ifndef PASSWORD_H
#define PASSWORD_H

#include <string>
#include "user.h"
#include "selectdata.h"
#include "QSqlQuery"


using namespace std;

class Password {
public:
    bool validatePassword(string, string);
    Password();
};

#endif // PASSWORD_H
