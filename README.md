# Movie Management System - Final Student DSA Version

This is the final C++ OOP project version prepared for Visual Studio 2017.

The project is still written in a believable student style, but it now includes stronger Data Structures and Algorithms improvements.

## What the project does

- Add Action movies
- Add Sci-Fi movies
- Give every movie a unique ID
- Store movies dynamically
- Search for a movie by ID
- Search for a movie by exact name
- Delete a movie by ID
- Sort movies by rating
- Show all movie details
- Show movie budgets
- Show the top rated movie
- Track the best Action movie rating

## OOP concepts used

- Classes and objects
- Encapsulation with private data members
- Constructors and destructors
- Inheritance: `Action` and `SciFi` inherit from `Movie`
- Polymorphism: `Movie*` can point to `Action` or `SciFi` objects
- Abstract class: `Movie` has pure virtual functions
- Composition: `Movie` contains `Date`, `CastMember`, and `ShootLocation`
- Dynamic memory using `new`, `delete`, `new[]`, and `delete[]`
- Static data member in the `Action` class

## Data Structures and Algorithms used

### 1. vector

The project now uses:

```cpp
vector<Movie*> movies;
```

This replaces the old fixed-size array:

```cpp
Movie* movies[50];
```

Why this is better:

- The movie list can grow dynamically.
- There is no hard limit of 50 movies.
- Adding and removing movies is cleaner.

### 2. unordered_map

The project now uses:

```cpp
unordered_map<int, Movie*> movieById;
```

This is used to search movies by ID quickly.

Old search by name was linear search:

```text
O(n)
```

New search by ID using hash table:

```text
O(1) average case
```

This is the clearest performance improvement in the project.

### 3. Merge sort

The old version used bubble sort.

Bubble sort time complexity:

```text
O(n^2)
```

The new version uses merge sort to sort movies by rating.

Merge sort time complexity:

```text
O(n log n)
```

This is better and shows Data Structures and Algorithms knowledge.

### 4. priority_queue

The project uses a priority queue to show the top rated movie.

```cpp
priority_queue<Movie*, vector<Movie*>, CompareMovieRating>
```

This is useful for the feature:

```text
Show top rated movie
```

## Important implementation notes

The project stores the same movie pointers in two structures:

```cpp
vector<Movie*> movies;
unordered_map<int, Movie*> movieById;
```

So when adding or deleting a movie, both structures must be updated.

When adding:

1. Add the pointer to the vector.
2. Add the same pointer to the hash table using the movie ID.

When deleting:

1. Find the pointer using the ID.
2. Remove the pointer from the vector.
3. Remove the ID from the hash table.
4. Delete the movie from memory.

## How to run in Visual Studio 2017

1. Extract the zip file.
2. Open `MovieManagementSystem.sln`.
3. Choose `Debug` and `Win32`.
4. Press `Ctrl + F5` to run without closing the console immediately.

If Visual Studio asks to retarget the project, accept the retargeting.

## Visual Studio 2017 SDK Fix

If Visual Studio shows this error:

```text
error MSB8036: The Windows SDK version 10.0 was not found
```

This is not a C++ code error. It means Visual Studio cannot find the required Windows SDK.

Fast fix:

1. Open `MovieManagementSystem.sln`.
2. Right-click the solution name.
3. Choose `Retarget solution`.
4. Select any installed Windows SDK version.
5. Rebuild the project.

If no SDK appears, install it from:

```text
Visual Studio Installer -> Modify -> Desktop development with C++ -> Windows 10 SDK
```

## Files

```text
MovieManagementSystem.sln
MovieManagementSystem/
  Main.cpp
  Date.h / Date.cpp
  CastMember.h / CastMember.cpp
  ShootLocation.h / ShootLocation.cpp
  Movie.h / Movie.cpp
  Action.h / Action.cpp
  SciFi.h / SciFi.cpp
  MovieManager.h / MovieManager.cpp
```

## Interview explanation

Use this explanation:

> I used OOP to model movies with inheritance and polymorphism. `Movie` is an abstract base class, and `Action` and `SciFi` are derived classes. I used a `vector` to store movies dynamically, an `unordered_map` to search movies quickly by ID, merge sort to sort movies by rating more efficiently than bubble sort, and a `priority_queue` to display the top rated movie.

Do not oversell it as production software. Present it as a student academic project improved with basic Data Structures and Algorithms.
