#include <iostream>
#include <string>
using namespace std;

// Parent Class
class Car {
protected:
    string brand;
    string model;
    int speed;

public:
    Car(string b, string m) {
        brand = b;
        model = m;
        speed = 0;
    }

    void startEngine() {
        cout << brand << " " << model
             << " : Engine Started!" << endl;
    }

    void accelerate() {
        speed += 20;
        cout << "Current Speed: "
             << speed << " km/h" << endl;
    }

    void brake() {
        if (speed > 0)
            speed -= 10;

        cout << "Current Speed: "
             << speed << " km/h" << endl;
    }
};

// Child Class
class SportsCar : public Car {
private:
    bool turboMode;

public:
    SportsCar(string b, string m)
        : Car(b, m) {
        turboMode = false;
    }

    void enableTurbo() {
        turboMode = true;
        speed += 50;

        cout << "Turbo Mode Enabled!" << endl;
        cout << "Current Speed: "
             << speed << " km/h" << endl;
    }
};

int main() {

    SportsCar car("BMW", "M4");

    car.startEngine();
    car.accelerate();
    car.accelerate();
    car.enableTurbo();
    car.brake();

    return 0;
}