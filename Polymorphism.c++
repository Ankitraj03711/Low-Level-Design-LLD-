#include <iostream>
using namespace std;

// Base Class
class Car {
public:
    virtual void startEngine() {
        cout << "Starting Car Engine..." << endl;
    }

    virtual void accelerate() {
        cout << "Car is accelerating..." << endl;
    }

    virtual ~Car() {}
};

// Derived Class 1
class SportsCar : public Car {
public:
    void startEngine() override {
        cout << "BMW M4: Roaring V8 Engine Started!" << endl;
    }

    void accelerate() override {
        cout << "BMW M4 accelerates from 0-100 km/h in 4 seconds." << endl;
    }
};

// Derived Class 2
class ElectricCar : public Car {
public:
    void startEngine() override {
        cout << "Tesla Model 3: Powering On Silently..." << endl;
    }

    void accelerate() override {
        cout << "Tesla gives instant electric acceleration." << endl;
    }
};

int main() {

    Car *car;

    SportsCar sports;
    ElectricCar electric;

    // Points to SportsCar
    car = &sports;
    car->startEngine();
    car->accelerate();

    cout << endl;

    // Points to ElectricCar
    car = &electric;
    car->startEngine();
    car->accelerate();

    return 0;
}