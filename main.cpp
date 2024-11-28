#include <iostream>
#include "functions.hpp"
using namespace std;

int main(void)
{
    // Normal constructor
    Vehicle vehicle1(3, 50, "green", "bmw");
    Vehicle vehicle2(2, 2, "yellow", "pegas");
    printCarData(vehicle1);

    // Copy constructor
    Vehicle vehicle1_copy = vehicle1;
    printCarData(vehicle1_copy, "Vehicle copy data");

    // Copy assignment operator
    Vehicle vehicle4(2, 2, "yellow", "pegas");
    vehicle4 = vehicle1;
    printCarData(vehicle4, "Vehicle copy assignment data");

    // Move constructor
    Vehicle vehicle3 = move(vehicle2);
    printCarData(vehicle3);
    // printCarData(vehicle2);
    // Will create seg fault because vehicle2 is moved to vehicle3

    Vehicle vehicle5;
    vehicle5 = vehicle3;
    printCarData(vehicle5, "Vehicle move assignment data");

    return 0;
}