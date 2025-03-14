#include <iostream>

using namespace std;

int main() {
    int data = 42;  
    int* sharedObject = &data; 
    int numPointers;
    cout << "¬ведите количество указателей, которые нужно создать: ";
    cin >> numPointers;

    int** pointers = new int* [numPointers];

    for (int i = 0; i < numPointers; ++i) {
        pointers[i] = sharedObject; 
    }

    cout << "јдреса созданных указателей:" << endl;
    for (int i = 0; i < numPointers; ++i) {
        cout << "”казатель " << i + 1 << ": " << pointers[i] << endl; 
    }

    delete[] pointers; 
    pointers = nullptr; 

}