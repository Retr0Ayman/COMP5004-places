#include <iostream>
#include <string>
using namespace std;

// Class To Represent A Place
class Place {
public:
    // Basic Details
    string name;
    int population;
    int yearRecorded;
    string leader;
    string address;
    string history;
    double latitude;
    double longitude;

    // Show All Details
    void showDetails() {
        cout << "\n--- Place Information ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Population: " << population << " (as of " << yearRecorded << ")" << endl;
        cout << "Leader: " << leader << endl;
        cout << "Address: " << address << endl;
        cout << "History: " << history << endl;
        cout << "Coordinates: (" << latitude << ", " << longitude << ")" << endl;
    }
};

// Main Program
int main() {
    cout << "=== Places of the World ===" << endl;

    Place p; // Create One Place To Test

    cout << "\nEnter Place Name: ";
    getline(cin, p.name);

    cout << "Enter Population: ";
    cin >> p.population;

    cout << "Enter Year Recorded: ";
    cin >> p.yearRecorded;
    cin.ignore(); // Clear Leftover newline

    cout << "Enter Leader's Name: ";
    getline(cin, p.leader);

    cout << "Enter Address: ";
    getline(cin, p.address);

    cout << "Enter a Short History: ";
    getline(cin, p.history);

    cout << "Enter Latitude: ";
    cin >> p.latitude;
    cout << "Enter Longitude: ";
    cin >> p.longitude;

    // Show The Result
    p.showDetails();

    cout << "\nThank You For Using My Program!" << endl;
    return 0;
}
