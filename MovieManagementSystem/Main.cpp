#include <iostream>
#include <string>
#include <limits>
#include "MovieManager.h"
#include "Action.h"
#include "SciFi.h"
using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string readLine(string message) {
    string value;
    cout << message;
    getline(cin, value);
    return value;
}

int readInt(string message) {
    int value;

    while (true) {
        cout << message;
        cin >> value;

        if (!cin.fail()) {
            clearInput();
            return value;
        }

        cout << "Invalid number. Try again." << endl;
        clearInput();
    }
}

float readFloat(string message) {
    float value;

    while (true) {
        cout << message;
        cin >> value;

        if (!cin.fail()) {
            clearInput();
            return value;
        }

        cout << "Invalid number. Try again." << endl;
        clearInput();
    }
}

Date inputDate() {
    int day, month, year;

    cout << "\nEnter release date" << endl;
    day = readInt("Day: ");
    month = readInt("Month: ");
    year = readInt("Year: ");

    return Date(day, month, year);
}

CastMember* inputCastMembers(int& count) {
    count = readInt("Number of cast members: ");

    if (count <= 0) {
        count = 0;
        return NULL;
    }

    CastMember* cast = new CastMember[count];

    for (int i = 0; i < count; i++) {
        cout << "\nCast member " << i + 1 << endl;
        string name = readLine("Name: ");
        string nationality = readLine("Nationality: ");
        int cost = readInt("Cost: ");

        cast[i] = CastMember(name, nationality, cost);
    }

    return cast;
}

void inputLocations(ShootLocation*& locations, int*& days, int& count) {
    count = readInt("Number of shoot locations: ");

    if (count <= 0) {
        count = 0;
        locations = NULL;
        days = NULL;
        return;
    }

    locations = new ShootLocation[count];
    days = new int[count];

    for (int i = 0; i < count; i++) {
        cout << "\nShoot location " << i + 1 << endl;
        string name = readLine("Location name: ");
        string city = readLine("City: ");
        int costPerDay = readInt("Cost per day: ");
        int numberOfDays = readInt("Number of days: ");

        locations[i] = ShootLocation(name, city, costPerDay);
        days[i] = numberOfDays;
    }
}

Movie* createActionMovie() {
    cout << "\n--- Add Action Movie ---" << endl;

    int id = readInt("Movie ID: ");
    string name = readLine("Movie name: ");
    float rate = readFloat("Rating from 0 to 10: ");
    Date date = inputDate();
    int heroes = readInt("Number of heroes: ");

    int castCount;
    CastMember* cast = inputCastMembers(castCount);

    int locationCount;
    ShootLocation* locations;
    int* days;
    inputLocations(locations, days, locationCount);

    Movie* movie = new Action(heroes, id, name, rate, date, cast, castCount, locations, days, locationCount);

    delete[] cast;
    delete[] locations;
    delete[] days;

    return movie;
}

Movie* createSciFiMovie() {
    cout << "\n--- Add Sci-Fi Movie ---" << endl;

    int id = readInt("Movie ID: ");
    string name = readLine("Movie name: ");
    float rate = readFloat("Rating from 0 to 10: ");
    Date date = inputDate();
    string brief = readLine("Short brief: ");
    int bookAnswer = readInt("Based on a book? 1 = Yes, 0 = No: ");
    bool fromBook = (bookAnswer == 1);

    int castCount;
    CastMember* cast = inputCastMembers(castCount);

    int locationCount;
    ShootLocation* locations;
    int* days;
    inputLocations(locations, days, locationCount);

    Movie* movie = new SciFi(fromBook, brief, id, name, rate, date, cast, castCount, locations, days, locationCount);

    delete[] cast;
    delete[] locations;
    delete[] days;

    return movie;
}

void addMovieMenu(MovieManager& manager) {
    cout << "\nChoose movie type" << endl;
    cout << "1. Action" << endl;
    cout << "2. Sci-Fi" << endl;

    int choice = readInt("Choice: ");

    Movie* movie = NULL;

    if (choice == 1)
        movie = createActionMovie();
    else if (choice == 2)
        movie = createSciFiMovie();
    else {
        cout << "Wrong choice." << endl;
        return;
    }

    if (manager.addMovie(movie))
        cout << "Movie added successfully." << endl;
    else {
        cout << "Movie was not added. ID may be invalid or already used." << endl;
        delete movie;
    }
}

void searchMovieByIdMenu(const MovieManager& manager) {
    int id = readInt("Enter movie ID: ");
    Movie* movie = manager.searchById(id);

    if (movie == NULL)
        cout << "Movie was not found." << endl;
    else {
        cout << "\nMovie found:" << endl;
        movie->print();
    }
}

void searchMovieByNameMenu(const MovieManager& manager) {
    string name = readLine("Enter exact movie name: ");
    int index = manager.searchByName(name);

    if (index == -1)
        cout << "Movie was not found." << endl;
    else
        cout << "Movie found at position " << index + 1 << "." << endl;
}

void deleteMovieByIdMenu(MovieManager& manager) {
    int id = readInt("Enter movie ID to delete: ");

    if (manager.deleteMovieById(id))
        cout << "Movie deleted successfully." << endl;
    else
        cout << "Movie was not found." << endl;
}

int main() {
    MovieManager manager;
    int choice;

    do {
        cout << "\n========== Movie Management System ==========" << endl;
        cout << "1. Add movie" << endl;
        cout << "2. Show all movies" << endl;
        cout << "3. Search movie by ID" << endl;
        cout << "4. Search movie by name" << endl;
        cout << "5. Delete movie by ID" << endl;
        cout << "6. Sort movies by rating" << endl;
        cout << "7. Show movie budgets" << endl;
        cout << "8. Show top rated movie" << endl;
        cout << "9. Show best Action rating" << endl;
        cout << "10. Exit" << endl;

        choice = readInt("Choice: ");

        switch (choice) {
        case 1:
            addMovieMenu(manager);
            break;
        case 2:
            manager.printAllMovies();
            break;
        case 3:
            searchMovieByIdMenu(manager);
            break;
        case 4:
            searchMovieByNameMenu(manager);
            break;
        case 5:
            deleteMovieByIdMenu(manager);
            break;
        case 6:
            manager.sortByRating();
            cout << "Movies sorted by rating using merge sort." << endl;
            break;
        case 7:
            manager.printBudgets();
            break;
        case 8:
            manager.showTopRatedMovie();
            break;
        case 9:
            cout << "Best Action movie rating: " << Action::getBestRatedAction() << endl;
            break;
        case 10:
            cout << "Program finished." << endl;
            break;
        default:
            cout << "Wrong choice." << endl;
        }

    } while (choice != 10);

    return 0;
}
