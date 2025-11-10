// --- File: PlaceManager.cpp ---

#include "PlaceManager.h" // I must include the blueprint file for this class
#include <iostream>     // I need this for 'cout' and 'cin'
#include <string>       // I need this for the 'string' data type
#include <fstream>      // I need this for 'ifstream' and 'ofstream' (file saving/loading)

using namespace std;

//  Constructor Code
// This is the code for my PlaceManager constructor.
// It runs when my main() function creates a 'PlaceManager' object.
PlaceManager::PlaceManager() {

    // When my program first starts, I haven't added any places yet.
    // I MUST set this to 0 *before* I try to load my filee
    placeCount = 0;

    // Now, I'll automatically call my private load function
    // as required by the coursework.
    loadFromFile();
}

// --- My Main Function Definitions ---

// This is the code for my addNewPlace function
void PlaceManager::addNewPlace() {

    // First, I need to check if my array is full.
    if (placeCount >= 100) {
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


// --- My New File I/O Functions ---

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