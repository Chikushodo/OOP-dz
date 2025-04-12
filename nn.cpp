#include <iostream>

using namespace std;

class IClient {
public:
    virtual void Foo() = 0;
    virtual ~IClient() {}
};

class Client : public IClient {
public:
    void Foo() override {
        cout << "Я Клиентский" << endl;
    }
};

class Wrapper : public IClient {
protected:
    IClient* client; 

public:
    Wrapper(IClient* client) : client(client) {}
    virtual ~Wrapper() { delete client; } 

    void Foo() override {
        client->Foo();
        cout << "А я Декораторский" << endl;
    }
};

class LoudWrapper : public Wrapper {
public:
    LoudWrapper(IClient* client) : Wrapper(client) {}

    void Foo() override {
        cout << "НАЧАЛО ВЫЗОВА" << endl;
        Wrapper::Foo();                 
        cout << "КОНЕЦ ВЫЗОВА" << endl; 
    }
};

int main() {
    Client* client = new Client();    
    Wrapper* wrapper = new Wrapper(client); 

    cout << "Вызов Foo() через декоратор:" << endl;
    wrapper->Foo(); 

    cout << endl << "Вызов Foo() через LoudWrapper:" << endl;

    Client* client2 = new Client();
    LoudWrapper* loudWrapper = new LoudWrapper(client2);
    loudWrapper->Foo();

    delete wrapper;  
    delete loudWrapper; 
}