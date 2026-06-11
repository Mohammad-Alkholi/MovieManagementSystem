#ifndef MOVIEMANAGER_H
#define MOVIEMANAGER_H

#include "Movie.h"
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class MovieManager {
private:
    vector<Movie*> movies;
    unordered_map<int, Movie*> movieById;

    void mergeByRating(int left, int mid, int right);
    void mergeSortByRating(int left, int right);
    void updateBestActionRating();

public:
    MovieManager();
    ~MovieManager();

    bool addMovie(Movie* movie);
    Movie* searchById(int id) const;
    int searchByName(string name) const;
    bool deleteMovieById(int id);
    void sortByRating();
    void showTopRatedMovie() const;
    void printAllMovies() const;
    void printBudgets() const;
    int getCount() const;
};

#endif
