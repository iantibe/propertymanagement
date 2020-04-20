#ifndef LOGINOUT_H
#define LOGINOUT_H

#include "password.h"
#include "user.h"
#include "loginscreen.h"
#include "loginscreen.h"
#include "logoutscreen.h"

class Loginout {
private:
    Password password;
public:
    Loginout();
    User init_Loginout();
};

#endif // LOGINOUT_H
