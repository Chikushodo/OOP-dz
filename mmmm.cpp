#include <iostream>
#include <list>

using namespace std;

// (Observer)
class Student {
public:
    virtual void update() = 0; 
    virtual ~Student() {}
};

// (Subject)
class Teacher {
private:
    list<Student*> students; 

public:
    void attach(Student* student) {
        students.push_back(student);
    }
    void detach(Student* student) {
        students.remove(student);
    }

    void notify() {
        for (Student* student : students) {
            student->update();
        }
    }

    void wrapUp() {
        cout << "Преподаватель: Можете собираться и идти домой!" << endl;
        notify(); 
    }
};


class PackingStudent : public Student {
public:
    void update() override {
        cout << "Студент, собирающий вещи: Начинаю собирать свои вещи." << endl;
    }
};

class ComputerStudent : public Student {
public:
    void update() override {
        cout << "Студент, выключающий компьютер: Выключаю компьютер." << endl;
    }
};

class RushingStudent : public Student {
public:
    void update() override {
        cout << "Студент, спешащий уйти: Выбегаю из аудитории!" << endl;
    }
};


int main() {
    Teacher teacher;
    PackingStudent* packingStudent = new PackingStudent();
    ComputerStudent* computerStudent = new ComputerStudent();
    RushingStudent* rushingStudent = new RushingStudent();

    teacher.attach(packingStudent);
    teacher.attach(computerStudent);
    teacher.attach(rushingStudent);

    teacher.wrapUp();

    cout << endl << "Отписываем спешащего студента и завершаем занятие еще раз:" << endl;
    teacher.detach(rushingStudent);

    teacher.wrapUp();

    delete packingStudent;
    delete computerStudent;
    delete rushingStudent;
}