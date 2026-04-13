#include<bits/stdc++.h>
using namespace std;

class Burger {
    public:
    virtual void preprare() = 0; // pure virtual funtion which will be implemented by the concrete burger classes
    virtual ~Burger() {} // virtual destructor to ensure proper cleanup of derived classes
};

class BasicBurger : public Burger {
    public:
    void preprare() override {
        cout << "Preparing a basic burger with bun and patty." << endl;
    }
};

class StandardBurger : public Burger {
    public:
    void preprare() override {
        cout << "Preparing a standard burger with bun, patty, lettuce, and tomato." << endl;
    }
};

class premiumBurger : public Burger {
    public:
    void preprare() override {
        cout << "Preparing a premium burger with bun, patty, lettuce, tomato, cheese, and bacon." << endl;
    }
};

class BurgerFactory {
    public:
    static Burger* createBurger(string type) {
        if (type == "basic") {
            return new BasicBurger();
        } else if (type == "standard") {
            return new StandardBurger();
        } else if (type == "premium") {
            return new premiumBurger();
        } else {
            cout<<"invalid burger type"<<endl;
            return nullptr; // Return nullptr for unknown burger types
        }
    }
};

int main() {
    string type = "standard"; // This can be changed to "basic", "standard", or "premium
    BurgerFactory* myBurgerFactory = new BurgerFactory();
    Burger* burger = myBurgerFactory->createBurger(type);
    burger->preprare();
    return 0;
}
//by ad73prem