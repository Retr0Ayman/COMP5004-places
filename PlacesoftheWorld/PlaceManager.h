// File: PlaceManager.h

#pragma once // My standard include guard
#include "Place.h" // I need to include Place.h so this class knows what a "Place" object is

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

    // Public Interface
    // These are the public "buttons" my main() function will press.
public:
    // This is my constructor for the PlaceManager.
    PlaceManager();

    // My Main Functions
    // (I will add more here soon)
};