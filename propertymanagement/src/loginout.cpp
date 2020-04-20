#include "loginout.h"
#include "iostream"
#include "constants.h"
#include "Tenantuser.h"


Loginout::Loginout(){

}

User Loginout::init_Loginout() {
    //be sure to return a user object with userid zero for exiting program
    string user;
    string passwordToTest;
    Loginscreen loginscreen;
    bool exitFlag = false;

    while(!exitFlag){
        loginscreen.displayScreen();
        cout << "User name: ";
        cin >> user;

        if(user == exitWord){
        User exitUser(0,"null","null");
            return exitUser;
        }else{
            cout << "password: ";
            cin >> passwordToTest;

            if(password.validatePassword(user,passwordToTest)){
                //figure out user type and create valid user object to return
                cout << "it worked!";
                exitFlag = true;


            }else {
                cout << "Invalid Username or Password" << endl;
            }
        }



  }


}
