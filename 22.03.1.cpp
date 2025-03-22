#include <iostream>
#include <string>

using namespace std;

class ElectricVehicle {
protected:
    int batteryLevel; // ������� ������ �������

public:
    ElectricVehicle() : batteryLevel(100) {} // ����������� �� ��������� - ������ �������

    void charge(int amount) {
        batteryLevel += amount;
        if (batteryLevel > 100) {
            batteryLevel = 100;
        }
        cout << "ElectricVehicle: ����� ������� �������� �� " << amount << ". ������� �������: " << batteryLevel << endl;
    }

    void showBattery() const {
        cout << "ElectricVehicle: ������� ������� ������ �������: " << batteryLevel << endl;
    }

    virtual ~ElectricVehicle() {} // ����������� ����������
};

class LandTransport {
protected:
    int speed; // ��������

public:
    LandTransport() : speed(0) {} // ����������� �� ��������� - ����� �� �����

    virtual void accelerate(int value) {
        speed += value;
        cout << "LandTransport: �������� ��������� �� " << value << ". ������� ��������: " << speed << endl;
    }

    virtual void brake(int value) {
        speed -= value;
        if (speed < 0) {
            speed = 0;
        }
        cout << "LandTransport: �������� ��������� �� " << value << ". ������� ��������: " << speed << endl;
    }

    virtual ~LandTransport() {} // ����������� ����������

    virtual void displayMode() const {
        cout << "LandTransport: �������� �����" << endl;
    }
};

class WaterTransport {
protected:
    int depth; // �������

public:
    WaterTransport() : depth(0) {} // ����������� �� ��������� - �� �����������

    virtual void dive(int value) {
        depth += value;
        cout << "WaterTransport: ������� ��������� �� " << value << ". ������� �������: " << depth << endl;
    }

    virtual void surface(int value) {
        depth -= value;
        if (depth < 0) {
            depth = 0;
        }
        cout << "WaterTransport: ������� ��������� �� " << value << ". ������� �������: " << depth << endl;
    }

    virtual ~WaterTransport() {} // ����������� ����������

    virtual void displayMode() const {
        cout << "WaterTransport: ������ �����" << endl;
    }
};

class ElectricCar : public ElectricVehicle, public LandTransport {
public:
    void drive() {
        cout << "ElectricCar: ���� �� �����������!" << endl;
    }

    void commonMethod() {
        cout << "ElectricCar: ��� ������� �����!" << endl;
    }

    void accelerate(int value) override {
        LandTransport::accelerate(value);
        cout << "ElectricCar: ��������� � ���������������!" << endl;
    }

    void displayMode() const override {
        cout << "ElectricCar: �������� �����" << endl;
    }
};

class ElectricBoat : public ElectricVehicle, public WaterTransport {
public:
    void sail() {
        cout << "ElectricBoat: ������ �� �����������!" << endl;
    }

    void commonMethod() {
        cout << "ElectricBoat: ��� ������� �����!" << endl;
    }

    void dive(int value) override {
        WaterTransport::dive(value);
        cout << "ElectricBoat: ���������� � ���������������!" << endl;
    }

    void displayMode() const override {
        cout << "ElectricBoat: ������ �����" << endl;
    }
};

class AmphibiousVehicle : public ElectricCar, public ElectricBoat {
private:
    bool isInWaterMode; // ����, ������������ ������� ����� (true - ������, false - ��������)

public:
    AmphibiousVehicle() : isInWaterMode(false) {} // �������� �� ����

    void switchToLandMode() {
        if (isInWaterMode) {
            cout << "AmphibiousVehicle: ������� � �������� �����." << endl;
            isInWaterMode = false;
            ElectricCar::displayMode();
        }
        else {
            cout << "AmphibiousVehicle: ��� � �������� ������." << endl;
        }
    }

    void switchToWaterMode() {
        if (!isInWaterMode) {
            cout << "AmphibiousVehicle: ������� � ������ �����." << endl;
            isInWaterMode = true;
            ElectricBoat::displayMode();
        }
        else {
            cout << "AmphibiousVehicle: ��� � ������ ������." << endl;
        }
    }

    // ����� ������� � ���������� ������, �� �� ������ ������� �������
    void showCommonMethod() {
        if (isInWaterMode) {
            ElectricBoat::commonMethod();
        }
        else {
            ElectricCar::commonMethod();
        }
    }

    //�������������� virtual ����� ��� ������ �����������
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