//1
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Weapon {
//public:
//    virtual string getDescription() const = 0;
//    virtual ~Weapon() {}
//};
//
//class Sword : public Weapon {
//public:
//    string getDescription() const override {
//        return "���: ������ ������ ��� �������� ���.";
//    }
//};
//
//class Axe : public Weapon {
//public:
//    string getDescription() const override {
//        return "�����: ������ ������ ��� �����.";
//    }
//};
//
//class Bow : public Weapon {
//public:
//    string getDescription() const override {
//        return "���: ������ ��� �������� ���.";
//    }
//};
//
//class Blacksmith {
//public:
//    virtual Weapon* createWeapon() = 0;
//    virtual ~Blacksmith() {}
//};
//
//class SwordBlacksmith : public Blacksmith {
//public:
//    Weapon* createWeapon() override {
//        return new Sword();
//    }
//};
//
//class AxeBlacksmith : public Blacksmith {
//public:
//    Weapon* createWeapon() override {
//        return new Axe();
//    }
//};
//
//class BowBlacksmith : public Blacksmith {
//public:
//    Weapon* createWeapon() override {
//        return new Bow();
//    }
//};
//
//int main() {
//    Blacksmith* swordSmith = new SwordBlacksmith();
//    Blacksmith* axeSmith = new AxeBlacksmith();
//    Blacksmith* bowSmith = new BowBlacksmith();
//
//    Weapon* sword = swordSmith->createWeapon();
//    Weapon* axe = axeSmith->createWeapon();
//    Weapon* bow = bowSmith->createWeapon();
//
//    cout << sword->getDescription() << endl;
//    cout << axe->getDescription() << endl;
//    cout << bow->getDescription() << endl;
//
//    delete sword;
//    delete axe;
//    delete bow;
//    delete swordSmith;
//    delete axeSmith;
//    delete bowSmith;
//
//}

//2
#include <iostream>
#include <string>

using namespace std;

class Government {
private:
    Government() {}

    static Government* instance;

    Government(const Government&);
    Government& operator=(const Government&);

    string policy = "����������� ������������ � �������������� �������.";

public:
    static Government* getInstance() {
        if (!instance) {
            instance = new Government();
        }
        return instance;
    }
    string getPolicy() const {
        return policy;
    }

    void setPolicy(const string& newPolicy) {
        policy = newPolicy;
        cout << "������������� �������� �������� ��: " << policy << endl;
    }

    ~Government() {
        cout << "����������� ���������� �������������." << endl;
        instance = nullptr;
    }
};

Government* Government::instance = nullptr;

int main() {
    Government* government1 = Government::getInstance();
    Government* government2 = Government::getInstance();

    cout << "����� government1: " << government1 << endl;
    cout << "����� government2: " << government2 << endl;

    cout << "������� ��������: " << government1->getPolicy() << endl;

    government2->setPolicy("�������� ��������� � ��������� �������.");

    cout << "������� ��������: " << government1->getPolicy() << endl;

    delete government1;
}