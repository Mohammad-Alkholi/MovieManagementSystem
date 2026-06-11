#include "Action.h"
#include <iostream>
using namespace std;

float Action::bestRatedAction = 0;

Action::Action() : Movie() {
    numberOfHeroes = 0;
}

Action::Action(int heroes, int movieId, string n, float r, Date d,
               CastMember* cast, int castCount,
               ShootLocation* loc, int* locDays, int locCount)
    : Movie(movieId, n, r, d, cast, castCount, loc, locDays, locCount) {
    setNumberOfHeroes(heroes);

}

void Action::setNumberOfHeroes(int heroes) {
    if (heroes >= 0)
        numberOfHeroes = heroes;
    else
        numberOfHeroes = 0;
}

int Action::getNumberOfHeroes() const {
    return numberOfHeroes;
}

float Action::getBestRatedAction() {
    return bestRatedAction;
}

void Action::resetBestRatedAction() {
    bestRatedAction = 0;
}

void Action::updateBestRatedAction(float rating) {
    if (rating > bestRatedAction)
        bestRatedAction = rating;
}

string Action::getType() const {
    return "Action";
}

int Action::calculateBudget() const {
    int extraCost = 70000;
    int heroCost = numberOfHeroes * 10000;
    return calculateBasicBudget() + extraCost + heroCost;
}

void Action::print() const {
    Movie::print();
    cout << "Number of heroes: " << numberOfHeroes << endl;
    cout << "Total budget: " << calculateBudget() << endl;
}
