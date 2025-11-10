//  File: PlacesMain.cpp

#include <iostream>
#include <string>
#include "PlaceManager.h" // I only need to include my manager

using namespace std;

// My main() function is just a simple menu.
// All the real work is done by my PlaceManager object.
int main() {

    // 1. I create my one instance of PlaceManager.
    // The constructor will now automatically call loadFromFile().
    PlaceManager manager;

    int choice = 0;

    // I'll loop until the user chooses option 4.
    while (choice != 4) {
        cout << "\n=== Places of the World Menu ===" << endl;
        cout << "1. Add a new place" << endl;
        cout << "2. Show all places" << endl;
        cout << "3. Find a place by name" << endl; // I'm adding this option for later
        cout << "4. Save and Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;
        cin.ignore(); // I clear the newline character

        if (choice == 1) {
            manager.addNewPlace();
        }
        else if (choice == 2) {
            manager.showAllPlaces();
        }
        else if (choice == 3) {
            // We haven't built this yet, but we'll add it next.
            cout << "Feature coming soon!" << endl;
            // manager.findPlaceByName();
        }
        else if (choice == 4) {
            // When the user wants to exit, I'll call my save function first.
            manager.saveToFile();
            cout << "Data saved. Exiting program. Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}