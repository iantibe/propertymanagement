#ifndef BUILDING_H
#define BUILDING_H

#include <string>

using namespace std;

class Building {
private:
    string address;
    int onSiteLaundry;
    int offStreetParking;
    int multiFamily;
    int studio;
    int oneBed;
    int twoBed;
    int threeBed;
    int rentControlled;
    int buildingID;
public:
    int totalUnits();
    Building(string, int, int, int, int, int, int, int, int);
    void setAddress(string );
    void setOnSiteLaundry(bool);
    void setOffStreetParking(bool);
    void setMultiFamily(bool);
    void setStudio(int);
    void setOneBed(int);
    void setTwoBed(int);
    void setThreeBed(int);
    void setRentControlled(bool);
    void setBuildingId(int);
    string getAddress();
    int getOnSiteLaundry();
    int getOffStreetParking();
    int getMultiFamily();
    int getStudio();
    int getOneBed();
    int getTwoBed();
    int getThreeBed();
    int getRentControlled();
    int getBuildingId();


};

#endif // BUILDING_H
