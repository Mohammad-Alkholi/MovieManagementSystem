#include "ShootLocation.h"
#include <iostream>
using namespace std;

ShootLocation::ShootLocation() {
    name = "Unknown";
    city = "Unknown";
    costPerDay = 0;
}

ShootLocation::ShootLocation(string n, string c, int cost) {
    setName(n);
    setCity(c);
    setCostPerDay(cost);
}

void ShootLocation::setName(string n) {
    name = n;
}

void ShootLocation::setCity(string c) {
    city = c;
}

void ShootLocation::setCostPerDay(int cost) {
    if (cost >= 0)
        costPerDay = cost;
    else
        costPerDay = 0;
}

string ShootLocation::getName() const {
    return name;
}

string ShootLocation::getCity() const {
    return city;
}

int ShootLocation::getCostPerDay() const {
    return costPerDay;
}

void ShootLocation::print() const {
    cout << "Location name: " << name << endl;
    cout << "City: " << city << endl;
    cout << "Cost per day: " << costPerDay << endl;
}
