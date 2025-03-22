#include <iostream>
#include <string>

using namespace std;

// Базовый класс для генерации уникальных ID
class IDGenerator {
private:
    static int nextID; // Статическое поле для хранения следующего доступного ID
protected:
    int id; // Уникальный ID объекта
public:
    IDGenerator() { // Конструктор
        id = nextID++; // Получаем уникальный ID и увеличиваем счетчик
        cout << "IDGenerator: Создан ID " << id << endl;
    }

    virtual ~IDGenerator() { // Виртуальный деструктор для корректного вызова в производных классах
        cout << "IDGenerator: Уничтожен ID " << id << endl;
    }

    int getID() const { return id; } // Getter для получения ID
};

int IDGenerator::nextID = 1; // Инициализация статического поля

// Абстрактный класс Shape
class Shape : public IDGenerator {
public:
    virtual double calculateArea() const = 0; // Чисто виртуальный метод для вычисления площади
    virtual void displayInfo() const = 0; // Чисто виртуальный метод для вывода информации о фигуре
    virtual ~Shape() { // Виртуальный деструктор
        cout << "Shape: Уничтожается фигура с ID " << getID() << endl;
    }

    // Оператор сравнения (сравниваем площади фигур)
    bool operator==(const Shape& other) const {
        return calculateArea() == other.calculateArea();
    }

    // Оператор сложения (по умолчанию возвращает площадь)
    double operator+(const Shape& other) const {
        return calculateArea() + other.calculateArea();
    }
};

// Класс Circle (наследуется от Shape)
class Circle : public Shape {
private:
    double radius; // Радиус круга
public:
    Circle(double radius) : radius(radius) { // Конструктор
        cout << "Circle: Создан круг с ID " << getID() << " и радиусом " << radius << endl;
    }

    ~Circle() override { // Деструктор
        cout << "Circle: Уничтожается круг с ID " << getID() << endl;
    }

    double calculateArea() const override { // Переопределение метода вычисления площади
        return 3.14159 * radius * radius; // Площадь круга: π * r^2
    }

    void displayInfo() const override { // Переопределение метода вывода информации
        cout << "Круг: ID = " << getID() << ", Радиус = " << radius << ", Площадь = " << calculateArea() << endl;
    }

    void scale(double factor) { // Дополнительный метод: масштабирование круга
        radius *= factor;
        cout << "Circle: ID = " << getID() << " масштабирован, новый радиус = " << radius << endl;
    }
};

// Класс Sphere (наследуется от Circle, представляет трехмерную вариацию)
class Sphere : public Circle {
public:
    Sphere(double radius) : Circle(radius) { // Конструктор
        cout << "Sphere: Создана сфера с ID " << getID() << " и радиусом " << radius << endl;
    }

    ~Sphere() override { // Деструктор
        cout << "Sphere: Уничтожается сфера с ID " << getID() << endl;
    }

    double calculateVolume() const { // Метод для вычисления объема сферы
        return (4.0 / 3.0) * 3.14159 * radius * radius * radius; // Объем сферы: (4/3) * π * r^3
    }

    void displayInfo() const override { // Переопределение метода вывода информации
        cout << "Сфера: ID = " << getID() << ", Радиус = " << radius << ", Площадь поверхности = " << calculateArea()
            << ", Объем = " << calculateVolume() << endl;
    }
private:
    double radius = 0;
};

// Класс Rectangle (наследуется от Shape)
class Rectangle : public Shape {
private:
    double width;  // Ширина прямоугольника
    double height; // Высота прямоугольника
public:
    Rectangle(double width, double height) : width(width), height(height) { // Конструктор
        cout << "Rectangle: Создан прямоугольник с ID " << getID() << ", шириной " << width << " и высотой " << height << endl;
    }

    ~Rectangle() override { // Деструктор
        cout << "Rectangle: Уничтожается прямоугольник с ID " << getID() << endl;
    }

    double calculateArea() const override { // Переопределение метода вычисления площади
        return width * height; // Площадь прямоугольника: ширина * высота
    }

    void displayInfo() const override { // Переопределение метода вывода информации
        cout << "Прямоугольник: ID = " << getID() << ", Ширина = " << width << ", Высота = " << height
            << ", Площадь = " << calculateArea() << endl;
    }

    void stretch(double factor) { // Дополнительный метод: растяжение прямоугольника по ширине
        width *= factor;
        cout << "Rectangle: ID = " << getID() << " растянут, новая ширина = " << width << endl;
    }

    //Оператор сравнения для подсчета площади
    double operator+(const Rectangle& other) const {
        return calculateArea() + other.calculateArea();
    }
};

// Класс Cuboid (наследуется от Rectangle, представляет трехмерную вариацию)
class Cuboid : public Rectangle {
private:
    double depth; // Глубина кубоида
public:
    Cuboid(double width, double height, double depth) : Rectangle(width, height), depth(depth) { // Конструктор
        cout << "Cuboid: Создан кубоид с ID " << getID() << ", шириной " << width << ", высотой " << height << " и глубиной " << depth << endl;
    }

    ~Cuboid() override { // Деструктор
        cout << "Cuboid: Уничтожается кубоид с ID " << getID() << endl;
    }

    double calculateVolume() const { // Метод для вычисления объема кубоида
        return calculateArea() * depth; // Объем кубоида: площадь основания * глубина
    }

    void displayInfo() const override { // Переопределение метода вывода информации
        cout << "Кубоид: ID = " << getID() << ", Ширина = " << width << ", Высота = " << height
            << ", Глубина = " << depth << ", Площадь поверхности = " << calculateArea() << ", Объем = " << calculateVolume() << endl;
    }
};

int main() {
    const int MAX_SHAPES = 10; // Максимальное количество фигур в массиве
    Shape* shapes[MAX_SHAPES]; // Массив указателей на Shape
    int shapeCount = 0;      // Счетчик текущего количества фигур

    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить фигуру\n";
        cout << "2. Вывести информацию о фигурах\n";
        cout << "3. Сравнить две фигуры\n";
        cout << "4. Сложить площади двух фигур\n";
        cout << "5. Выход\n";
        cout << "Выберите опцию: ";
        cin >> choice;

        switch (choice) {
        case 1: { // Add shape
            if (shapeCount >= MAX_SHAPES) {
                cout << "Достигнуто максимальное количество фигур." << endl;
                break;
            }

            int shapeType;
            cout << "\nВыберите тип фигуры:\n";
            cout << "1. Круг\n";
            cout << "2. Сфера\n";
            cout << "3. Прямоугольник\n";
            cout << "4. Кубоид\n";
            cout << "Выберите опцию: ";
            cin >> shapeType;

            switch (shapeType) {
            case 1: { // Add Circle
                double radius;
                cout << "Введите радиус круга: ";
                cin >> radius;
                shapes[shapeCount++] = new Circle(radius);
                break;
            }
            case 2: { // Add Sphere
                double radius;
                cout << "Введите радиус сферы: ";
                cin >> radius;
                shapes[shapeCount++] = new Sphere(radius);
                break;
            }
            case 3: { // Add Rectangle
                double width, height;
                cout << "Введите ширину прямоугольника: ";
                cin >> width;
                cout << "Введите высоту прямоугольника: ";
                cin >> height;
                shapes[shapeCount++] = new Rectangle(width, height);
                break;
            }
            case 4: { // Add Cuboid
                double width, height, depth;
                cout << "Введите ширину кубоида: ";
                cin >> width;
                cout << "Введите высоту кубоида: ";
                cin >> height;
                cout << "Введите глубину кубоида: ";
                cin >> depth;
                shapes[shapeCount++] = new Cuboid(width, height, depth);
                break;
            }
            default:
                cout << "Недопустимый ввод." << endl;
            }
            break;
        }
        case 2: { // Display Info
            if (shapeCount == 0) {
                cout << "Нет фигур для отображения." << endl;
                break;
            }
            cout << "\nИнформация о фигурах:\n";
            for (int i = 0; i < shapeCount; ++i) {
                shapes[i]->displayInfo();
            }
            break;
        }
        case 3: { // Compare
            if (shapeCount < 2) {
                cout << "Недостаточно фигур для сравнения." << endl;
                break;
            }
            int index1, index2;
            cout << "Введите индекс первой фигуры (0-" << shapeCount - 1 << "): ";
            cin >> index1;
            cout << "Введите индекс второй фигуры (0-" << shapeCount - 1 << "): ";
            cin >> index2;

            if (index1 >= 0 && index1 < shapeCount && index2 >= 0 && index2 < shapeCount) {
                if (*shapes[index1] == *shapes[index2]) {
                    cout << "Фигуры равны по площади." << endl;
                }
                else {
                    cout << "Фигуры не равны по площади." << endl;
                }
            }
            else {
                cout << "Недопустимые индексы." << endl;
            }
            break;
        }
        case 4: {//add areas
            if (shapeCount < 2) {
                cout << "Недостаточно фигур для сложения." << endl;
                break;
            }
            int index1, index2;
            cout << "Введите индекс первой фигуры (0-" << shapeCount - 1 << "): ";
            cin >> index1;
            cout << "Введите индекс второй фигуры (0-" << shapeCount - 1 << "): ";
            cin >> index2;

            if (index1 >= 0 && index1 < shapeCount && index2 >= 0 && index2 < shapeCount) {
                double area = *shapes[index1] + *shapes[index2];
                cout << "Сумма площадей фигур: " << area << endl;

            }
            else {
                cout << "Недопустимые индексы." << endl;
            }
            break;
        }
        case 5: // Exit
            cout << "Завершение работы." << endl;
            break;
        default:
            cout << "Недопустимый ввод." << endl;
        }
    } while (choice != 5);

    // Освобождение памяти
    for (int i = 0; i < shapeCount; ++i) {
        delete shapes[i];
    }

}