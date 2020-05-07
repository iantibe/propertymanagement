#include "loginout.h"
#include "iostream"
#include "constants.h"
#include "Tenantuser.h"

Loginout::Loginout(){

}

User Loginout::init_Loginout() {
    string user;
    string passwordToTest;
    Loginscreen loginscreen;
    bool exitFlag = false;
    User outputUser(0,"null","null");

    while(!exitFlag){
        loginscreen.displayScreen();
        cout << "User name: ";
        cin >> user;

        if(user == exitWord){
        exitFlag = true;

        }else{
            cout << "password: ";
            cin >> passwordToTest;

            if(password.validatePassword(user,passwordToTest)){
                Selectdata instance;
                User validUser(instance.getUserbyScreenName(user));
                outputUser = validUser;
                exitFlag = true;
            }else {
                cout << "Invalid Username or Password" << endl;
            }
        }
  }

   return outputUser;
}
