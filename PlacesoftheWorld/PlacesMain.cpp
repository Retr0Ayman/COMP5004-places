//  File: PlacesMain.cpp

#include <iostream>
#include <string>
#include "Place.h" // I need to include my new "Place.h" blueprint

using namespace std;

// My Place class definition is gone from here. It's now split
// into Place.h and Place.cpp, which is much cleaner and required by the assignment.

// Main Program
int main() {
    cout << "=== Places of the World ===" << endl;

    // Here, I'm creating one instance (object) of my Place class.
    // My default constructor (from Place.cpp) runs automatically here.
    Place p; 

    // I'll create some temporary variables to store the user's input
    // before I pass it to my object.
    string tempString;
    int tempInt;
    double tempDouble;

    cout << "\nEnter Place Name: ";
    getline(cin, tempString);
    p.setName(tempString); // Instead of p.name = ..., I now use my public setter function.

    cout << "Enter Population: ";
    cin >> tempInt;
    p.setPopulation(tempInt); // Use the setter

    cout << "Enter Year Recorded: ";
    cin >> tempInt;
    p.setYearRecorded(tempInt); // Use the setter
    
    // I need to use cin.ignore() here to clear the leftover newline
    // character after 'cin >> tempInt', otherwise my next 'getline' will fail.
    cin.ignore(); 

    cout << "Enter Leader's Name: ";
    getline(cin, tempString);
    p.setLeader(tempString); // Use the setter

    cout << "Enter Address: ";
    getline(cin, tempString);
    p.setAddress(tempString); // Use the setter

    cout << "Enter a Short History: ";
    getline(cin, tempString);
    p.setHistory(tempString); // Use the setter

    cout << "Enter Latitude: ";
    cin >> tempDouble;
    p.setLatitude(tempDouble); // Use the setter

    cout << "Enter Longitude: ";
    cin >> tempDouble;
    p.setLongitude(tempDouble); // Use the setter

    // I call my public function to show the details I just set.
    p.showDetails();

    cout << "\nThank You For Using My Program!" << endl;
    return 0;
}