#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include "Date.h"
#include "CastMember.h"
#include "ShootLocation.h"
using namespace std;

class Movie {
private:
    int id;
    string name;
    float rate;
    Date releaseDate;

    CastMember* castMembers;
    int numberOfCast;

    ShootLocation* locations;
    int* days;
    int numberOfLocations;

protected:
    int calculateBasicBudget() const;

public:
    Movie();
    Movie(int movieId, string n, float r, Date d,
          CastMember* cast, int castCount,
          ShootLocation* loc, int* locDays, int locCount);

    Movie(const Movie& other);
    Movie& operator=(const Movie& other);
    virtual ~Movie();

    void setId(int movieId);
    void setName(string n);
    void setRate(float r);
    void setReleaseDate(Date d);

    int getId() const;
    string getName() const;
    float getRate() const;
    Date getReleaseDate() const;

    virtual string getType() const = 0;
    virtual int calculateBudget() const = 0;
    virtual void print() const;
};

#endif
