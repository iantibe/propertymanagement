#ifndef LANDLORDUSER_H
#define LANDLORDUSER_H

#include "user.h"
#include <string>
#include "usertype.h"

class Landlorduser : User {
private:
    Usertype type;
public:
    Usertype getUsertype();
    Landlorduser(int, string, string);
};

#endif // LANDLORDUSER_H
