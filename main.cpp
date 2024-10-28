#include <iostream>
#include "functions.hpp"
using namespace std;

int main(void) {
    // Vehicle vehicle1;
    // cout << vehicle1.getVehicleBrand() << endl;
    // cout << vehicle1.getVehicleColor() << endl;

    Vehicle *vehicle2 = new Vehicle(4, 60, "red", "vw");
    cout << vehicle2->getVehicleBrand() << endl;
    cout << vehicle2->getVehicleColor() << endl;
    
    return 0;
}