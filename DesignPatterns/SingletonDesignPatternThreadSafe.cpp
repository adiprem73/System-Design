#include<bits/stdc++.h>
using namespace std;

class Singleton
{
private: // let's nake the constructor private
    static Singleton *instance;
    static mutex mtx; // mutex to ensure thread safety

    Singleton()
    {
        cout << "Singleton Constructor Called. New Object Created" << endl;
    }

public:
    static Singleton *getInstance()
    {
        if (instance == nullptr)
        {
            lock_guard<mutex> lock(mtx); // lock the mutex to ensure thread safety
            if(instance == nullptr) {
                // double-checked locking to avoid multiple instances in multi-threaded environment{}
            instance = new Singleton();
            }
        }

        return instance;
    }
};

Singleton *Singleton::instance = nullptr; // initialize the static member variable to nullptr
mutex Singleton::mtx; // initialize the mutex

int main() {
    
    return 0;
}
//by ad73prem