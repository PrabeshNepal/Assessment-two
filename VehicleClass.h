#pragma once // or use #ifndef/#define guards

class Vehicle {
private:
    int vehicleId;           // Unique ID for the vehicle
    int currentCityId;        // ID representing the current city
    int destinationId;        // ID representing the destination city
    int capacityRange;      // Maximum range the vehicle can cover (e.g., in kilometers)
    int remainingRange;     // Remaining range based on fuel or charge

public:
    // Constructor
    Vehicle(int vId, int destId, int capRange, int remRange);

    // Getters and Setters
    int getVehicleId() const;
    int getCurrentCityId() const;
    int getDestinationId() const;
    int getCapacityRange() const;
    int getRemainingRange() const;

    void setVehicleId(int vId);
    void setCurrentCityId(int currCityId);
    void setDestinationId(int destId);
    void setCapacityRange(int capRange);
    void setRemainingRange(int remRange);

    // Additional methods
    void displayVehicleInfo() const;
    bool canReachDestination() const; // Check if vehicle can reach its destination

    friend std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle);  // Declaration

  
};

