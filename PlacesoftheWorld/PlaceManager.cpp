// --- File: PlaceManager.cpp ---

#include "PlaceManager.h" // I must include the blueprint file for this class
#include <iostream>     // I'll probably need this later for printing

using namespace std;

//  Constructor Code
// This is the code for my PlaceManager constructor.
// It runs when my main() function creates a 'PlaceManager' object.
// Its most important job is to initialize my placeCount to zero.
PlaceManager::PlaceManager() {

    // When my program first starts, I haven't added any places yet.
    placeCount = 0;
}

// My Main Function Definitions
// I will add the code for addNewPlace() and showAllPlaces() here next