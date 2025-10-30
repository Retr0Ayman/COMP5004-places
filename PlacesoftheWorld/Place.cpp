// File: Place.cpp

#include "Place.h"   // I need to include my "Place.h" blueprint file here.
#include <iostream> // I need <iostream> so I can use 'cout' to print to the console.

using namespace std;

//  Constructor Code
// This is the code for my constructor. I'm setting some default values
// just in case I create an object but don't set all its data.
// I have to use "Place::" to tell C++ these functions belong to my Place class.
Place::Place() {
    name = "Unknown";
    population = 0;
    yearRecorded = 0;
    leader = "Unknown";
    address = "Unknown";
    history = "N/A";
    latitude = 0.0;
    longitude = 0.0;
}

// Setter Function Code

// This function takes 'newName' from the outside and assigns it to my private 'name' variable.
void Place::setName(string newName) {
    name = newName;
}

void Place::setPopulation(int newPop) {
    population = newPop;
}

void Place::setYearRecorded(int newYear) {
    yearRecorded = newYear;
}

void Place::setLeader(string newLeader) {
    leader = newLeader;
}

void Place::setAddress(string newAddress) {
    address = newAddress;
}

void Place::setHistory(string newHistory) {
    history = newHistory;
}

// For latitude and longitude, I can add a simple check
// to make sure the data is valid before I set it.
void Place::setLatitude(double newLat) {
    if (newLat >= -90.0 && newLat <= 90.0) {
        latitude = newLat;
    } else {
        latitude = 0.0; // Set a safe default if input is bad
    }
}

void Place::setLongitude(double newLon) {
    if (newLon >= -180.0 && newLon <= 180.0) {
        longitude = newLon;
    } else {
        longitude = 0.0; // Set a safe default
    }
}

// Getter Function Code
// These just return the value of the private variable.
string Place::getName() {
    return name;
}

int Place::getPopulation() {
    return population;
}

//  Other Function Code
// This is the code for my showDetails function. It can access the private
// variables directly because this function is part of the Place class.
void Place::showDetails() {
    cout << "\n--- Place Information ---" << endl;
    cout << "Name: " << name << endl;
    cout << "Population: " << population << " (as of " << yearRecorded << ")" << endl;
    cout << "Leader: " << leader << endl;
    cout << "Address: " << address << endl;
    cout << "History: " << history << endl;
    cout << "Coordinates: (" << latitude << ", " << longitude << ")" << endl;
}