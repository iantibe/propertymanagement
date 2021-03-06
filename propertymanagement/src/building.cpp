#include "building.h"

Building::Building(string ad, int osl, int osp, int mf, int s, int o, int t, int th, int rc){
    this->address = ad;
    this->onSiteLaundry = osl;
    this->offStreetParking = osp;
    this->multiFamily = mf;
    this->studio = s;
    this->oneBed = o;
    this->twoBed = t;
    this->threeBed = th;
    this->rentControlled = rc;
}

int Building::totalUnits(){
return oneBed + twoBed + threeBed + studio;
}

void Building::setAddress(string ad ){
    this->address = ad;
}

void Building::setOnSiteLaundry(bool l){
    this->onSiteLaundry = l;
}

void Building::setOffStreetParking(bool p){
    this->offStreetParking = p;
}

void Building::setMultiFamily(bool m){
    this->multiFamily = m;
}

void Building::setStudio(int s){
    this->studio = s;
}

void Building::setOneBed(int ob){
    this->oneBed = ob;
}

void Building::setTwoBed(int tb){
    this->twoBed = tb;
}
void Building::setThreeBed(int thb){
    this->threeBed = thb;
}

void Building::setRentControlled(bool rc){
    this->rentControlled = rc;
}

string Building::getAddress(){
    return address;
}

int Building::getOnSiteLaundry(){
    return onSiteLaundry;
}

int Building::getOffStreetParking(){
    return offStreetParking;
}

int Building::getMultiFamily(){
    return multiFamily;
}

int Building::getStudio(){
    return studio;
}

int Building::getOneBed(){
    return oneBed;
}

int Building::getTwoBed(){
    return twoBed;
}

int Building::getThreeBed(){
    return threeBed;
}

int Building::getRentControlled(){
    return rentControlled;
}

void Building::setBuildingId(int id){
    this->buildingID = id;
}

int Building::getBuildingId(){
    return buildingID;
}
