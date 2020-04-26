#include "Tenantuser.h"
#include "usertype.h"
#include "constants.h"

Usertype Tenantuser::getUsertype(){
    return type;
}

Tenantuser::Tenantuser(int id, string fnam, string lnam): User(id , fnam, lnam){
    type = Tenant;
}
