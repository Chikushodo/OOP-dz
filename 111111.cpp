#include <iostream>
#include <string>

using namespace std;

void logMessage(const string& message) {
    cout << message << endl;
}

class Vehicle {
protected:
    string model;
    int year;     

public:
    Vehicle() : model("����������"), year(0) {
        logMessage("Vehicle: ������ ����������� �� ���������");
    }

    Vehicle(string model, int year) : model(model), year(year) {
        logMessage("Vehicle: ������ ����������� � �����������");
    }

    virtual void display() const {
        cout << "������������ ��������: ������ = " << model << ", ��� = " << year;
    }

    virtual ~Vehicle() {
        logMessage("Vehicle: ������ ����������");
    }
};

class Car : public Vehicle {
private:
    int numDoors; 

public:
    Car() : numDoors(4) {
        logMessage("Car: ������ ����������� �� ���������");
    }

    Car(string model, int year, int numDoors) : Vehicle(model, year), numDoors(numDoors) {
        logMessage("Car: ������ ����������� � �����������");
    }

    void display() const override {
        Vehicle::display();
        cout << ", ���������� ������ = " << numDoors << endl;
    }

    ~Car() override {
        logMessage("Car: ������ ����������");
    }
};

class Bike : public Vehicle {
private:
    bool hasBasket; 

public:
    Bike() : hasBasket(false) {
        logMessage("Bike: ������ ����������� �� ���������");
    }
    Bike(string model, int year, bool hasBasket) : Vehicle(model, year), hasBasket(hasBasket) {
        logMessage("Bike: ������ ����������� � �����������");
    }
    void display() const override {
        Vehicle::display();
        cout << ", ���� ������� = " << (hasBasket ? "��" : "���") << endl;
    }
    ~Bike() override {
        logMessage("Bike: ������ ����������");
    }
};

int main() {
    const int NUM_VEHICLES = 3; 
    Vehicle* vehicles[NUM_VEHICLES];

    vehicles[0] = new Car("Toyota Camry", 2020, 4);
    vehicles[1] = new Bike("Giant", 2022, true);
    vehicles[2] = new Car("Ford Mustang", 2021, 2);

    logMessage("����� ���������� � ������������ ���������:");
    for (int i = 0; i < NUM_VEHICLES; ++i) {
        cout << "������������ �������� " << i + 1 << ": ";
        vehicles[i]->display(); 
    }

    logMessage("������������ ������:");
    for (int i = 0; i < NUM_VEHICLES; ++i) {
        delete vehicles[i]; 
        vehicles[i] = nullptr; 
    }

}