#include <iostream>
#include <cstring>
using namespace std;

# define STRSIZE 10

class Vehicle {
private: 
    int *nrOfWheels, *hp;
    char *color, *brand;
public:
    Vehicle(int initial_nrOfWheels, int initial_hp, const char *initial_color, const char *initial_brand) {
        nrOfWheels = new int;
        hp = new int;
        color = new char[STRSIZE];
        brand = new char[STRSIZE];
        
        *nrOfWheels = initial_nrOfWheels;
        *hp = initial_hp;
        strcpy(color, initial_color);
        strcpy(brand, initial_brand);
    }

    ~Vehicle() {
        delete[] nrOfWheels, hp, color, brand;
    }

    char *getVehicleColor() {
        return color;
    }

    char *getVehicleBrand() {
        return brand;
    }
};

int main(void) {
    // Vehicle vehicle1;
    // cout << vehicle1.getVehicleBrand() << endl;
    // cout << vehicle1.getVehicleColor() << endl;

    Vehicle *vehicle2 = new Vehicle(4, 60, "red", "vw");
    cout << vehicle2->getVehicleBrand() << endl;
    cout << vehicle2->getVehicleColor() << endl;
    
    return 0;
}