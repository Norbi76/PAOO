# define STRSIZE 10
#include <cstring>
#include <string>
using namespace std;

class Vehicle {
private: 
    int *nrOfWheels, *hp;
    char *color, *brand;
public:
    //Default constructor
    Vehicle(): nrOfWheels(nullptr), hp(nullptr), color(nullptr), brand(nullptr) {}

    //Normal constructor
    Vehicle(int initial_nrOfWheels, int initial_hp, const char *initial_color, const char *initial_brand)
    : nrOfWheels(new int(initial_nrOfWheels)), hp(new int(initial_hp)), color(new char[STRSIZE]), brand(new char[STRSIZE])
    {
        strcpy(color, initial_color);
        strcpy(brand, initial_brand);
    }

    //Copy constructor
    Vehicle(const Vehicle &obj)
    : nrOfWheels(new int(*obj.nrOfWheels)), hp(new int(*obj.hp)), color(new char[STRSIZE]), brand(new char[STRSIZE])
    {
        strcpy(color, obj.color);
        strcpy(brand, obj.brand);
    }

    // Move constructor
    Vehicle(Vehicle&& other) noexcept: nrOfWheels(other.nrOfWheels), hp(other.hp), color(move(other.color)), brand(move(other.brand)) {
        other.nrOfWheels = 0;
        other.hp = 0;
        other.color = nullptr;
        other.brand = nullptr;
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

void printCarData(Vehicle veh, string message = "") {
    if (message == "") {
        cout << "Vehicle data " << veh.getVehicleBrand() << ":" << endl;
    }
    else {
        cout << message << " " << veh.getVehicleBrand() << ":" << endl;
    }

    cout << veh.getNrOfWheels() << endl;
    cout << veh.getHp() << endl;
    cout << veh.getVehicleBrand() << endl;
    cout << endl;
}

void printStr(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        cout << str[i];
    }
    cout << endl;
}