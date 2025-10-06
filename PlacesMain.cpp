#include <iostream>
#include <string>   // Allows me to use text/string variables
using namespace std;


// CLASS TO REPRESENT A PLACE

class Place {
public:
    // BASIC DETAILS ABOUT THE PLACE
    string name;          // Name of the place
    int population;       // How many people live there
    int yearRecorded;     // Year when the population was recorded
    string leader;        // Name of the leader

    // FUNCTION THAT SHOWS THE DETAILS OF A PLACE
    void showDetails() {
        cout << "\nPlace: " << name << endl;
        cout << "Population: " << population
             << " (as of " << yearRecorded << ")" << endl;
        cout << "Leader: " << leader << endl;
    }
};

// MAIN PROGRAM STARTS HERE

int main() {
    cout << "=== Places of the World Program ===" << endl;

    // Create an example place to test
    Place example;

    // Fill in details
    example.name = "Oxford";
    example.population = 152000;
    example.yearRecorded = 2024;
    example.leader = "Councillor Susan Brown";

    // Show the information
    example.showDetails();

    return 0; // Program finished successfully
}
