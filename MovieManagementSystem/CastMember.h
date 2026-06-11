#ifndef CASTMEMBER_H
#define CASTMEMBER_H

#include <string>
using namespace std;

class CastMember {
private:
    string name;
    string nationality;
    int cost;

public:
    CastMember();
    CastMember(string n, string nat, int c);

    void setName(string n);
    void setNationality(string nat);
    void setCost(int c);

    string getName() const;
    string getNationality() const;
    int getCost() const;

    void print() const;
};

#endif
