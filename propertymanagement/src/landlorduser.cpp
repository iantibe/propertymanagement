#include "landlorduser.h"
#include "usertype.h"

Usertype Landlorduser::getUsertype(){
    return type;
}

Landlorduser::Landlorduser(int id, string fnam, string lnam): User(id, fnam, lnam){
    type = Landlord;
}
