#include<bits/stdc++.h>
using namespace std;

class Parent{
public: 
    virtual void print(string msg){
        cout<<"message : "<<msg<<endl;
    }
};

class Child : public Parent{
public:
    void print(string msg){
        cout<<"message from child : "<<msg<<endl;
    }
};

class Client {
private:
    Parent* p;
public:
    Client(Parent* p){
        this->p = p;
    }

    void printMsg(){
        p->print("Hello");
    }
};

int main() {
    Parent* parent = new Parent();
    Parent* child = new Child();

    Client* client = new Client(child);
    client->printMsg(); 
    return 0;
}
//by ad73prem