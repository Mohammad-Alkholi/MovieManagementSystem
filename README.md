# Movie Management System

A C++ console-based Movie Management System that allows users to manage different types of movies, search movie records, sort movies by rating, and display movie information in an organized way.

The project demonstrates object-oriented programming concepts, dynamic memory management, and the use of data structures and algorithms in a practical console application.

## Features

* Add new movies
* Add different movie types, including Action and Sci-Fi movies
* Display all stored movies
* Search for a movie by ID
* Search for a movie by title
* Delete a movie by ID
* Sort movies by rating
* Display the top-rated movie
* Display movie budget information
* Track the highest rating for Action movies

## Technologies Used

* C++
* Visual Studio 2017
* Console-based application
* STL containers: `vector`, `unordered_map`, and `priority_queue`

## Object-Oriented Programming Concepts

This project applies several core OOP concepts:

* **Classes and Objects**
  Used to represent movies, cast members, dates, and shooting locations.

* **Encapsulation**
  Class data is kept private and accessed through public member functions.

* **Inheritance**
  `Action` and `SciFi` classes inherit from the base `Movie` class.

* **Polymorphism**
  Movie objects are handled through base class pointers, allowing different movie types to be managed in one system.

* **Abstract Class**
  The `Movie` class acts as an abstract base class for specific movie types.

* **Composition**
  A movie contains related objects such as release date, cast member, and shooting location.

* **Constructors and Destructors**
  Used to initialize objects and manage dynamically allocated memory.

* **Static Data Member**
  Used to store class-level information shared between objects.

## Data Structures and Algorithms Used

| Concept          | Usage                            |
| ---------------- | -------------------------------- |
| `vector`         | Stores movie objects dynamically |
| `unordered_map`  | Provides fast movie search by ID |
| Merge Sort       | Sorts movies by rating           |
| `priority_queue` | Displays the top-rated movie     |

## Project Structure

```text
MovieManagementSystem/
│
├── MovieManagementSystem.sln
├── README.md
├── .gitignore
│
└── MovieManagementSystem/
    ├── Main.cpp
    ├── Movie.h / Movie.cpp
    ├── Action.h / Action.cpp
    ├── SciFi.h / SciFi.cpp
    ├── MovieManager.h / MovieManager.cpp
    ├── Date.h / Date.cpp
    ├── CastMember.h / CastMember.cpp
    └── ShootLocation.h / ShootLocation.cpp
```

## How to Run

### Using Visual Studio 2017

1. Clone or download the repository.
2. Open `MovieManagementSystem.sln`.
3. Select `Debug` and `Win32`.
4. Build the solution.
5. Run the project using `Ctrl + F5`.

If Visual Studio asks to retarget the solution, accept the retargeting and rebuild the project.

## Example Use Cases

The system can be used to:

* Store movie records
* Manage different movie categories
* Search quickly for a movie using its ID
* Organize movies based on rating
* Display the best-rated movie in the collection

## Skills Demonstrated

* C++ programming
* Object-oriented design
* Dynamic memory management
* Inheritance and polymorphism
* Data structures
* Sorting algorithms
* Console application development
