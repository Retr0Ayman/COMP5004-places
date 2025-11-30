// File: PlaceManager.h

#pragma once // My standard include guard
#include "Place.h" // I need to include Place.h so this class knows what a "Place" object is

// This is the blueprint for my manager class.
// Its job is to look after my collection of Place objects.
class PlaceManager {

private:
    // My coursework says I must store at least 100 places.
    // A simple array is the easiest approach.
    Place allPlaces[100];

    // This variable keeps track of how many places I have stored.
    int placeCount;

    // Private helper that loads the data from the file.
    // My constructor will call this automatically.
    void loadFromFile();

public:
    // Constructor (in my .cpp it calls loadFromFile)
    PlaceManager();

    // --- Main Menu Functions ---

    // 1. Add a new place
    void addNewPlace();

    // 2. Show all places
    void showAllPlaces();

    // 3. Save data to file (used by "Save and Exit")
    void saveToFile();

    // 4. Delete a place by name
    void deletePlace();

    // 5. Find a place by its name
    void findPlaceByName();

    // 6. Update/edit an existing place
    void updatePlace();

    // 7. Show just one field (e.g. only names) for all places
    void showFieldForAllPlaces();

    // 8. Calculate the distance between two places
    void distanceBetweenTwoPlaces();
};
