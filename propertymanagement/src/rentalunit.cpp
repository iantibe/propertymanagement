#include "rentalunit.h"

Rentalunit::Rentalunit(string un, string ad, bool osl, bool osp, bool mf, int s, int o, int t, int th, bool rc) : building(ad, osl, osp, mf, s, o, t, th, rc){
    unitNumber = un;
    building.setOnSiteLaundry(osl);
    building.setAddress(ad);
    building.setOffStreetParking(osp);
    building.setMultiFamily(mf);
    building.setStudio(s);
    building.setOneBed(o);
    building.setTwoBed(t);
    building.setThreeBed(th);
    building.setRentControlled(rc);
}

Rentalunit::Rentalunit(string number, Building & b):building(b){
        this->unitNumber = number;
}




