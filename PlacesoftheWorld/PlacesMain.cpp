// File: PlacesMain.cpp

#include <iostream>
#include <string>
#include "PlaceManager.h"  // I only need my manager class here

using namespace std;

// This is my main menu function.
// All the real work is handled by my PlaceManager object.
int main() {

    // When this object is created, the constructor will automatically
    // call loadFromFile() so my saved data is ready to use.
    PlaceManager manager;

    int choice = 0;

    // I will keep looping until the user chooses "Save and Exit".
    while (choice != 8) {

        cout << "\n=== Places of the World Menu ===" << endl;
        cout << "1. Add a new place" << endl;
        cout << "2. Show all places" << endl;
        cout << "3. Delete a place" << endl;
        cout << "4. Find a place by name" << endl;
        cout << "5. Update an existing place" << endl;
        cout << "6. Distance between two places" << endl;
        cout << "7. Show one field for all places" << endl;
        cout << "8. Save and Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear leftover newline

        if (choice == 1) {
            manager.addNewPlace();
        }
        else if (choice == 2) {
            manager.showAllPlaces();
        }
        else if (choice == 3) {
            manager.deletePlace();
        }
        else if (choice == 4) {
            manager.findPlaceByName();
        }
        else if (choice == 5) {
            manager.updatePlace();
        }
        else if (choice == 6) {
            manager.distanceBetweenTwoPlaces();
        }
        else if (choice == 7) {
            manager.showFieldForAllPlaces();
        }
        else if (choice == 8) {
            manager.saveToFile();
            cout << "Data saved. Exiting program. Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
