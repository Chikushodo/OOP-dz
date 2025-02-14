#include <iostream>
#include <string>

using namespace std;

class Pudge {
private:
    int health;
    int armor;

public:
    Pudge(int initialHealth, int initialArmor) : health(initialHealth), armor(initialArmor) {}

    void FreshMeat(int bonus) {
        health += bonus;
        armor += bonus;
        cout << "bonus " << bonus << "." << endl;
    }

    int getHealth() const { return health; }

    int getArmor() const { return armor; }
};

class Character : public Pudge {
private:
    string name;
    int strength;
    int agility;
    int intelligence;
    string* abilities;
    int numAbilities;

public:
    Character(string name, int strength, int agility, int intelligence, int initialHealth, int initialArmor)
        : name(name), strength(strength), agility(agility), intelligence(intelligence), Pudge(initialHealth, initialArmor), abilities(nullptr), numAbilities(0) {}

    ~Character() {
        cout << "Вызван деструктор для " << name << endl;
        delete[] abilities;
    }

    void addAbility(const string& ability) {
        string* newAbilities = new string[numAbilities + 1];
        for (int i = 0; i < numAbilities; ++i) {
            newAbilities[i] = abilities[i];
        }
        newAbilities[numAbilities] = ability;
        delete[] abilities;
        abilities = newAbilities;
        numAbilities++;
    }
    int simpleRandom(int max) {
        static unsigned long next = 1;
        next = next * 1103515245 + 12345;
        return (unsigned int)(next / 65536) % max;
    }

    void printRandomAbility() {
        if (numAbilities > 0) {
            int randomIndex = simpleRandom(numAbilities);
            cout << name << " использует способность: " << abilities[randomIndex] << endl;
        }
        else {
            cout << name << " не имеет способностей!" << endl;
        }
    }

    int calculateDamage(const string& stat, const string& ability) {
        int damage = 0;

        if (stat == "strength") {
            damage = strength * 2;
        }
        else if (stat == "agility") {
            damage = agility * 3;
        }
        else if (stat == "intelligence") {
            damage = intelligence * 4;
        }

        if (ability == "Hook") {
            damage += 20;
        }
        else if (ability == "Rot") {
            damage += 10;
        }

        return damage;
    }

    string getName() const { return name; }
};

int main() {
    Pudge pudge(500, -2);
    cout << "Initial Health: " << pudge.getHealth() << endl;
    cout << "Initial Armor: " << pudge.getArmor() << endl;
    pudge.FreshMeat(50);
    cout << "Current Health: " << pudge.getHealth() << endl;
    cout << "Current Armor: " << pudge.getArmor() << endl;

    Character hero("Axe", 25, 15, 10, 800, 10);
    hero.addAbility("Berserker's Call");
    hero.addAbility("Battle Hunger");
    hero.addAbility("Counter Helix");
    hero.addAbility("Culling Blade");

    hero.printRandomAbility();
    int damage = hero.calculateDamage("strength", "Berserker's Call");
    cout << hero.getName() << " наносит " << damage << " урона." << endl;
    Character hero2("Queen of Pain", 10, 20, 30, 600, 5);
    hero2.addAbility("Shadow Strike");
    hero2.addAbility("Blink");
    hero2.addAbility("Scream of Pain");
    hero2.addAbility("Sonic Wave");
    hero2.printRandomAbility();
    int damage2 = hero2.calculateDamage("intelligence", "Shadow Strike");
    cout << hero2.getName() << " наносит " << damage2 << " урона." << endl;
}