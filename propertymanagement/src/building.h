#ifndef BUILDING_H
#define BUILDING_H

#include <string>

using namespace std;

class Building {
private:
    string address;
    bool onSiteLaundry;
    bool offStreetParking;
    bool multiFamily;
    int studio;
    int oneBed;
    int twoBed;
    int threeBed;
    bool rentControlled;
public:
    int totalUnits();
    Building(string, bool, bool, bool, int, int, int, int, bool);
    void setAddress(string );
    void setOnSiteLaundry(bool);
    void setOffStreetParking(bool);
    void setMultiFamily(bool);
    void setStudio(int);
    void setOneBed(int);
    void setTwoBed(int);
    void setThreeBed(int);
    void setRentControlled(bool);
    string getAddress();
    bool getOnSiteLaundry();
    bool getOffStreetParking();
    bool getMultiFamily();
    int getStudio();
    int getOneBed();
    int getTwoBed();
    int getThreeBed();
    bool getRentControlled();

};

#endif // BUILDING_H
