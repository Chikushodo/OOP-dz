#include <iostream>

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
        cout << "bonus" << bonus << "." << endl;
    }
    int getHealth() const { return health; }
    int getArmor() const { return armor; }
};

int main() {
    Pudge pudge(500, -2);

    cout << "Initial Health: " << pudge.getHealth() << endl;
    cout << "Initial Armor: " << pudge.getArmor() << endl;
    pudge.FreshMeat(50);
    cout << "Current Health: " << pudge.getHealth() << endl;
    cout << "Current Armor: " << pudge.getArmor() << endl;

}