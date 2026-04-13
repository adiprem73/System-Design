#include<bits/stdc++.h>
using namespace std;

class Burger {
    public:
    virtual void prepare() = 0;
    virtual ~Burger() {}
};

class BasicBurger : public Burger{
    public:
    void prepare() override{
        cout<<"Preparing a basic burger with bun and patty."<<endl;
    }
};

class StandardBurger : public Burger {
    public:
    void prepare() override{
        cout<< "Preparing a standard burger with bun patty cheese and lettuce" <<endl;
    }
};

class PremiumBurger : public Burger {
    public:
    void prepare() override{
        cout<<"Preparing a premium burger with bun patty cheese lettuce tomato and bacon"<<endl;
    }
};

class BasicWheatBurger : public Burger{
    public:
    void prepare() override {
        cout<< "prepareing a basic wheat burger";
    }
};

class StandardWheatBurger : public Burger{
    public: 
    void prepare() override{
        cout<<"preparing a standard wheat burger with bun patty cheese and lettuce"<<endl;
    }
};

class PremiumWheatBurger : public Burger{
    public:
    void prepare() override{
        cout<<"Preparing a premium wheat burger with bun patty cheese lettuce tomato and bacon"<<endl;
    }
};

class BurgerFactory{
    public:
    virtual Burger* createBurger(string & type) = 0; // abstract method to create a burger, which will be implemented by the concrete factory classes
};

class SinghBurger : public BurgerFactory{
    public:
    Burger* createBurger(string & type) override{
        if(type == "basic"){
            return new BasicBurger();
        }else if(type == "standard"){
            return new StandardBurger();
        }else if(type == "premium"){
            return new PremiumBurger();
        }else{
            cout<<"invalid burger type"<<endl;
            return nullptr;
        }
    }
};

class KingBurger : public BurgerFactory{
    public:
    Burger* createBurger(string & type) override{
        if(type == "basic"){
            return new BasicWheatBurger();
        }else if(type == "standard"){
            return new StandardWheatBurger();
        }else if(type == "premium"){
            return new PremiumWheatBurger();
        }else{
            cout<<"invalid burger type"<<endl;
            return nullptr;
        }
    }
};

int main() {
    string type = "basic";
    BurgerFactory* burgerFactory = new SinghBurger();
    Burger* burger = burgerFactory->createBurger(type);
    burger->prepare();
    return 0;
}
//by ad73prem