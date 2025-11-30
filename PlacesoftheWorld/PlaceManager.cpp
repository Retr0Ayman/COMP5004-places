// --- File: PlaceManager.cpp ---

#include "PlaceManager.h" // I must include the blueprint file for this class
#include <iostream>       // I need this for 'cout' and 'cin'
#include <string>         // I need this for the 'string' data type
#include <fstream>        // I need this for 'ifstream' and 'ofstream' (file saving/loading)
#include <cmath>          // I need this for sin, cos, acos in the distance formula

using namespace std;

//  Constructor Code
// This is the code for my PlaceManager constructor.
// It runs when my main() function creates a 'PlaceManager' object.
PlaceManager::PlaceManager() {

    // When my program first starts, I haven't added any places yet.
    // I MUST set this to 0 *before* I try to load my file
    placeCount = 0;

    // Now, I'll automatically call my private load function
    // as required by the coursework.
    loadFromFile();
}

// My Main Function Definitions

// This is the code for my addNewPlace function
void PlaceManager::addNewPlace() {

    // First, I need to check if my array is full.
    if (placeCount >= 100) { // maximum places stored is 100
        cout << "Error: My database is full. I can't add more places." << endl;
        return; // I'll just exit the function
    }

    // I'll create some temporary variables to store the user's input
    string tempString;
    int tempInt;
    double tempDouble;

    cout << "\n--- Adding a New Place ---" << endl;
    cout << "Enter Place Name: ";
    getline(cin, tempString);
    // I'm adding the new data into the 'allPlaces' array,
    // at the 'placeCount' index.
    allPlaces[placeCount].setName(tempString);

    cout << "Enter Population: ";
    cin >> tempInt;
    allPlaces[placeCount].setPopulation(tempInt);

    cout << "Enter Year Recorded: ";
    cin >> tempInt;
    allPlaces[placeCount].setYearRecorded(tempInt);

    cin.ignore(); // I still need to use cin.ignore() here.

    cout << "Enter Leader's Name: ";
    getline(cin, tempString);
    allPlaces[placeCount].setLeader(tempString);

    cout << "Enter Address: ";
    getline(cin, tempString);
    allPlaces[placeCount].setAddress(tempString);

    cout << "Enter a Short History: ";
    getline(cin, tempString);
    allPlaces[placeCount].setHistory(tempString);

    cout << "Enter Latitude: ";
    cin >> tempDouble;
    allPlaces[placeCount].setLatitude(tempDouble);

    cout << "Enter Longitude: ";
    cin >> tempDouble;
    allPlaces[placeCount].setLongitude(tempDouble);

    // --- THIS IS THE MOST IMPORTANT STEP ---
    // Now that I've successfully filled the slot at 'allPlaces[placeCount]',
    // I MUST increment my counter.
    placeCount++;

    cout << "Successfully added new place!" << endl;

    // I'll add one more 'ignore' to clean up after my last 'cin >> tempDouble'
    // so my main menu works correctly.
    cin.ignore();
}


// This is the code for my showAllPlaces function
void PlaceManager::showAllPlaces() {
    cout << "\n--- Displaying All Places ---" << endl;

    // First, I'll check if I've actually added any places.
    if (placeCount == 0) {
        cout << "No places to show. I should add one first." << endl;
        return; // Exit the function
    }

    // I'll use a simple 'for' loop to go from 0 up to (but not including)
    // my 'placeCount'.
    for (int i = 0; i < placeCount; i++) {
        // For each item in my array, I'll call its own 'showDetails' function.
        allPlaces[i].showDetails();
    }
}

// This is the code for my deletePlace function
void PlaceManager::deletePlace() {
    // First, check if there are any places to delete
    if (placeCount == 0) {
        cout << "There are no places to delete.\n";
        return;
    }

    string target;
    cout << "\n--- Delete a Place ---" << endl;
    cout << "Enter the name of the place to delete: ";
    getline(cin, target);

    // Look for the place with the given name
    int index = -1;
    for (int i = 0; i < placeCount; i++) {
        if (allPlaces[i].getName() == target) {
            index = i;
            break;
        }
    }

    // If not found, tell the user
    if (index == -1) {
        cout << "No place found with that name.\n";
        return;
    }

    // Shift all places after the deleted one left by one position
    for (int j = index; j < placeCount - 1; j++) {
        allPlaces[j] = allPlaces[j + 1];
    }

    // Reduce the total count of places
    placeCount--;

    cout << "Deleted '" << target << "' successfully.\n";
}

// This is the code for my findPlaceByName function
void PlaceManager::findPlaceByName() {
    cout << "\n--- Find a Place by Name ---\n";

    if (placeCount == 0) {
        cout << "There are no places stored yet.\n";
        return;
    }

    string target;
    cout << "Enter the name of the place: ";
    getline(cin, target);

    for (int i = 0; i < placeCount; i++) {
        if (allPlaces[i].getName() == target) {
            cout << "\nPlace found:\n";
            allPlaces[i].showDetails();
            return;
        }
    }

    cout << "No place found with that name.\n";
}

// This is the code for my updatePlace function
void PlaceManager::updatePlace() {
    cout << "\n--- Update an Existing Place ---\n";

    if (placeCount == 0) {
        cout << "There are no places to update.\n";
        return;
    }

    string target;
    cout << "Enter the name of the place you want to update: ";
    getline(cin, target);

    int index = -1;
    for (int i = 0; i < placeCount; i++) {
        if (allPlaces[i].getName() == target) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "No place found with that name.\n";
        return;
    }

    cout << "\nCurrent details:\n";
    allPlaces[index].showDetails();
    cout << "\nEnter new details for this place.\n";

    string name, leader, address, history;
    int population, yearRecorded;
    double latitude, longitude;

    cout << "Name: ";
    getline(cin, name);

    cout << "Population: ";
    cin >> population;
    cout << "Year recorded: ";
    cin >> yearRecorded;
    cin.ignore(); // clear newline

    cout << "Leader name: ";
    getline(cin, leader);

    cout << "Address: ";
    getline(cin, address);

    cout << "Short history: ";
    getline(cin, history);

    cout << "Latitude: ";
    cin >> latitude;
    cout << "Longitude: ";
    cin >> longitude;
    cin.ignore(); // clear newline after longitude

    allPlaces[index].setName(name);
    allPlaces[index].setPopulation(population);
    allPlaces[index].setYearRecorded(yearRecorded);
    allPlaces[index].setLeader(leader);
    allPlaces[index].setAddress(address);
    allPlaces[index].setHistory(history);
    allPlaces[index].setLatitude(latitude);
    allPlaces[index].setLongitude(longitude);

    cout << "Place updated.\n";
}

// This is the code for my showFieldForAllPlaces function
void PlaceManager::showFieldForAllPlaces() {
    cout << "\n--- Show One Field for All Places ---\n";

    if (placeCount == 0) {
        cout << "There are no places stored yet.\n";
        return;
    }

    cout << "Which field do I want to display?\n";
    cout << "1. Name\n";
    cout << "2. Population\n";
    cout << "3. Year recorded\n";
    cout << "4. Leader\n";
    cout << "5. Address\n";
    cout << "6. History\n";
    cout << "7. Coordinates (latitude and longitude)\n";
    cout << "Enter my choice: ";

    int choice;
    cin >> choice;
    cin.ignore();

    cout << "\n";

    for (int i = 0; i < placeCount; i++) {
        cout << "[" << (i + 1) << "] ";

        if (choice == 1) {
            cout << allPlaces[i].getName();
        }
        else if (choice == 2) {
            cout << allPlaces[i].getName()
                 << " -> Population: " << allPlaces[i].getPopulation();
        }
        else if (choice == 3) {
            cout << allPlaces[i].getName()
                 << " -> Year recorded: " << allPlaces[i].getYearRecorded();
        }
        else if (choice == 4) {
            cout << allPlaces[i].getName()
                 << " -> Leader: " << allPlaces[i].getLeader();
        }
        else if (choice == 5) {
            cout << allPlaces[i].getName()
                 << " -> Address: " << allPlaces[i].getAddress();
        }
        else if (choice == 6) {
            cout << allPlaces[i].getName()
                 << " -> History: " << allPlaces[i].getHistory();
        }
        else if (choice == 7) {
            cout << allPlaces[i].getName()
                 << " -> (" << allPlaces[i].getLatitude()
                 << ", " << allPlaces[i].getLongitude() << ")";
        }
        else {
            cout << "Invalid choice.\n";
            return;
        }

        cout << "\n";
    }
}

// This is the code for my distanceBetweenTwoPlaces function
void PlaceManager::distanceBetweenTwoPlaces() {
    cout << "\n--- Distance Between Two Places ---\n";

    if (placeCount < 2) {
        cout << "I need at least two places stored.\n";
        return;
    }

    string name1, name2;
    cout << "Enter the name of the first place: ";
    getline(cin, name1);
    cout << "Enter the name of the second place: ";
    getline(cin, name2);

    int index1 = -1;
    int index2 = -1;

    for (int i = 0; i < placeCount; i++) {
        if (allPlaces[i].getName() == name1) {
            index1 = i;
        }
        if (allPlaces[i].getName() == name2) {
            index2 = i;
        }
    }

    if (index1 == -1) {
        cout << "Could not find '" << name1 << "'.\n";
        return;
    }
    if (index2 == -1) {
        cout << "Could not find '" << name2 << "'.\n";
        return;
    }

    double lat1 = allPlaces[index1].getLatitude();
    double lon1 = allPlaces[index1].getLongitude();
    double lat2 = allPlaces[index2].getLatitude();
    double lon2 = allPlaces[index2].getLongitude();

    // Convert degrees to radians (simplest formula)
    double phi1 = lat1 * 3.141592653589793 / 180.0;
    double phi2 = lat2 * 3.141592653589793 / 180.0;
    double L1   = lon1 * 3.141592653589793 / 180.0;
    double L2   = lon2 * 3.141592653589793 / 180.0;

    // Formula from the coursework sheet
    double cos_d = sin(phi1) * sin(phi2) +
                   cos(phi1) * cos(phi2) * cos(L1 - L2);

    double d = acos(cos_d);          // angular distance in radians
    double distance = 6371.0 * d;    // 6371 km is Earth's mean radius

    cout << "Approximate distance between '"
         << name1 << "' and '" << name2
         << "' is " << distance << " km.\n";
}

// My New File I/O Functions

// This is the code for my saveToFile function
void PlaceManager::saveToFile() {
    string path = "places.txt";
    // I use 'ofstream' (output file stream) to write to a file
    ofstream outFile(path);

    if (!outFile.is_open()) {
        cout << "Error: I could not open the file for writing.\n";
        return;
    }

    // I'll loop through my array from 0 up to my 'placeCount'
    for (int i = 0; i < placeCount; i++) {
        // I write each piece of data to the file, one line at a time,
        // using all the 'getter' functions I just added to my Place class.
        outFile << allPlaces[i].getName() << endl;
        outFile << allPlaces[i].getPopulation() << endl;
        outFile << allPlaces[i].getYearRecorded() << endl;
        outFile << allPlaces[i].getLeader() << endl;
        outFile << allPlaces[i].getAddress() << endl;
        outFile << allPlaces[i].getHistory() << endl;
        outFile << allPlaces[i].getLatitude() << endl;
        outFile << allPlaces[i].getLongitude() << endl;
    }

    outFile.close();
    cout << "Saved " << placeCount << " place(s) to file: " << path << endl;
}

// This is the code for my private loadFromFile function
void PlaceManager::loadFromFile() {
    string path = "places.txt";
    // I use 'ifstream' (input file stream) to read from a file
    ifstream inFile(path);

    if (!inFile.is_open()) {
        cout << "(No save file found — I'm starting fresh)\n";
        return; // This isn't an error, it just means no file exists yet
    }

    // I'll keep looping as long as I have data to read
    // and my 'placeCount' is not over my 100 limit
    while (placeCount < 100) {

        // I'll use temporary variables to read the data
        string name, leader, address, history;
        int population, year;
        double lat, lon;

        // I read the data in the *exact same order* I saved it
        getline(inFile, name);

        // If the name is empty, I've probably hit the end of the file
        if (name.empty()) {
            break; // I stop looping
        }

        inFile >> population;
        inFile >> year;
        inFile.ignore(); // I clear the newline after 'cin >> year'
        getline(inFile, leader);
        getline(inFile, address);
        getline(inFile, history);
        inFile >> lat;
        inFile >> lon;
        inFile.ignore(); // I clear the newline after 'cin >> lon'

        // Now I use my setters to put this data into my array
        // at the current 'placeCount' index
        allPlaces[placeCount].setName(name);
        allPlaces[placeCount].setPopulation(population);
        allPlaces[placeCount].setYearRecorded(year);
        allPlaces[placeCount].setLeader(leader);
        allPlaces[placeCount].setAddress(address);
        allPlaces[placeCount].setHistory(history);
        allPlaces[placeCount].setLatitude(lat);
        allPlaces[placeCount].setLongitude(lon);

        // And I MUST remember to increment my placeCount!
        placeCount++;
    }

    inFile.close();

    // I only want to show this message if I actually loaded something
    if (placeCount > 0) {
         cout << "Loaded " << placeCount << " place(s) from file.\n";
    }
}

//should be the end rn