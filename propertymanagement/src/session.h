#ifndef SESSION_H
#define SESSION_H

#include "user.h"
#include "Tenantuser.h"
#include "landlorduser.h"
#include "adminuser.h"
#include "rentaction.h"
#include "maintenancehandler.h"
#include "insertdata.h"
#include "selectdata.h"
#include "messagehandler.h"
#include "updatedata.h"
#include "messagemenu.h"
#include "adminmenu.h"
#include "landlordmenu.h"
#include "tenantmenu.h"
#include "message.h"
#include "rent.h"
#include "maintenancerequest.h"

class Session {
private:
    User currentUser;
public:
    void init_Session();
    Session(User &);
};

#endif // SESSION_H
