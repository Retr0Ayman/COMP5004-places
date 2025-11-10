// File: Place.cpp
// This is the IMPLEMENTATION and it defines how those functions work.

#include "Place.h"   // <-- Include the blueprint we just made
#include <iostream>  // <-- For std::cout
#include <string>    // <-- For std::string

using namespace std; // This is fine in a .cpp file

//  Constructor Code
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

void Place::setLatitude(double newLat) {
    if (newLat >= -90.0 && newLat <= 90.0) {
        latitude = newLat;
    } else {
        latitude = 0.0; // Set a safe default
    }
}

void Place::setLongitude(double newLon) {
    if (newLon >= -180.0 && newLon <= 180.0) {
        longitude = newLon;
    } else {
        longitude = 0.0; // Set a safe default
    }
}


//  Getter Function Code
string Place::getName() const {
    return name;
}

int Place::getPopulation() const {
    return population;
}

int Place::getYearRecorded() const {
    return yearRecorded;
}

string Place::getLeader() const {
    return leader;
}

string Place::getAddress() const {
    return address;
}

string Place::getHistory() const {
    return history;
}

double Place::getLatitude() const {
    return latitude;
}

double Place::getLongitude() const {
    return longitude;
}


//   Other Function Code
void Place::showDetails() const {
    cout << "\n--- Place Information ---" << endl;
    cout << "Name: " << name << endl;
    cout << "Population: " << population << " (as of " << yearRecorded << ")" << endl;
    cout << "Leader: " << leader << endl;
    cout << "Address: " << address << endl;
    cout << "History: " << history << endl;
    cout << "Coordinates: (" << latitude << ", " << longitude << ")" << endl;
}