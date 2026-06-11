#include "Date.h"
#include <iostream>
using namespace std;

Date::Date() {
    day = 1;
    month = 1;
    year = 2000;
}

Date::Date(int d, int m, int y) {
    setDay(d);
    setMonth(m);
    setYear(y);
}

void Date::setDay(int d) {
    if (d >= 1 && d <= 31)
        day = d;
    else
        day = 1;
}

void Date::setMonth(int m) {
    if (m >= 1 && m <= 12)
        month = m;
    else
        month = 1;
}

void Date::setYear(int y) {
    if (y >= 1900)
        year = y;
    else
        year = 2000;
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

void Date::print() const {
    cout << day << "/" << month << "/" << year;
}
