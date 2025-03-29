#include <iostream>
#include <string>
#include <stdexcept>  

using namespace std;

int main() {
    int numerator, denominator;

    try {
        cout << "������� ���������: ";
        if (!(cin >> numerator)) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            throw invalid_argument("������������ ����: ��������� ������ ���� ����� ������.");
        }

        cout << "������� �����������: ";
        if (!(cin >> denominator)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("������������ ����: ����������� ������ ���� ����� ������.");
        }

        if (denominator == 0) {
            throw runtime_error("������: ������� �� ����!");
        }

        double result = static_cast<double>(numerator) / denominator;
        cout << "��������� �������: " << result << endl;

    }
    catch (const runtime_error& error) {
        cerr << "������ ������� ����������: " << error.what() << endl;
    }
    catch (const invalid_argument& error) {
        cerr << "������ �����: " << error.what() << endl;
    }
    catch (...) {
        cerr << "����������� ������!" << endl;
    }
}