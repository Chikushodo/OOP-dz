#include <iostream>

using namespace std;

class FirstClass;

class SecondClass {
private:
    int num1;
    int num2;

public:
    SecondClass(int num1 = 0, int num2 = 0) : num1(num1), num2(num2) {}

    int getNum1() const { return num1; }
    int getNum2() const { return num2; }

    friend int addAllFields(const FirstClass& obj1, const SecondClass& obj2);
};

class FirstClass {
private:
    int num1;
    int num2;

public:
    FirstClass(int num1 = 0, int num2 = 0) : num1(num1), num2(num2) {}

    int getNum1() const { return num1; }
    int getNum2() const { return num2; }

    friend int addAllFields(const FirstClass& obj1, const SecondClass& obj2);
};

int addAllFields(const FirstClass& obj1, const SecondClass& obj2) {
    return obj1.getNum1() + obj1.getNum2() + obj2.getNum1() + obj2.getNum2();
}

int main() {
    FirstClass obj1(10, 20);
    SecondClass obj2(30, 40);

    int sum = addAllFields(obj1, obj2); 

    cout << "Сумма всех полей: " << sum << endl; 

}