#include "adminuser.h"
#include "usertype.h"

Usertype Adminuser::getUserType(){
    return type;
}

Adminuser::Adminuser(int id, string fnam, string lnam): User(id, fnam, lnam){
    type = Admin;

}
