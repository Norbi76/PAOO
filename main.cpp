#include <iostream>
#include <cstring>
using namespace std;

# define STRSIZE 10

class Vehicle {
private: 
    int nrOfWheels, hp;
    char color[STRSIZE], brand[STRSIZE];
public:
    Vehicle(int initial_nrOfWheels, int initial_hp, char *initial_color, char *initial_brand) {
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
    Vehicle vehicle1(4, 60, "red", "vw");

    cout << vehicle1.getVehicleBrand() << endl;
    cout << vehicle1.getVehicleColor() << endl;
    
    return 0;
}