#ifndef SHOOTLOCATION_H
#define SHOOTLOCATION_H

#include <string>
using namespace std;

class ShootLocation {
private:
    string name;
    string city;
    int costPerDay;

public:
    ShootLocation();
    ShootLocation(string n, string c, int cost);

    void setName(string n);
    void setCity(string c);
    void setCostPerDay(int cost);

    string getName() const;
    string getCity() const;
    int getCostPerDay() const;

    void print() const;
};

#endif
