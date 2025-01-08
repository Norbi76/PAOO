#define STRSIZE 10
#include <cstring>
#include <string>
#include <vector>
#include <memory>
#include <iostream>
using namespace std;

class Vehicle
{
private:
    shared_ptr<int> nrOfWheels;
    shared_ptr<int> hp;
    unique_ptr<char[]> color;
    unique_ptr<char[]> brand;

    // Private helper function to copy data members
    void copyFrom(const Vehicle &other)
    {
        nrOfWheels = make_shared<int>(*other.nrOfWheels);
        hp = make_shared<int>(*other.hp);
        color = make_unique<char[]>(STRSIZE);
        brand = make_unique<char[]>(STRSIZE);
        strcpy(color.get(), other.color.get());
        strcpy(brand.get(), other.brand.get());
    }

public:
    // Default constructor
    Vehicle() : nrOfWheels(nullptr), hp(nullptr), color(nullptr), brand(nullptr) {}

    // Normal constructor
    Vehicle(int initial_nrOfWheels, int initial_hp, const char *initial_color, const char *initial_brand)
        : nrOfWheels(make_shared<int>(initial_nrOfWheels)), hp(make_shared<int>(initial_hp)), color(make_unique<char[]>(STRSIZE)), brand(make_unique<char[]>(STRSIZE))
    {
        strcpy(color.get(), initial_color);
        strcpy(brand.get(), initial_brand);
    }

    // Copy constructor
    Vehicle(const Vehicle &other)
    {
        copyFrom(other);
    }

    // Move constructor
    Vehicle(Vehicle &&other) noexcept
        : nrOfWheels(move(other.nrOfWheels)), hp(move(other.hp)), color(move(other.color)), brand(move(other.brand)) {}

    // Copy assignment operator using copy-and-swap idiom
    Vehicle &operator=(const Vehicle &other)
    {
        if (this != &other)
        {
            Vehicle temp(other);
            swap(*this, temp);
        }
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
        return color.get();
    }

    const char *getVehicleBrand() const
    {
        return brand.get();
    }

    void printCarData(const Vehicle &car) const
    {
        cout << "Brand: " << car.getVehicleBrand() << ", Color: " << car.getVehicleColor()
             << ", HP: " << car.getHp() << ", Wheels: " << car.getNrOfWheels() << endl;
    }
};

class CarFactory
{
public:
    // Function to deliver a car to a dealership
    static shared_ptr<Vehicle> deliverCar(int nrOfWheels, int hp, const char *color, const char *brand)
    {
        return make_shared<Vehicle>(nrOfWheels, hp, color, brand);
    }
};

class CarDealership
{
private:
    vector<shared_ptr<Vehicle>> inventory;

public:
    // Add a vehicle to the inventory
    void buyCar(shared_ptr<Vehicle> car)
    {
        inventory.push_back(car);
    }

    // Print the inventory
    void printInventory() const
    {
        cout << "Current Inventory:" << endl;
        for (const auto &car : inventory)
        {
            car->printCarData(*car);
        }
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