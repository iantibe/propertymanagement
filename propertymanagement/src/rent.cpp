#include "rent.h"
#include "Tenantuser.h"

Rent::Rent(Tenantuser & t, float rent, string month):user(t){
    this->rent = rent;
    this->month = month;
}

void Rent::setTenant(Tenantuser & u){
    this->user = u;
    }

void Rent::setRent(float r){
    this->rent = r;
}

Tenantuser Rent::getTenant(){
    return user;
}

float Rent::getRent(){
    return rent;
}

string Rent::getMonth(){
    return month;
}

void Rent::setMonth(string mon){
    this->month = mon;
}
