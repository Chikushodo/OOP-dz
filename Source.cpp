#include <iostream>

using namespace std;

class DynamicArray {
private:
    int* data;       
    int size;        
    int capacity;   

public:
    DynamicArray(int initialCapacity = 10) : size(0), capacity(initialCapacity) {
        cout << initialCapacity << endl;
        data = new int[capacity];
    }

    ~DynamicArray() {
        cout << "Вызван деструктор" << endl;
        delete[] data; 
    }

    DynamicArray(const DynamicArray& other) : size(other.size + 1), capacity(other.capacity + 1) {
        cout << "Вызван конструктор копирования" << endl;
        cout << "   Копирование размера: " << other.size << " -> " << size << endl;
        cout << "   Копирование вместимости: " << other.capacity << " -> " << capacity << endl;

        data = new int[capacity];
        cout << "   Выделена новая память для " << capacity << " элементов" << endl;

        for (int i = 0; i < other.size; ++i) {
            data[i] = other.data[i] + 1; 
            cout << "   Копирование элемента " << i << ": " << other.data[i] << " -> " << data[i] << endl;
        }
        cout << "Конструктор копирования завершен" << endl;
    }
    void add(int value) {
        if (size == capacity) {
            int newCapacity = capacity * 2;
            cout << "Увеличение capacity с " << capacity << " до " << newCapacity << endl;
            int* newData = new int[newCapacity];
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        data[size] = value;
        size++;
    }

    int getSize() const { return size; }
    int getCapacity() const { return capacity; }

    int getElement(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        }
        else {
            cout << "Ошибка: Индекс за пределами допустимого диапазона." << endl;
            return -1; 
        }
    }

    void setElement(int index, int value) {
        if (index >= 0 && index < size) {
            data[index] = value;
        }
        else {
            cout << "Ошибка: Индекс за пределами допустимого диапазона." << endl;
        }
    }
    void print() const {
        cout << "Массив: [";
        for (int i = 0; i < size; ++i) {
            cout << data[i];
            if (i < size - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    DynamicArray arr1(5);
    arr1.add(10);
    arr1.add(20);
    arr1.add(30);
    cout << "Исходный массив:" << endl;
    arr1.print();
    cout << "Размер: " << arr1.getSize() << ", Вместимость: " << arr1.getCapacity() << endl;

    cout << "\nСоздание копии..." << endl;
    DynamicArray arr2 = arr1; 
    cout << "Копия массива:" << endl;
    arr2.print();
    cout << "Размер: " << arr2.getSize() << ", Вместимость: " << arr2.getCapacity() << endl;

    cout << "\nИзменение элемента в копии..." << endl;
    arr2.setElement(0, 100);
    arr2.print();
    cout << "Исходный массив после изменения копии:" << endl;
    arr1.print();
}