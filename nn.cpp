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
        cout << "� ����������" << endl;
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
        cout << "� � �������������" << endl;
    }
};

class LoudWrapper : public Wrapper {
public:
    LoudWrapper(IClient* client) : Wrapper(client) {}

    void Foo() override {
        cout << "������ ������" << endl;
        Wrapper::Foo();                 
        cout << "����� ������" << endl; 
    }
};

int main() {
    Client* client = new Client();    
    Wrapper* wrapper = new Wrapper(client); 

    cout << "����� Foo() ����� ���������:" << endl;
    wrapper->Foo(); 

    cout << endl << "����� Foo() ����� LoudWrapper:" << endl;

    Client* client2 = new Client();
    LoudWrapper* loudWrapper = new LoudWrapper(client2);
    loudWrapper->Foo();

    delete wrapper;  
    delete loudWrapper; 
}