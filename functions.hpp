# define STRSIZE 10
#include <cstring>
using namespace std;

class Vehicle {
private: 
    int *nrOfWheels, *hp;
    char *color, *brand;
public:
    //Normal constructor
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

    //Copy constructor
    Vehicle(const Vehicle &obj) {
        nrOfWheels = new int;
        hp = new int;
        color = new char[STRSIZE];
        brand = new char[STRSIZE];

        *nrOfWheels = *obj.nrOfWheels;
        *hp = *obj.hp;
        *color = *obj.color;
        *brand = *obj.brand;
    }

    //Deconstructor 
    ~Vehicle() {
        delete[] nrOfWheels, hp, color, brand;
    }

    int getHp() {
        return *hp;
    }

    int getNrOfWheels() {
        return *nrOfWheels;
    }

    char *getVehicleColor() {
        return color;
    }

    char *getVehicleBrand() {
        return brand;
    }
};

void printStr(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        cout << str[i];
    }
    cout << endl;
}