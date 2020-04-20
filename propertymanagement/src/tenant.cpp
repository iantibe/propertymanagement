#include "tenant.h"

Tenant::Tenant(Tenantuser &u, Rentalunit &r, Building &b): user(u){

}

Tenantuser Tenant::getUser(){
    return user;
}

void Tenant::setUser(Tenantuser &u){
    user = u;
}

