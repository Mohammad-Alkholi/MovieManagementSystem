#include "CastMember.h"
#include <iostream>
using namespace std;

CastMember::CastMember() {
    name = "Unknown";
    nationality = "Unknown";
    cost = 0;
}

CastMember::CastMember(string n, string nat, int c) {
    setName(n);
    setNationality(nat);
    setCost(c);
}

void CastMember::setName(string n) {
    name = n;
}

void CastMember::setNationality(string nat) {
    nationality = nat;
}

void CastMember::setCost(int c) {
    if (c >= 0)
        cost = c;
    else
        cost = 0;
}

string CastMember::getName() const {
    return name;
}

string CastMember::getNationality() const {
    return nationality;
}

int CastMember::getCost() const {
    return cost;
}

void CastMember::print() const {
    cout << "Name: " << name << endl;
    cout << "Nationality: " << nationality << endl;
    cout << "Cost: " << cost << endl;
}
