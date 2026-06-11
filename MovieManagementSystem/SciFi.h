#ifndef SCIFI_H
#define SCIFI_H

#include "Movie.h"

class SciFi : public Movie {
private:
    bool fromBook;
    string brief;

public:
    SciFi();
    SciFi(bool book, string br, int movieId, string n, float r, Date d,
          CastMember* cast, int castCount,
          ShootLocation* loc, int* locDays, int locCount);

    void setFromBook(bool book);
    void setBrief(string br);

    bool getFromBook() const;
    string getBrief() const;

    string getType() const;
    int calculateBudget() const;
    void print() const;
};

#endif
