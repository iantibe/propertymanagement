#include "session.h"
#include "constants.h"
#include "errorhandler.h"
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
            throw domain_error("Unable to determine menu for user");
        }
    } catch (exception e) {
        Errorhandler errorhandler;
        errorhandler.saveError(e.what());
        cout << "An Error has occured. IT has been notified";
    }



}

Session::Session(User & user): currentUser(user){

}
