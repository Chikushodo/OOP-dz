#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cout << "Введите размер вектора целых чисел: ";
    cin >> N;

    vector<int> numbers; 
    numbers.reserve(N);  

    cout << "Введите " << N << " чисел:" << endl;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        numbers.push_back(num); 
    }

    cout << "Числа в обратном порядке: ";
    for (int i = numbers.size() - 1; i >= 0; --i) {
        cout << numbers[i] << " "; 
    }
    cout << endl;

    cout << "\nВведите размер вектора строк: ";
    cin >> N;
    cin.ignore();

    vector<string> strings;
    strings.reserve(N);

    cout << "Введите " << N << " строк:" << endl;
    for (int i = 0; i < N; ++i) {
        string str;
        getline(cin, str); 
        strings.push_back(str); 
    }

    cout << "Попытка добавить еще один элемент..." << endl;
    string extraString;
    cout << "Введите дополнительную строку: ";
    getline(cin, extraString);
    strings.push_back(extraString); 

    cout << "Содержимое вектора строк:" << endl;
    for (const string& s : strings) { 
        cout << s << endl;
    }
}

