#include<bits/stdc++.h>
using namespace std;

class Singleton {
    private: // let's nake the constructor private

    static Singleton* instance;

    Singleton(){
        cout<<"Singleton Constructor Called. New Object Created"<<endl;
    }

    public:
    static Singleton* getInstance(){ // a static method belongs to the class and not the object. so to call this we do not need to create an object of the class. we can directly call it using the class name. Also, these static methods are same for all objects.
        if(instance == nullptr){
            instance = new Singleton();
        }

        return instance;
    }
};

Singleton* Singleton::instance = nullptr; // initialize the static member variable to nullptr

int main() {

    /*
    Singleton* s1 = new Singleton();
    Singleton* s2 = new Singleton();  
    cout<<(s1==s2)<<endl; // this will print false as both s1 and s2 are different objects in memory  */


    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    cout<<(s1==s2)<<endl; // this will print true as both s1 and s2 are pointing to the same object in memory which is created by the getInstance() method. Hence, we have only one instance of the Singleton class in the entire program. This is the main idea behind the Singleton design pattern. It ensures that there is only one instance of a class and provides a global point of access to that instance.
    return 0;
}
//by ad73prem