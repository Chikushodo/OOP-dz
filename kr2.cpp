#include <iostream>
#include <string>
// its so hard, im cry
// in street rain, in soul pain
using namespace std;

class Animal {
protected:
    string name;  
    int age;    

public:
    // konstruktor po ymolch
    Animal() : name("Unknown"), age(0) {}

    // s parametrami
    Animal(string n, int a) : name(n) {}

    //metod vivoda o animals
    virtual void display() const {
        cout << "name: " << name << ", age: " << age << endl;
    }

    // peregryz sravnenia
    bool operator==(const Animal& other) const {
        return (name == other.name && age == other.age);
    }

    // peregryz slogenia
    Animal operator+(const Animal& other) {
        return Animal(name + " & " + other.name, age + other.age);
    }

    // inkriment age
    Animal& operator++() {
        age++;
        return *this;
    }

    // destructor
    virtual ~Animal() {}
};

// xichnik 
class Predator : public Animal {
public:
    Predator(string n, int a) : Animal(n, a) {}

    void display() const override {
        cout << "predator: ";
        Animal::display();
    }
};

class Fish : public Animal {
public:
    Fish(string n, int a) : Animal(n, a) {}

    void display() const override {
        cout << "fish: ";
        Animal::display();
    }
};

// reptilia
class Reptile : public Animal {
public:
    Reptile(string n, int a) : Animal(n, a) {}

    void display() const override {
        cout << "reptile: ";
        Animal::display();
    }
};

// kollekcia animals
const int MAX_ANIMALS = 100; // max
Animal* animals[MAX_ANIMALS]; // massiv
int animalCount = 0; 

// add
void addAnimal() {
    if (animalCount >= MAX_ANIMALS) {
        cout << "dostignuto max" << endl;
        return;
    }

    string name;
    int age;

    cout << "vvedite animal: ";
    cin >> name;

    cout << "vvedite age animal: ";
    cin >> age;

    // vibor
    int type;
    cout << "viberite type animals: 1 - predator, 2 - fish, 3 - reptyle: ";
    cin >> type;

    // create object ot vibora 
    if (type == 1) {
        animals[animalCount++] = new Predator(name, age);
    }
    else if (type == 2) {
        animals[animalCount++] = new Fish(name, age);
    }
    else if (type == 3) {
        animals[animalCount++] = new Reptile(name, age);
    }

    cout << "animal successfully add" << endl;
}

// del animal po index
void removeAnimal() {
    int index;
    cout << "vvedite index animal for delete" << animalCount - 1 << "): ";
    cin >> index;

    delete animals[index]; // osvob pam
    for (int i = index; i < animalCount - 1; ++i) {
        animals[i] = animals[i + 1]; // sdvig elements
    }
    animalCount--; // ymenshenie animal
    cout << "animal successfully delete" << endl;
}

// vivod all animals
void displayAllAnimals() {
    if (animalCount == 0) {
        cout << "pusto :(" << endl;
        return;
    }
    for (int i = 0; i < animalCount; ++i) {
        cout << "index " << i << ": ";
        animals[i]->display(); // display kagdogo animal
    }
}

// sravnenie animals
void compareAnimals() {
    int index1, index2;

    cout << "vvedite index first animal (0-" << animalCount - 1 << "): ";
    cin >> index1;
    cout << "vvedite index second animal (0-" << animalCount - 1 << "): ";
    cin >> index2;

    if (*animals[index1] == *animals[index2]) {
        cout << "Животные равны." << endl;
    }
    else {
        cout << "Животные не равны." << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\nmenu:\n";
        cout << "1. add new animal\n";
        cout << "2. delete animal\n";
        cout << "3. vivesti vsex animal\n";
        cout << "4. sravnit two animals\n";
        cout << "5. exit\n";
        cout << "viberite opciy: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addAnimal();
            break;
        case 2:
            removeAnimal();
            break;
        case 3:
            displayAllAnimals();
            break;
        case 4:
            compareAnimals();
            break;
        case 5:
            cout << "zavershenie work" << endl;
            break;
        default:
            cout << "nedopustim vvod" << endl;
        }
    } while (choice != 5);

    for (int i = 0; i < animalCount; i++) {
        delete animals[i];
    }
}