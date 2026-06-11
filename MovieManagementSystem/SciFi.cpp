#include "SciFi.h"
#include <iostream>
using namespace std;

SciFi::SciFi() : Movie() {
    fromBook = false;
    brief = "No brief";
}

SciFi::SciFi(bool book, string br, int movieId, string n, float r, Date d,
             CastMember* cast, int castCount,
             ShootLocation* loc, int* locDays, int locCount)
    : Movie(movieId, n, r, d, cast, castCount, loc, locDays, locCount) {
    fromBook = book;
    brief = br;
}

void SciFi::setFromBook(bool book) {
    fromBook = book;
}

void SciFi::setBrief(string br) {
    brief = br;
}

bool SciFi::getFromBook() const {
    return fromBook;
}

string SciFi::getBrief() const {
    return brief;
}

string SciFi::getType() const {
    return "Sci-Fi";
}

int SciFi::calculateBudget() const {
    int extraCost = 90000;

    if (fromBook)
        extraCost += 20000;

    return calculateBasicBudget() + extraCost;
}

void SciFi::print() const {
    Movie::print();
    cout << "Brief: " << brief << endl;
    cout << "Based on book: " << (fromBook ? "Yes" : "No") << endl;
    cout << "Total budget: " << calculateBudget() << endl;
}
