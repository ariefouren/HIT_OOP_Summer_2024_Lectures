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
    // for dynamic_cast, the base class should have
    // at least one virtual function to insure that the class is polymorphic
    // virtual destructor is a good candidate for this purpose
    virtual ~Machine() {
        cout << "Machine is destroyed." << endl;
    }
private: 
    double weight;
};

// Base class Vehicle virtually inherits from Machine
// in each object of classes derived from Vehicle, 
// there is only one copy of Machine object
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
// in case of multiple inheritance, the objects of derived classes
// can contain multiple copies of Vehicle object
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
// in case of multiple inheritance, the objects of derived classes
// can contain multiple copies of Vehicle object
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
// (due to virtual inheritance from Machine in Vehicle)
// and two copies of Vehicle, one from Car and one from Airplane
// (due to non-virtual inheritance from Vehicle in Car and Airplane)
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
    // class Machine is polymorphic, since it has a virtual destructor
    // therefore, all classes derived from Machine are polymorphic
    
    cout << "\n=== demonstrating dynamic upcast ===\n";
    
    // OK: upcasting from FlyinCar* to Vehicle* 
    // through Car* is unambiguous, since 
    // there is only one copy of Vehicle object in Car object
    Car* carPtr = dynamic_cast<Car*>(flyingCarPtr); 
    Vehicle* vehiclePtr1 = dynamic_cast<Vehicle*>(carPtr);
    if(vehiclePtr1 != nullptr) {
        cout << "Upcast from Car* to Vehicle* is correct." << endl;
        cout << "Vehicle (trough Car): serial number = " 
            << vehiclePtr1->getSerialNumber() << endl;
    }
    else {
        cout << "Upcast from Car* to Vehicle* is incorrect." << endl;
    }

    // OK: upcasting from FlyingCar* to Vehicle* 
    // through Airplane* is unambiguous, since
    // there is only one copy of Vehicle object in Airplane object
    Vehicle* vehiclePtr2 = dynamic_cast<Vehicle*>
        (dynamic_cast<Airplane*>(flyingCarPtr));
    if(vehiclePtr2 != nullptr) {
        cout << "Upcast from Airplane* to Vehicle* is correct." << endl;
        cout << "Vehicle (trough Airplane): serial number = " 
            << vehiclePtr2->getSerialNumber() << endl;
    }
    else {
        cout << "Upcast from Airplane* to Vehicle* is incorrect." << endl;
    }
    
    // OK: the upcasting from FlyingCar* to Machine* is unambiguous.
    // there is only one copy of Machine object in 
    // FlyingCar object due to virtual inheritance from Machine
    Machine* machinePtr = dynamic_cast<Machine*>(flyingCarPtr);
    if(machinePtr != nullptr) {
        cout << "Upcast from FlyingCar* to Machine* is correct." << endl;
    }
    else {
        cout << "Upcast from FlyingCar* to Machine* is incorrect." << endl;
    }

    // ERROR ! upcasting from FlyingCar* to Vehicle* is ambiguous
    // inheritance of Car and Airplane from Vehicle is not virtual, 
    // therefore there are two objects that represent Vehicle in FlyingCar
    // compilation error: ambiguous conversion from derived class 'FlyingCar' to base class 'Vehicle':
    /*
    Vehicle* vehiclePtr3 = dynamic_cast<Vehicle*>(flyingCarPtr);
    if(vehiclePtr3 != nullptr) {
        cout << "Upcast from FlyingCar* to Vehicle* is correct." << endl;
        cout << "Vehicle: serial number = " 
            << vehiclePtr3->getSerialNumber() << endl;
    }
    else {
        cout << "Upcast from FlyingCar* to Vehicle* is incorrect." << endl;
    }
    */

    cout << "\n\n=== demonstrating dynamic downcast ===\n";
    // OK, since each FlyingCar is a Machine
    machinePtr = flyingCarPtr; 

    // ERROR ! 
    // the FlyingCar object contains two Vehicle objects
    // therefore downcast from Machine* to Vehicle* is incorrect
    // the code will compile, but the result will be nullptr
    vehiclePtr1 = dynamic_cast<Vehicle*>(machinePtr); 
    if(vehiclePtr1 != nullptr) {
        cout << "Downcast from Machine* to Vehicle* is correct." << endl;
        cout << "vehiclePtr1->toString():" << vehiclePtr1->toString() << endl;
    }
    else {
        cout << "Downcast from Machine* to Vehicle* is incorrect." << endl;
    }
   
    // OK: downcast from Machine* to Car* is unambiguous  
    // since there is only one copy of Car object in FlyingCar object
    carPtr = dynamic_cast<Car*>(machinePtr);
    if(carPtr != nullptr) {
        cout << "Downcast from Machine* to Car* is correct." << endl;
        cout << "carPtr->toString():" << carPtr->toString() << endl;
    }
    else {
        cout << "Downcast from Machine* to Car* is incorrect." << endl;
    }

    // OK: downcast from Machine* to Airplane* is unambiguous
    // since there is only one copy of Airplane object in FlyingCar object
    Airplane* airplanePtr = dynamic_cast<Airplane*>(machinePtr);
    if(airplanePtr != nullptr) {
        cout << "Downcast from Machine* to Airplane* is correct." << endl;
        cout << "airplanePtr->toString():" << airplanePtr->toString() << endl;
    }
    else {
        cout << "Downcast from Machine* to Airplane* is incorrect." << endl;
    }

    // OK: downcast from Machine* to FlyingCar* is unambiguous 
    // since there is only one copy of FlyingCar object in FlyingCar object 
    FlyingCar* flyingCarPtr2 = dynamic_cast<FlyingCar*>(machinePtr);
    if(flyingCarPtr2 != nullptr) {
        cout << "Downcast from Machine* to FlyingCar* is correct." << endl;
        cout << "flyingCarPtr2->toString():" << flyingCarPtr2->toString() << endl;
        cout << "\nFlyingCar: Car serial number: " <<
        flyingCarPtr2->Car::getSerialNumber() << endl;
        cout << "FlyingCar: Airplane serial number: " <<
        flyingCarPtr2->Airplane::getSerialNumber() << endl<< endl;
    }
    else {
        cout << "Downcast from Machine* to FlyingCar* is incorrect." << endl;
    }
   
    // OK
    vehiclePtr1 = dynamic_cast<Vehicle*>
        (dynamic_cast<Car*>
            (dynamic_cast<FlyingCar*>(machinePtr)));
    if(vehiclePtr1 != nullptr) {
        cout << "Downcast from Machine* to FlyingCar* to Car* to Vehicle* is correct." << endl;
        cout << "Vehicle (trough Car): serial number = "
        << vehiclePtr1->getSerialNumber() << endl;
    }
    else {
        cout << "Downcast from FlyingCar* to Car* to Vehicle* is incorrect." << endl;
    }
             
    // OK
    vehiclePtr2 = dynamic_cast<Vehicle*>
        (dynamic_cast<Airplane*>
            (dynamic_cast<FlyingCar*>(machinePtr)));
    if(vehiclePtr2 != nullptr) {
        cout << "Downcast from Machine* to FlyingCar* to Airplane* to Vehicle* is correct." << endl;
        cout << "Vehicle (trough Airplane): serial number = " 
        << vehiclePtr2->getSerialNumber() << endl;
    }
    else {
        cout << "Downcast from Machine* to Airplane* to Vehicle* is incorrect." << endl;
    }

    // demonstrating cross-casting
    cout << "\n=== demonstrating cross-casting ===\n";
    carPtr = dynamic_cast<Car*>(flyingCarPtr);
    if(carPtr != nullptr) {
        cout << "Car: serial number = "
            << carPtr->getSerialNumber() << endl;
    }
    else {
        cout << "Car: serial number = nullptr" << endl;
    }
    
    airplanePtr = dynamic_cast<Airplane*>(carPtr);
    if(airplanePtr != nullptr) {
        cout << "Airplane: serial number = "
            << airplanePtr->getSerialNumber() << endl;
    }
    else {
        cout << "Airplane: serial number = nullptr" << endl;
    }

   return 0;
}