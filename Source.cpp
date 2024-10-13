#include <iostream>
#include <string>     // Include string library for std::string
#include <vector>
#include "Constant.h"  // Include your constants header file'
#include<ctime>
#include <fstream>
#include <ostream>

#include <cstdlib>
#include "VehicleClass.h"

//vechile vehicle

using namespace std;


class ChargingStation {
public:
    int cityId = 1;
    string cityName = "Sydney";            // Declare string and initialize it 
    int distanceToLastCity =1;
    int numberOfChargers = 1;
    // Constructor to initialize city details
    ChargingStation(int Stationid) {
        if (Stationid >= 0 && Stationid < NUM_CITIES) {
            cityId = Stationid;
            cityName = nameMap[Stationid];  // Correctly reference nameMap from Constant.h
            distanceToLastCity = distanceMap[Stationid];
            numberOfChargers = chargersMap[Stationid];
            
        }
        else {
            // Handle invalid city ID
            cout << "Invalid City ID!" << endl;
        }
    }
    // Display city information
    void displayCityID() const {
        cout << "City ID: " << cityId << endl;
    }
    void displayDistanceToLastCity() const {
        cout << "Distance to Last City: " << distanceToLastCity << " km" << endl;
    }
    void displayNumberOfChargers() const {
        cout << "Number of Chargers: " << numberOfChargers << endl;
    }
    void displayCityName() const {
        cout << "City Name: " << cityName << endl;
    }
};


Vehicle::Vehicle(int vId, int destId, int capRange, int remRange): vehicleId(vId), destinationId(destId),capacityRange(capRange), remainingRange(remRange) {}// constructor

// Getters
int Vehicle::getVehicleId() const { return vehicleId; } 
int Vehicle::getCurrentCityId() const { return currentCityId; }
int Vehicle::getDestinationId() const { return destinationId; }
int Vehicle::getCapacityRange() const { return capacityRange; }
int Vehicle::getRemainingRange() const { return remainingRange; }

// Setters
void Vehicle::setVehicleId(int vId) { vehicleId = vId; }
void Vehicle::setCurrentCityId(int currCityId) { currentCityId = currCityId; }
void Vehicle::setDestinationId(int destId) { destinationId = destId; }
void Vehicle::setCapacityRange(int capRange) { capacityRange = capRange; }
void Vehicle::setRemainingRange(int remRange) { remainingRange = remRange; }

// Display vehicle information
void Vehicle::displayVehicleInfo() const {

        cout << "[" << vehicleId << "," << destinationId << "," << capacityRange << "," << remainingRange << "]"<<"\n";
}

// Check if the vehicle can reach its destination
bool Vehicle::canReachDestination() const {
    return remainingRange >= capacityRange;  // Simplified check; actual implementation may vary
}

std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle) {
    os << "[" << vehicle.vehicleId<< "," << vehicle.destinationId << "," << vehicle.capacityRange << "," << vehicle.remainingRange << "]";
    return os;  // Return the output stream
}

int main() 
{
    /*
    Vehicle car{ 1, 101, 202, 500 };
    Vehicle car1(1, 102, 203, 501);
    car.displayVehicleInfo();
    vector <Vehicle> cars;
    cars.push_back(car);
    car.displayVehicleInfo();
    */
    

    ifstream fin;
    fin.open("Travel_Details.txt");
    if (fin.fail()) {
        cout << "This file could not be opened";
        exit(1);
    }
    //else
      //  cout << "File successfully opened"; WORKS
    ofstream fout;
    fout.open("New_Travel_Details.txt");
    if (fout.fail()) {
        cout << "This file could not be opened";
        exit(1);
    }
    //else
      //  cout << "File successfully opened"; WORKS
    char delimiter;
    int vehicleId = 0;
    int destinationId = 0;
    int capacityRange = 0;
    int remainingRange = 0;

    vector <Vehicle> cars;
    

    while (fin >> vehicleId) {
        fin.get(delimiter);
        fin >> destinationId;

        fin.get(delimiter);
        fin >> capacityRange;

        fin.get(delimiter);
        fin >> remainingRange;

        

        Vehicle v(vehicleId, destinationId, capacityRange, remainingRange);
        cars.push_back(v);
        //cout << v << endl; DOESNT WORK
        
    }
    cout << cars[0];
    
// int id = 2;  // Example: Using the city ID 0 for Sydney
    //ChargingStation city_obj(id);  // Create a City object with ID 0
    //city_obj.displayCityName();  // Display information about the city
    

    return 0;
}


/*
* /// this is the part for making a new file and using this to make a new file with random values for the vehicle and store them in a vector.

// Prac6task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    ofstream fout;
    fout.open("C:\\Users\\61449\\source\\repos\\Prac6task3\\neat.txt");

    if (fout.fail()) {
        cout << "Output file opening failed.\n";
        exit(1);
    }


    const int chMap[] = { 0, 0, 0, 0};
    int copyMap[] = { 0,0,0,0 };
    for (int i = 0; i < 3; i++)
    {
        int r;
        r = rand() % 10;
        copyMap[i] += copyMap[r];
    }
   // fout << copyMap[1];

    int x = 2;
    int y = 3;

    fout << "x + y = " << x + y;

    fout.close();
    return 0;
}


*/
