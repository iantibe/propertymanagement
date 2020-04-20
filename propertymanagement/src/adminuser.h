#ifndef ADMINUSER_H
#define ADMINUSER_H

#include "user.h"
#include "usertype.h"

class Adminuser : User {
private:
    Usertype type;
public:
    Usertype getUserType();
    Adminuser(int, string, string);
};

#endif // ADMINUSER_H
