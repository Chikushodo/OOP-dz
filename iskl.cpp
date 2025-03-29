#include <iostream>
#include <string>
#include <stdexcept>  

using namespace std;

int main() {
    int numerator, denominator;

    try {
        cout << "Введите числитель: ";
        if (!(cin >> numerator)) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            throw invalid_argument("Некорректный ввод: числитель должен быть целым числом.");
        }

        cout << "Введите знаменатель: ";
        if (!(cin >> denominator)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Некорректный ввод: знаменатель должен быть целым числом.");
        }

        if (denominator == 0) {
            throw runtime_error("Ошибка: деление на ноль!");
        }

        double result = static_cast<double>(numerator) / denominator;
        cout << "Результат деления: " << result << endl;

    }
    catch (const runtime_error& error) {
        cerr << "Ошибка времени выполнения: " << error.what() << endl;
    }
    catch (const invalid_argument& error) {
        cerr << "Ошибка ввода: " << error.what() << endl;
    }
    catch (...) {
        cerr << "Неожиданная ошибка!" << endl;
    }
}