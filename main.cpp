#include <iostream>
#include "functions.hpp"
using namespace std;

int main(void) {
    Vehicle vehicle1(3, 50, "green", "bmw");
    Vehicle vehicle2(2, 2, "yellow", "pegas");
    
    printCarData(vehicle1);
    Vehicle vehicle1_copy = vehicle1;
    printCarData(vehicle1_copy, "Vehicle copy data");
    
    printCarData(vehicle2);
    Vehicle vehicle3 = move(vehicle2);
    printCarData(vehicle3);
    
    // printCarData(vehicle2);
    //Will create seg fault 

    
    return 0;
}