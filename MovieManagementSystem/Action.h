#ifndef ACTION_H
#define ACTION_H

#include "Movie.h"

class Action : public Movie {
private:
    int numberOfHeroes;
    static float bestRatedAction;

public:
    Action();
    Action(int heroes, int movieId, string n, float r, Date d,
           CastMember* cast, int castCount,
           ShootLocation* loc, int* locDays, int locCount);

    void setNumberOfHeroes(int heroes);
    int getNumberOfHeroes() const;

    static float getBestRatedAction();
    static void resetBestRatedAction();
    static void updateBestRatedAction(float rating);

    string getType() const;
    int calculateBudget() const;
    void print() const;
};

#endif
