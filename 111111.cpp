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
    Vehicle() : model("Неизвестно"), year(0) {
        logMessage("Vehicle: Вызван конструктор по умолчанию");
    }

    Vehicle(string model, int year) : model(model), year(year) {
        logMessage("Vehicle: Вызван конструктор с параметрами");
    }

    virtual void display() const {
        cout << "Транспортное средство: Модель = " << model << ", Год = " << year;
    }

    virtual ~Vehicle() {
        logMessage("Vehicle: Вызван деструктор");
    }
};

class Car : public Vehicle {
private:
    int numDoors; 

public:
    Car() : numDoors(4) {
        logMessage("Car: Вызван конструктор по умолчанию");
    }

    Car(string model, int year, int numDoors) : Vehicle(model, year), numDoors(numDoors) {
        logMessage("Car: Вызван конструктор с параметрами");
    }

    void display() const override {
        Vehicle::display();
        cout << ", Количество дверей = " << numDoors << endl;
    }

    ~Car() override {
        logMessage("Car: Вызван деструктор");
    }
};

class Bike : public Vehicle {
private:
    bool hasBasket; 

public:
    Bike() : hasBasket(false) {
        logMessage("Bike: Вызван конструктор по умолчанию");
    }
    Bike(string model, int year, bool hasBasket) : Vehicle(model, year), hasBasket(hasBasket) {
        logMessage("Bike: Вызван конструктор с параметрами");
    }
    void display() const override {
        Vehicle::display();
        cout << ", Есть корзина = " << (hasBasket ? "Да" : "Нет") << endl;
    }
    ~Bike() override {
        logMessage("Bike: Вызван деструктор");
    }
};

int main() {
    const int NUM_VEHICLES = 3; 
    Vehicle* vehicles[NUM_VEHICLES];

    vehicles[0] = new Car("Toyota Camry", 2020, 4);
    vehicles[1] = new Bike("Giant", 2022, true);
    vehicles[2] = new Car("Ford Mustang", 2021, 2);

    logMessage("Вывод информации о транспортных средствах:");
    for (int i = 0; i < NUM_VEHICLES; ++i) {
        cout << "Транспортное средство " << i + 1 << ": ";
        vehicles[i]->display(); 
    }

    logMessage("Освобождение памяти:");
    for (int i = 0; i < NUM_VEHICLES; ++i) {
        delete vehicles[i]; 
        vehicles[i] = nullptr; 
    }

}