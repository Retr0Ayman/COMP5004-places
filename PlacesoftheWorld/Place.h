//  File: Place.h

#pragma once // This simple line stops my compiler from getting confused if I include this file more than once.
#include <string> // I need to include <string> so I can use the string data type.

using namespace std;

// This is the declaration (the blueprint) for my Place class
class Place {

    //  Private Data Members
    // I'm making all my data 'private'. This is called encapsulation.
    // It means my main() function can't just grab this data and change it directly.
    // It *has* to use my public 'setter' functions below. This is good OO design.
private:
    string name;
    int population;
    int yearRecorded;
    string leader;
    string address;
    string history;
    double latitude;
    double longitude;

    //  Public Interface
    // These are my 'public' functions. My main() function (and other classes)
    // can "press these buttons" to interact with my Place object.
public:
    // This is my constructor. I'll write the code for it in Place.cpp.
    // It will run automatically whenever I create a new Place object.
    Place();

    // "Setter" Functions
    // I'll use these public functions to SET the values of my private variables.
    void setName(string newName);
    void setPopulation(int newPop);
    void setYearRecorded(int newYear);
    void setLeader(string newLeader);
    void setAddress(string newAddress);
    void setHistory(string newHistory);
    void setLatitude(double newLat);
    void setLongitude(double newLon);

    // "Getter" Functions
    // I'll use these to GET (read) the values of my private variables.
    string getName();
    int getPopulation();
    // (I'll add more getters later when my program needs them)

    // Other Functions
    // This is my function to print all the details for a place.
    void showDetails();
};