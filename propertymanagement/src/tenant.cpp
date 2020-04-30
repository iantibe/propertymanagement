#include "tenant.h"

Tenant::Tenant( Tenantuser &u, Rentalunit r ): user(u), unit(r){

}

Tenantuser Tenant::getUser(){
    return user;
}

void Tenant::setUser(Tenantuser &u){
    user = u;
}

void Tenant::setRentalunit(Rentalunit &r){
    this->unit = r;
}

Rentalunit Tenant::getRentalunit(){
    return unit;
}

