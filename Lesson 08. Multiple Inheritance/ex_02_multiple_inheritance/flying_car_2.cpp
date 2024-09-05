// File: flying_car_2.cpp
// demonstrating multiple inheritance and ambiguity resolution
//

#include <iostream>
#include <string>
using namespace std;

// Base class
class Vehicle
{
public:
    Vehicle(): serialNumber(++numVehicles) {
        cout << toString() << " is created." << endl;
    }
  
    ~Vehicle() {
        cout << toString() << " is destroyed." << endl;
    }

    int getSerialNumber() const {
        return serialNumber;
    }

    virtual string toString() const {
        return "Vehicle: [serial number = " + 
        to_string(serialNumber) + "]";
    }
    
private:
    int serialNumber;
    static int numVehicles;
};
// Initialize the static member of the Vehicle class
int Vehicle::numVehicles = 0;

// Derived class
class Car : public Vehicle {
public:
    Car(const string& brand) : brand(brand) {
        cout << toString() << " is created." << endl;
    }

    virtual void startEngine() {
        cout << "The car's engine started." << endl;
    }

    virtual string toString() const{
        return "Car: [Brand=" + brand + ", " + Vehicle::toString()
        + "]";
    }

    ~Car() {
        cout << toString() << " is destroyed." << endl;
    }

    private:
        string brand;
};

// Derived class
class Airplane: public Vehicle {
public:
    Airplane(const string& model) : model(model) {
        cout << toString() << " is created." << endl;
    }

    virtual void takeOff() {
        cout << "The airplane is taking off." << endl;
    }

    virtual string toString() const {
        return "Airplane: [Model=" + model + ", "
         + Vehicle::toString() + "]";
    }

    ~Airplane() {
        cout << toString() << " is destroyed." << endl;
    }

    private: 
        string model;
};

// class FlyingCar inherits from Car and Airplane
// each object of FlyingCar will have two copies of the serialNumber,
// one from Car and one from Airplane
class FlyingCar : public Car, public Airplane {
public:
    FlyingCar(const string& brand, const string& model)
        : Car(brand), Airplane(model) {
        cout << toString() << " is created." << endl;
    }

    // Override startEngine from Car
    virtual  void startEngine() override {
        cout << "The flying car's engine is starting." << endl;
    }

    // Override takeOff from Airplane
    virtual  void takeOff() override {
        cout << "The flying car is taking off like an airplane." << endl;
    }

    virtual string toString() const {
        return "FlyingCar: [" + Car::toString() + ", " + 
                                Airplane::toString() + "]";
    } 

    ~FlyingCar() {
        cout << toString() << " is destroyed." << endl;
    }
};

int main() {
    FlyingCar flyingCar("XYZ Motors", "Flying Carpet 2023");

    // demonstrating access to the member of the base class 
    cout << "\nflyingCar.Car::getSerialNumber() = " 
        << flyingCar.Car::getSerialNumber() << endl;

    cout << "flyingCar.Airplane::getSerialNumber() = "
        << flyingCar.Airplane::getSerialNumber() << endl << endl;

    // cout << flyingCar.getSerialNumber() << endl; // ERROR ! ambiguity

    return 0;
}