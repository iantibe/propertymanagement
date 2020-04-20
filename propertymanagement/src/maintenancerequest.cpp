#include "maintenancerequest.h"

class Tenant Maintenancerequest::getTenant(){
    return this->tenant;
}

time_t Maintenancerequest::getTime(){
    return time;
}

Requesttype Maintenancerequest::getRequestType(){
    return this->request;
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

void Maintenancerequest::setRequestType(Requesttype rt){
    this->request = rt;
}

void Maintenancerequest::setDescription(string d){
    this->description = d;
}

Maintenancerequest::Maintenancerequest(class Tenant ten, time_t t, Requesttype rt, string des): tenant(ten){
    this->time = t;
    this->request = rt;
    this->description = des;
}
