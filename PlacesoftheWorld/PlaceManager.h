// File: PlaceManager.h

#pragma once // My standard include guard
#include "Place.h" // I need to include Place.h so this class knows what a "Place" object is

// (I will need to include <iostream>, <string>, and <fstream> in my .cpp file)

// This is the blueprint for my "database" or "manager" class.
// Its whole job is to manage my collection of Place objects.
class PlaceManager {

    // Private Data Members
    // I'm keeping my data private, just like in my Place class.
private:
    // My coursework says I need to store at least 100 places.
    // A simple array is the easiest way to start.
    Place allPlaces[100];

    // This variable is super important. It will keep track of
    // how many places I've actually added to my array.
    int placeCount;

    // --- My Private Helper Functions ---
    // I'm making this private because my main() doesn't need to call it.
    // My constructor (below) will call this automatically when the program starts.
    void loadFromFile();


    // Public Interface
    // These are the public "buttons" my main() function will press.
public:
    // This is my constructor for the PlaceManager.
    // (In my .cpp file, I'll make sure this calls loadFromFile())
    PlaceManager();

    // --- My Main Menu Functions ---

    // This will be for menu option "1. Add a new place"
    void addNewPlace();

    // Tis will be for menu option "2. Show all places"
    void showAllPlaces();

    // This will be for my main menu's "Save and Exit" option
    void saveToFile();

    // (I will add more functions here later, like findPlaceByName())
};