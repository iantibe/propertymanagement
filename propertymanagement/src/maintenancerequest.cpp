#include "maintenancerequest.h"

class Tenant Maintenancerequest::getTenant(){
    return this->tenant;
}

time_t Maintenancerequest::getTime(){
    return time;
}

int Maintenancerequest::getRequestType(){
    return this->requesttype;
}

string Maintenancerequest::getDescription(){
    return description;
}

void Maintenancerequest::setTenant(class Tenant & ten){
    this->tenant = ten;
}

void Maintenancerequest::setTime(time_t t){
    this->time = t;
}

void Maintenancerequest::setRequestType(int rt){
    this->requesttype = rt;
}

void Maintenancerequest::setDescription(string d){
    this->description = d;
}

Maintenancerequest::Maintenancerequest(class Tenant ten, time_t t, int rt, string des): tenant(ten){
    this->time = t;
    this->requesttype = rt;
    this->description = des;
    maintenancerequestid = 0;
}

int Maintenancerequest::getMaintenancerequestid(){
    return maintenancerequestid;
}

void Maintenancerequest::setMaintenancerequestid(int id){
    this->maintenancerequestid = id;
}
