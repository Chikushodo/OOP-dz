#include <iostream>
#include <string>

using namespace std;

class ElectricVehicle {
protected:
    int batteryLevel; // Уровень заряда батареи

public:
    ElectricVehicle() : batteryLevel(100) {} // Конструктор по умолчанию - полная батарея

    void charge(int amount) {
        batteryLevel += amount;
        if (batteryLevel > 100) {
            batteryLevel = 100;
        }
        cout << "ElectricVehicle: Заряд батареи увеличен на " << amount << ". Текущий уровень: " << batteryLevel << endl;
    }

    void showBattery() const {
        cout << "ElectricVehicle: Текущий уровень заряда батареи: " << batteryLevel << endl;
    }

    virtual ~ElectricVehicle() {} // Виртуальный деструктор
};

class LandTransport {
protected:
    int speed; // Скорость

public:
    LandTransport() : speed(0) {} // Конструктор по умолчанию - стоит на месте

    virtual void accelerate(int value) {
        speed += value;
        cout << "LandTransport: Скорость увеличена на " << value << ". Текущая скорость: " << speed << endl;
    }

    virtual void brake(int value) {
        speed -= value;
        if (speed < 0) {
            speed = 0;
        }
        cout << "LandTransport: Скорость уменьшена на " << value << ". Текущая скорость: " << speed << endl;
    }

    virtual ~LandTransport() {} // Виртуальный деструктор

    virtual void displayMode() const {
        cout << "LandTransport: Наземный режим" << endl;
    }
};

class WaterTransport {
protected:
    int depth; // Глубина

public:
    WaterTransport() : depth(0) {} // Конструктор по умолчанию - на поверхности

    virtual void dive(int value) {
        depth += value;
        cout << "WaterTransport: Глубина увеличена на " << value << ". Текущая глубина: " << depth << endl;
    }

    virtual void surface(int value) {
        depth -= value;
        if (depth < 0) {
            depth = 0;
        }
        cout << "WaterTransport: Глубина уменьшена на " << value << ". Текущая глубина: " << depth << endl;
    }

    virtual ~WaterTransport() {} // Виртуальный деструктор

    virtual void displayMode() const {
        cout << "WaterTransport: Водный режим" << endl;
    }
};

class ElectricCar : public ElectricVehicle, public LandTransport {
public:
    void drive() {
        cout << "ElectricCar: Едем на электротяге!" << endl;
    }

    void commonMethod() {
        cout << "ElectricCar: Это обычный метод!" << endl;
    }

    void accelerate(int value) override {
        LandTransport::accelerate(value);
        cout << "ElectricCar: Ускорение с электроприводом!" << endl;
    }

    void displayMode() const override {
        cout << "ElectricCar: Наземный режим" << endl;
    }
};

class ElectricBoat : public ElectricVehicle, public WaterTransport {
public:
    void sail() {
        cout << "ElectricBoat: Плывем на электротяге!" << endl;
    }

    void commonMethod() {
        cout << "ElectricBoat: Это обычный метод!" << endl;
    }

    void dive(int value) override {
        WaterTransport::dive(value);
        cout << "ElectricBoat: Погружение с электроприводом!" << endl;
    }

    void displayMode() const override {
        cout << "ElectricBoat: Водный режим" << endl;
    }
};

class AmphibiousVehicle : public ElectricCar, public ElectricBoat {
private:
    bool isInWaterMode; // Флаг, определяющий текущий режим (true - водный, false - наземный)

public:
    AmphibiousVehicle() : isInWaterMode(false) {} // Начинаем на суше

    void switchToLandMode() {
        if (isInWaterMode) {
            cout << "AmphibiousVehicle: Переход в наземный режим." << endl;
            isInWaterMode = false;
            ElectricCar::displayMode();
        }
        else {
            cout << "AmphibiousVehicle: Уже в наземном режиме." << endl;
        }
    }

    void switchToWaterMode() {
        if (!isInWaterMode) {
            cout << "AmphibiousVehicle: Переход в водный режим." << endl;
            isInWaterMode = true;
            ElectricBoat::displayMode();
        }
        else {
            cout << "AmphibiousVehicle: Уже в водном режиме." << endl;
        }
    }

    // Вызов методов с одинаковым именем, но из разных базовых классов
    void showCommonMethod() {
        if (isInWaterMode) {
            ElectricBoat::commonMethod();
        }
        else {
            ElectricCar::commonMethod();
        }
    }

    //Переопределяем virtual метод для режима отображения
    void displayMode() const override {
        if (isInWaterMode) {
            ElectricBoat::displayMode();
        }
        else {
            ElectricCar::displayMode();
        }
    }
};

int main() {
    AmphibiousVehicle amphibiousVehicle;
    amphibiousVehicle.accelerate(30);

    amphibiousVehicle.switchToWaterMode();
    amphibiousVehicle.dive(10);
    amphibiousVehicle.sail();

    amphibiousVehicle.showCommonMethod();
    amphibiousVehicle.displayMode();

    amphibiousVehicle.switchToLandMode();
    amphibiousVehicle.brake(10);
    amphibiousVehicle.drive();

    amphibiousVehicle.showCommonMethod();
    amphibiousVehicle.displayMode();
}