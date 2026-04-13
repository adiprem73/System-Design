#include<bits/stdc++.h>
using namespace std;

// Return Type Rule: 
// the subtype overriden method return type should be wither identical or narrower than the parentt method's return type.
// this is also called as return type covariance
//C++ enforces this by covariance

// it basically means that the return type of the overriding method in the child class must be same or narrower than the return type of the parent class method

class Animal {

};

class Dog: public Animal{

};

class Parent{
public:
    virtual Animal* getAnimal(){
        cout<<"Parent : Returning Animal Instance"<<endl;
        return new Animal();
    }
};

class Child: public Parent{
public:
    Dog* getAnimal() override {
        cout<<"Child : Returing dog instance"<<endl;
        return new Dog();
    }
};

class Client{
private:
    Parent* p;

public:
    Client(Parent* p){
        this->p=p;
    }

    void takeAnimal(){
        p->getAnimal();
    }
};

int main() {
    Parent* parent = new Parent();
    Child* child = new Child();

    Client* client = new Client(parent);
    client->takeAnimal();
    return 0;
}
//by ad73prem