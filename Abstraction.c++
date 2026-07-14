#include <iostream>
#include <string>
using namespace std;

// Abstract Class
// real life example 

class Car {
public:
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;

    virtual ~Car() {}
};

// Concrete Class
class SportsCar : public Car {
private:
    string brand;
    string model;
    bool engineOn;
    int currentSpeed;
    int currentGear;

public:
    SportsCar(string b, string m) {
        brand = b;
        model = m;
        engineOn = false;
        currentSpeed = 0;
        currentGear = 0;
    }

    void startEngine() override {
        if (!engineOn) {
            engineOn = true;
            cout << brand << " " << model
                 << " : Engine started!" << endl;
        }
    }

    void shiftGear(int gear) override {
        if (!engineOn) {
            cout << "Engine is off! Cannot shift gear." << endl;
            return;
        }

        currentGear = gear;
        cout << "Shifted to Gear " << currentGear << endl;
    }

    void accelerate() override {
        if (!engineOn) {
            cout << "Start the engine first." << endl;
            return;
        }

        currentSpeed += 20;
        cout << "Current Speed: "
             << currentSpeed << " km/h" << endl;
    }

    void brake() override {
        if (currentSpeed > 0)
            currentSpeed -= 10;

        cout << "Current Speed: "
             << currentSpeed << " km/h" << endl;
    }

    void stopEngine() override {
        if (currentSpeed == 0) {
            engineOn = false;
            cout << "Engine stopped." << endl;
        } else {
            cout << "Stop the car before turning off the engine."
                 << endl;
        }
    }
};

int main() {
    Car *car = new SportsCar("BMW", "M4");

    car->startEngine();
    car->shiftGear(1);
    car->accelerate();
    car->accelerate();
    car->brake();
    car->brake();
    car->shiftGear(2);
    car->brake();
    car->brake();
    car->stopEngine();

    delete car;

    return 0;
}