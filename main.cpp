#include <iostream>
#include "functions.hpp"
using namespace std;

int main(void) {
    Vehicle vehicle1(3, 50, "green", "bmw");
    Vehicle vehicle2(2, 2, "yellow", "pegas");
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
    cout << vehicle1_copy.getVehicleBrand() << endl;
    cout << vehicle1_copy.getVehicleColor() << endl;
    cout << endl;
    
    cout << "Vehicle 2 data" << endl;
    cout << vehicle2.getNrOfWheels() << endl;
    cout << vehicle2.getHp() << endl;
    cout << vehicle2.getVehicleBrand() << endl;
    cout << vehicle2.getVehicleColor() << endl;
    cout << endl;

    Vehicle vehicle3 = move(vehicle2);

    cout << "Vehicle 3 data" << endl;
    cout << vehicle3.getNrOfWheels() << endl;
    cout << vehicle3.getHp() << endl;
    cout << vehicle3.getVehicleBrand() << endl;
    cout << vehicle3.getVehicleColor() << endl;
    cout << endl;

    // cout << "Vehicle 2 data after move" << endl;
    // cout << vehicle2.getNrOfWheels() << endl;
    // cout << vehicle2.getHp() << endl;
    // cout << vehicle2.getVehicleBrand() << endl;
    // cout << vehicle2.getVehicleColor() << endl;
    // cout << endl;
    //Will create seg fault 

    
    return 0;
}