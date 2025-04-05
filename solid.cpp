#include <iostream>
#include <string>

using namespace std;

// 1. Single Responsibility Principle

class Order {
private:
    string orderId;
    string* items;
    int itemCount;
    int maxItems;

public:
    Order(string orderId) : orderId(orderId), items(nullptr), itemCount(0), maxItems(5) {
        items = new string[maxItems];
    }

    ~Order() {
        delete[] items;
    }

    void addItem(string item) {
        if (itemCount < maxItems) {
            items[itemCount] = item;
            itemCount++;
            cout << "tovar '" << item << "' dobavlen v zakaz " << orderId << endl;
        }
        else {
            cout << "zakaz " << orderId << " polon." << endl;
        }
    }

    void removeItem(string item) {
        for (int i = 0; i < itemCount; ++i) {
            if (items[i] == item) {
                for (int j = i; j < itemCount - 1; ++j) {
                    items[j] = items[j + 1];
                }
                itemCount--;
                cout << "tovar '" << item << "' ydalen iz zakaza " << orderId << endl;
                return;
            }
        }
        cout << "tovar '" << item << "' ne naiden v tovare " << orderId << endl;
    }

    void printOrder() const {
        cout << "zakaz " << orderId << ":" << endl;
        for (int i = 0; i < itemCount; ++i) {
            cout << "- " << items[i] << endl;
        }
    }
};

class OrderPrinter {
public:
    void printOrder(const Order& order) const {
        order.printOrder(); 
    }
};

// 2. Open/Closed Principle 

class DiscountRule {
public:
    virtual double applyDiscount(double price) = 0; 
    virtual ~DiscountRule() {} 
};

class FixedDiscount : public DiscountRule {
private:
    double discountAmount;

public:
    FixedDiscount(double discountAmount) : discountAmount(discountAmount) {}

    double applyDiscount(double price) override {
        return price - discountAmount;
    }
};

class PercentageDiscount : public DiscountRule {
private:
    double discountPercentage;

public:
    PercentageDiscount(double discountPercentage) : discountPercentage(discountPercentage) {}

    double applyDiscount(double price) override {
        return price * (1 - discountPercentage / 100.0);
    }
};

// 3. Liskov Substitution Principle

class Item {
private:
    string name;
    double price;
    DiscountRule* discount;

public:
    Item(string name, double price, DiscountRule* discount = nullptr) : name(name), price(price), discount(discount) {}

    double getPrice() const {
        if (discount != nullptr) {
            return discount->applyDiscount(price);
        }
        else {
            return price;
        }
    }

    string getName() const { return name; }
};

int main() {
    Order myOrder("123");
    myOrder.addItem("Laptop");
    myOrder.addItem("Mouse");

    OrderPrinter printer;
    printer.printOrder(myOrder);
    FixedDiscount fixed(10);
    PercentageDiscount percentage(20);

    Item item1("Keyboard", 50, &fixed);
    Item item2("Monitor", 200, &percentage);
    Item item3("Headphones", 75);

    cout << item1.getName() << " cena so skidkoi: " << item1.getPrice() << endl;
    cout << item2.getName() << " cena so skidkoi: " << item2.getPrice() << endl;
    cout << item3.getName() << " cena: " << item3.getPrice() << endl;
}