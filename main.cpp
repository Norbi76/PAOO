#include <iostream>
#include "functions.hpp"
using namespace std;

int main(void) {
    Vehicle vehicle1(3, 50, "green", "bmw");
    cout << "Vehicle 1 data:" << endl;
    cout << vehicle1.getNrOfWheels() << endl;
    cout << vehicle1.getHp() << endl;
    cout << vehicle1.getVehicleBrand() << endl;
    cout << vehicle1.getVehicleColor() << endl;
    cout << endl;

    Vehicle vehicle1_copy = vehicle1;
    cout << "Vehicle 1 copy data:" << endl;
    cout << vehicle1_copy.getNrOfWheels() << endl;
    cout << vehicle1_copy.getHp() << endl;
    cout << vehicle1.getVehicleBrand() << endl;
    cout << vehicle1.getVehicleColor() << endl;
        
    
    return 0;
}