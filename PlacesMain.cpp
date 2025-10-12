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

    // SMALL GREETING FUNCTION (NEW)
    void greet() {
        cout << "\nWelcome to the Places program!" << endl;
    }
};

// MAIN PROGRAM STARTS HERE
int main() {
    cout << "=== Places of the World Program ===" << endl;

    // CREATE AN EXAMPLE PLACE TO TEST
    Place example;

    // FILL IN DETAILS
    example.name = "Oxford";
    example.population = 152000;
    example.yearRecorded = 2024;
    example.leader = "Councillor Susan Brown";

    // SHOW THE INFORMATION
    example.greet();       // CALL THE NEW GREETING FUNCTION
    example.showDetails();

    // TODO: Add more places dynamically in future
    Place london;
    london.name = "London";
    london.population = 9000000;
    london.yearRecorded = 2024;
    london.leader = "Mayor Sadiq Khan";
    london.showDetails();

    return 0; // PROGRAM FINISHES SUCCESSFULLY
}
