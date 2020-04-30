#ifndef RENTALUNIT_H
#define RENTALUNIT_H

#include "building.h"

class Rentalunit {
private:
    Building building;
    string unitNumber;
public:
    Rentalunit(string, Building );
    Rentalunit(string, string ad, bool osl, bool osp, bool mf, int s, int o, int t, int th, bool rc);
    Building getBuilding();
    void setBuilding(Building);
    string getUnitnumber();
    void setUnitNumber(string);
};

#endif // RENTALUNIT_H


