// File: flying_car.cpp
// demonstrates multiple inheritance
//
#include <iostream>
#include <string>

using namespace std;

// Base class
class Car {
public:
    Car(const string& brand) : brand(brand) {
        cout << toString() << " is created." << endl;
    }

    virtual void startEngine() {
        cout << "The car's engine started." << endl;
    }

    virtual string toString() const{
        return "Car: [Brand=" + brand + "]";
    }

    ~Car() {
        cout << toString() << " is destroyed." << endl;
    }

    private:
        string brand;
};

// Base class Airplane
class Airplane {
public:
    Airplane(const string& model) : model(model) {
        cout << toString() << " is created." << endl;
    }

    virtual void takeOff() {
        cout << "The airplane is taking off." << endl;
    }

    virtual string toString() const {
        return "Airplane: [Model=" + model + "]";
    }

    ~Airplane() {
        cout << toString() << " is destroyed." << endl;
    }

    private: 
        string model;
};

// Derived class FlyingCar inherits from both Car and Airplane
class FlyingCar : public Car, public Airplane {
public:
    FlyingCar(const string& brand, const string& model)
        : Car(brand), Airplane(model) {
        cout << toString() << " is created." << endl;
    }

    // Override startEngine from Car
    // 'override' keyword informs the compiler that 
    // we intend to override the base class functions. 
    // If the function signature in the derived class does 
    // not match a virtual function in the base class, 
    // or if there's no matching function in the base class, 
    // the compiler will generate an error
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

    // Demonstrate functions of FlyingCar
    cout << "\nFlyingCar Functions:\n";

    cout << "\nflyingCar.startEngine(): ";
    flyingCar.startEngine();    // Output: The flying car's engine is starting.
    cout << "flyingCar.Car::startEngine(): ";
    flyingCar.Car::startEngine(); // Access startEngine() of the basic class

    cout << "\nflyingCar.takeOff(): ";
    flyingCar.takeOff();        // Output: The flying car is taking off like an airplane.
    cout << "flyingCar.Airplane::takeOff(): ";
    flyingCar.Airplane::takeOff();// Access startEngine() of the basic class

    cout << "\nFlyingCar toString(): " << flyingCar.toString() << endl;
    cout << "flyingCar.Car::toString(): " << flyingCar.Car::toString() << endl;
    cout << "flyingCar.Airplane::toString(): " << flyingCar.Airplane::toString() << endl <<endl;

    return 0;
}