#define STRSIZE 10
#include <cstring>
#include <string>
using namespace std;

class Vehicle
{
private:
    int *nrOfWheels, *hp;
    char *color, *brand;

    // Private helper function to copy data members
    void copyFrom(const Vehicle &other)
    {
        nrOfWheels = new int(*other.nrOfWheels);
        hp = new int(*other.hp);
        color = new char[STRSIZE];
        brand = new char[STRSIZE];
        strcpy(color, other.color);
        strcpy(brand, other.brand);
    }

public:
    // Default constructor
    Vehicle() : nrOfWheels(nullptr), hp(nullptr), color(nullptr), brand(nullptr) {}

    // Normal constructor
    Vehicle(int initial_nrOfWheels, int initial_hp, const char *initial_color, const char *initial_brand)
        : nrOfWheels(new int(initial_nrOfWheels)), hp(new int(initial_hp)), color(new char[STRSIZE]), brand(new char[STRSIZE])
    {
        strcpy(color, initial_color);
        strcpy(brand, initial_brand);
    }

    // Copy constructor
    Vehicle(const Vehicle &other)
    {
        copyFrom(other);
    }

    // Move constructor
    Vehicle(Vehicle &&other) noexcept
        : nrOfWheels(other.nrOfWheels), hp(other.hp), color(other.color), brand(other.brand)
    {
        other.nrOfWheels = nullptr;
        other.hp = nullptr;
        other.color = nullptr;
        other.brand = nullptr;
    }

    // Copy assignment operator using copy-and-swap idiom
    Vehicle &operator=(Vehicle other)
    {
        swap(*this, other);
        return *this;
    }

    // Move assignment operator using copy-and-swap idiom
    Vehicle &operator=(Vehicle &&other) noexcept
    {
        if (this != &other)
        {
            swap(*this, other);
        }
        return *this;
    }

    // Swap function
    friend void swap(Vehicle &first, Vehicle &second) noexcept
    {
        using std::swap;
        swap(first.nrOfWheels, second.nrOfWheels);
        swap(first.hp, second.hp);
        swap(first.color, second.color);
        swap(first.brand, second.brand);
    }

    // Destructor
    ~Vehicle()
    {
        delete nrOfWheels;
        delete hp;
        delete[] color;
        delete[] brand;
    }

    int getHp() const
    {
        return *hp;
    }

    int getNrOfWheels() const
    {
        return *nrOfWheels;
    }

    const char *getVehicleColor() const
    {
        return color;
    }

    const char *getVehicleBrand() const
    {
        return brand;
    }
};

void printCarData(const Vehicle &veh, const string &message = "")
{
    if (message == "")
    {
        cout << "Vehicle data " << veh.getVehicleBrand() << ":" << endl;
    }
    else
    {
        cout << message << " " << veh.getVehicleBrand() << ":" << endl;
    }

    cout << veh.getNrOfWheels() << endl;
    cout << veh.getHp() << endl;
    cout << veh.getVehicleBrand() << endl;
    cout << endl;
}

void printStr(const char *str)
{
    cout << str << endl;
}