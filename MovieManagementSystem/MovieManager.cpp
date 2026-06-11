#include "MovieManager.h"
#include "Action.h"
#include <iostream>
using namespace std;

struct CompareMovieRating {
    bool operator()(Movie* first, Movie* second) {
        return first->getRate() < second->getRate();
    }
};

MovieManager::MovieManager() {
}

MovieManager::~MovieManager() {
    for (int i = 0; i < (int)movies.size(); i++)
        delete movies[i];

    movies.clear();
    movieById.clear();
}


void MovieManager::updateBestActionRating() {
    Action::resetBestRatedAction();

    for (int i = 0; i < (int)movies.size(); i++) {
        Action* actionMovie = dynamic_cast<Action*>(movies[i]);

        if (actionMovie != NULL)
            Action::updateBestRatedAction(actionMovie->getRate());
    }
}

bool MovieManager::addMovie(Movie* movie) {
    if (movie == NULL)
        return false;

    int id = movie->getId();

    if (id <= 0)
        return false;

    if (movieById.find(id) != movieById.end())
        return false;

    movies.push_back(movie);
    movieById[id] = movie;
    updateBestActionRating();
    return true;
}

Movie* MovieManager::searchById(int id) const {
    unordered_map<int, Movie*>::const_iterator it = movieById.find(id);

    if (it != movieById.end())
        return it->second;

    return NULL;
}

int MovieManager::searchByName(string name) const {
    for (int i = 0; i < (int)movies.size(); i++) {
        if (movies[i]->getName() == name)
            return i;
    }

    return -1;
}

bool MovieManager::deleteMovieById(int id) {
    Movie* movieToDelete = searchById(id);

    if (movieToDelete == NULL)
        return false;

    for (int i = 0; i < (int)movies.size(); i++) {
        if (movies[i]->getId() == id) {
            movies.erase(movies.begin() + i);
            break;
        }
    }

    movieById.erase(id);
    delete movieToDelete;
    updateBestActionRating();
    return true;
}

void MovieManager::mergeByRating(int left, int mid, int right) {
    vector<Movie*> temp;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (movies[i]->getRate() >= movies[j]->getRate()) {
            temp.push_back(movies[i]);
            i++;
        }
        else {
            temp.push_back(movies[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(movies[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(movies[j]);
        j++;
    }

    for (int k = 0; k < (int)temp.size(); k++)
        movies[left + k] = temp[k];
}

void MovieManager::mergeSortByRating(int left, int right) {
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSortByRating(left, mid);
    mergeSortByRating(mid + 1, right);
    mergeByRating(left, mid, right);
}

void MovieManager::sortByRating() {
    if (movies.size() <= 1)
        return;

    mergeSortByRating(0, (int)movies.size() - 1);
}

void MovieManager::showTopRatedMovie() const {
    if (movies.empty()) {
        cout << "No movies added yet." << endl;
        return;
    }

    priority_queue<Movie*, vector<Movie*>, CompareMovieRating> topMovies;

    for (int i = 0; i < (int)movies.size(); i++)
        topMovies.push(movies[i]);

    cout << "\n========== Top Rated Movie ==========" << endl;
    topMovies.top()->print();
}

void MovieManager::printAllMovies() const {
    if (movies.empty()) {
        cout << "No movies added yet." << endl;
        return;
    }

    for (int i = 0; i < (int)movies.size(); i++) {
        cout << "\n========== Movie " << i + 1 << " ==========" << endl;
        movies[i]->print();
    }
}

void MovieManager::printBudgets() const {
    if (movies.empty()) {
        cout << "No movies added yet." << endl;
        return;
    }

    for (int i = 0; i < (int)movies.size(); i++) {
        cout << i + 1 << ". ID " << movies[i]->getId()
             << " - " << movies[i]->getName()
             << " - " << movies[i]->getType()
             << " - Budget: " << movies[i]->calculateBudget() << endl;
    }
}

int MovieManager::getCount() const {
    return (int)movies.size();
}
