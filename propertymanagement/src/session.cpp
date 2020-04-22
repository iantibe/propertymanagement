#include "session.h"
#include "constants.h"
#include "error.h"
#include <iostream>

using namespace std;

void Session::init_Session(){
    int usertype;

    Selectdata instance;

    try {
        usertype = instance.getUserType(currentUser);

        if(usertype == 1){
            Tenantmenu instance("Tenant Menu",currentUser);
            instance.display();
        }else if(usertype == 2){
            Landlordmenu instance("Landlord Menu");
            instance.display();
        }else if (usertype == 3){
            Adminmenu instance("Admin Menu");
            instance.display();
        }else {
            throw "Error. Unable to determine user type";
        }
    } catch (exception e) {
        Error error;
        error.addError(e.what());
        cout << e.what();
    }



}

Session::Session(User & user): currentUser(user){

}
