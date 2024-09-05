// File: flying_car_04.cpp
// demonstrating dynamic_cast with multiple inheritance
//

#include <iostream>
#include <string>
using namespace std;

// virtual base class
class Machine {
public:
    Machine(double weight = 1000) : weight(weight) {};
    virtual double getWeight() const { return weight; };

private: 
    double weight;

};

// Base class Vehicle virtually inherits from Machine
class Vehicle: virtual public Machine
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

// Derived class Car not-virtually inherits from Vehicle
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

// Derived class Airplane not-virtually inherits from Vehicle
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
// each object of FlyingCar contains one copy of Machine
// and two copies of Vehicle (one from Car and one from Airplane)
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
    FlyingCar* flyingCarPtr = 
        new FlyingCar("XYZ Motors", "Flying Carpet 2023");
   
    // for dynamic cast, the pointer should be to a polymorphic class
    // (class with at least one virtual function)
    
    // demonstrating dynamic upcast
    cout << "\n=== demonstrating dynamic upcast ===\n";
    
    // OK: upcasting from FlyinCar* to Vehicle* 
    // through Car* is unambiguous, since 
    // there is only one copy of Vehicle object in Car object
    Car* carPtr = dynamic_cast<Car*>(flyingCarPtr); 
    Vehicle* vehiclePtr1 = dynamic_cast<Vehicle*>(carPtr);
    cout << "Vehicle (trough Car): serial number = "
        << vehiclePtr1->getSerialNumber() << endl;

    // OK: upcasting from FlyingCar* to Vehicle* 
    // through Airplane* is unambiguous, since
    // there is only one copy of Vehicle object in Airplane object
    Vehicle* vehiclePtr2 = dynamic_cast<Vehicle*>
        (dynamic_cast<Airplane*>(flyingCarPtr));
    cout << "Vehicle (trough Airplane): serial number = "
        << vehiclePtr2->getSerialNumber() << endl;

    // OK: the upcasting from FlyingCar* to Machine* is unambiguous.
    // there is only one copy of Machine object in 
    // FlyingCar object due to virtual inheritance from Machine
    Machine* machinePtr = dynamic_cast<Machine*>(flyingCarPtr);

    // ERROR ! upcasting to base class "Vehicle" is ambiguous.
    // inheritance of Car and Airplane from Vehicle is not virtual, therefore 
    // there are two objects that represent Vehicle in FlyingCar
    // Vehicle* vehiclePtr3 = dynamic_cast<Vehicle*>(flyingCarPtr);

    
    // demonstrating dynamic downcast
    cout << "\n=== demonstrating dynamic downcast ===\n";
    // OK, since FlyingCar is a Machine
    machinePtr = flyingCarPtr; 

    // ERROR ! downcast from Machine* to Vehicle* is incorrect
    // and generates a run-time error
    // vehiclePtr1 = dynamic_cast<Vehicle*>(machinePtr);
    // cout << vehiclePtr1->toString() << endl;

    // OK. downcast from Machine* to Car* is unambiguous  
    carPtr = dynamic_cast<Car*>(machinePtr);

    // OK. downcast from Machine* to FlyingCar* is unambiguous  
    FlyingCar* flyingCarPtr2 = dynamic_cast<FlyingCar*>(machinePtr);
    
    cout << "\nFlyingCar: Car serial number: " <<
        flyingCarPtr2->Car::getSerialNumber() << endl;

    cout << "FlyingCar: Airplane serial number: " <<
        flyingCarPtr2->Airplane::getSerialNumber() << endl<< endl;

    // OK
    vehiclePtr1 = dynamic_cast<Vehicle*>
        (dynamic_cast<Car*>
            (dynamic_cast<FlyingCar*>(machinePtr)));
    cout << "Vehicle (trough Car): serial number = " 
        << vehiclePtr1->getSerialNumber() << endl;
         
    // OK
    vehiclePtr2 = dynamic_cast<Vehicle*>
        (dynamic_cast<Airplane*>
            (dynamic_cast<FlyingCar*>(machinePtr)));
    cout << "Vehicle (trough Airplane): serial number = " 
        << vehiclePtr2->getSerialNumber() << endl;

    // demonstrating cross-casting
    cout << "\n=== demonstrating cross-casting ===\n";
    carPtr = dynamic_cast<Car*>(flyingCarPtr);
    cout << "Car: serial number = "
        << carPtr->getSerialNumber() << endl;

    Airplane* airplanePtr = dynamic_cast<Airplane*>(carPtr);
    cout << "Airplane: serial number = "
        << airplanePtr->getSerialNumber() << endl;
   return 0;
}