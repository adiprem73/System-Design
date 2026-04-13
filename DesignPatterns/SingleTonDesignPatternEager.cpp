#include<bits/stdc++.h>
using namespace std;

class Singleton {
    private: // let's nake the constructor private

    static Singleton* instance;

    Singleton(){
        cout<<"Singleton Constructor Called. New Object Created"<<endl;
    }

    public:
    static Singleton* getInstance(){
        return instance;
    }
};

Singleton* Singleton::instance = new Singleton(); // initialize the static member variable to nullptr


// we provide an object at the time of initialisaton only. Hence, this is called eager initialization. The main advantage of this approach is that it is thread safe as the instance is created at the time of class loading and there is no need for synchronization. The main disadvantage is that the instance is created even if it is not used in the program, which can lead to resource wastage if the instance creation is expensive.

int main() {
    
    return 0;
}
//by ad73prem