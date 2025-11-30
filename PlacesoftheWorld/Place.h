// File: Place.h
// This is the BLUEPRINT. It only declares what functions exist.

#pragma once       // Include guard: Tells the complier, to include the header file once per compilation
#include <string>  // <-- We need this because we use std::string below

class Place {
    // Private Data Members
private:
    std::string name;
    int population;
    int yearRecorded;
    std::string leader;
    std::string address;
    std::string history;
    double latitude;
    double longitude;

    // --- Public Function Declarations ---
public:
    Place(); // Constructor

    // Setters
    void setName(std::string newName);
    void setPopulation(int newPop);
    void setYearRecorded(int newYear);
    void setLeader(std::string newLeader);
    void setAddress(std::string newAddress);
    void setHistory(std::string newHistory);
    void setLatitude(double newLat);
    void setLongitude(double newLon);

    // Getters
    std::string getName() const;
    int getPopulation() const;
    int getYearRecorded() const;
    std::string getLeader() const;
    std::string getAddress() const;
    std::string getHistory() const;
    double getLatitude() const;
    double getLongitude() const;

    // Other functions
    void showDetails() const;
};