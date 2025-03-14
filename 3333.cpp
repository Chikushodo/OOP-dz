#include <iostream>

using namespace std;

int main() {
    int data = 42;  
    int* sharedObject = &data; 
    int numPointers;
    cout << "������� ���������� ����������, ������� ����� �������: ";
    cin >> numPointers;

    int** pointers = new int* [numPointers];

    for (int i = 0; i < numPointers; ++i) {
        pointers[i] = sharedObject; 
    }

    cout << "������ ��������� ����������:" << endl;
    for (int i = 0; i < numPointers; ++i) {
        cout << "��������� " << i + 1 << ": " << pointers[i] << endl; 
    }

    delete[] pointers; 
    pointers = nullptr; 

}