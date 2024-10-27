#include <iostream>
#include <cstring>
using namespace std;

# define STRSIZE 10

class Vehicle {
private: 
    int nrOfWheels, hp;
    char color[STRSIZE] = "not set", brand[STRSIZE] = "not set";
public:
    Vehicle(){}

    Vehicle(int initial_nrOfWheels, int initial_hp, const char *initial_color, const char *initial_brand) {
        nrOfWheels = initial_nrOfWheels;
        hp = initial_hp;
        strcpy(color, initial_color);
        strcpy(brand, initial_brand);
    }

    char *getVehicleColor() {
        return color;
    }

    char *getVehicleBrand() {
        return brand;
    }
};

int main(void) {
    Vehicle vehicle1;
    cout << vehicle1.getVehicleBrand() << endl;
    cout << vehicle1.getVehicleColor() << endl;

    Vehicle *vehicle2 = new Vehicle(4, 60, "red", "vw");
    cout << vehicle2->getVehicleBrand() << endl;
    cout << vehicle2->getVehicleColor() << endl;
    
    return 0;
}