#include "Movie.h"
#include <iostream>
using namespace std;

Movie::Movie() {
    id = 0;
    name = "Unknown";
    rate = 0;
    releaseDate = Date();
    castMembers = NULL;
    numberOfCast = 0;
    locations = NULL;
    days = NULL;
    numberOfLocations = 0;
}

Movie::Movie(int movieId, string n, float r, Date d,
             CastMember* cast, int castCount,
             ShootLocation* loc, int* locDays, int locCount) {
    setId(movieId);
    setName(n);
    setRate(r);
    releaseDate = d;

    numberOfCast = castCount;
    if (numberOfCast > 0) {
        castMembers = new CastMember[numberOfCast];
        for (int i = 0; i < numberOfCast; i++)
            castMembers[i] = cast[i];
    }
    else {
        castMembers = NULL;
    }

    numberOfLocations = locCount;
    if (numberOfLocations > 0) {
        locations = new ShootLocation[numberOfLocations];
        days = new int[numberOfLocations];

        for (int i = 0; i < numberOfLocations; i++) {
            locations[i] = loc[i];
            days[i] = locDays[i];
        }
    }
    else {
        locations = NULL;
        days = NULL;
    }
}

Movie::Movie(const Movie& other) {
    id = other.id;
    name = other.name;
    rate = other.rate;
    releaseDate = other.releaseDate;

    numberOfCast = other.numberOfCast;
    if (numberOfCast > 0) {
        castMembers = new CastMember[numberOfCast];
        for (int i = 0; i < numberOfCast; i++)
            castMembers[i] = other.castMembers[i];
    }
    else {
        castMembers = NULL;
    }

    numberOfLocations = other.numberOfLocations;
    if (numberOfLocations > 0) {
        locations = new ShootLocation[numberOfLocations];
        days = new int[numberOfLocations];

        for (int i = 0; i < numberOfLocations; i++) {
            locations[i] = other.locations[i];
            days[i] = other.days[i];
        }
    }
    else {
        locations = NULL;
        days = NULL;
    }
}

Movie& Movie::operator=(const Movie& other) {
    if (this != &other) {
        delete[] castMembers;
        delete[] locations;
        delete[] days;

        id = other.id;
        name = other.name;
        rate = other.rate;
        releaseDate = other.releaseDate;

        numberOfCast = other.numberOfCast;
        if (numberOfCast > 0) {
            castMembers = new CastMember[numberOfCast];
            for (int i = 0; i < numberOfCast; i++)
                castMembers[i] = other.castMembers[i];
        }
        else {
            castMembers = NULL;
        }

        numberOfLocations = other.numberOfLocations;
        if (numberOfLocations > 0) {
            locations = new ShootLocation[numberOfLocations];
            days = new int[numberOfLocations];

            for (int i = 0; i < numberOfLocations; i++) {
                locations[i] = other.locations[i];
                days[i] = other.days[i];
            }
        }
        else {
            locations = NULL;
            days = NULL;
        }
    }

    return *this;
}

Movie::~Movie() {
    delete[] castMembers;
    delete[] locations;
    delete[] days;
}

void Movie::setId(int movieId) {
    if (movieId > 0)
        id = movieId;
    else
        id = 0;
}

void Movie::setName(string n) {
    name = n;
}

void Movie::setRate(float r) {
    if (r >= 0 && r <= 10)
        rate = r;
    else
        rate = 0;
}

void Movie::setReleaseDate(Date d) {
    releaseDate = d;
}

int Movie::getId() const {
    return id;
}

string Movie::getName() const {
    return name;
}

float Movie::getRate() const {
    return rate;
}

Date Movie::getReleaseDate() const {
    return releaseDate;
}

int Movie::calculateBasicBudget() const {
    int total = 0;

    for (int i = 0; i < numberOfCast; i++)
        total += castMembers[i].getCost();

    for (int i = 0; i < numberOfLocations; i++)
        total += locations[i].getCostPerDay() * days[i];

    return total;
}

void Movie::print() const {
    cout << "ID: " << id << endl;
    cout << "Type: " << getType() << endl;
    cout << "Movie name: " << name << endl;
    cout << "Rating: " << rate << endl;
    cout << "Release date: ";
    releaseDate.print();
    cout << endl;

    cout << "\nCast members:" << endl;
    if (numberOfCast == 0)
        cout << "No cast members entered." << endl;

    for (int i = 0; i < numberOfCast; i++) {
        cout << "Cast member " << i + 1 << endl;
        castMembers[i].print();
    }

    cout << "\nShoot locations:" << endl;
    if (numberOfLocations == 0)
        cout << "No locations entered." << endl;

    for (int i = 0; i < numberOfLocations; i++) {
        cout << "Location " << i + 1 << endl;
        locations[i].print();
        cout << "Number of days: " << days[i] << endl;
    }
}
