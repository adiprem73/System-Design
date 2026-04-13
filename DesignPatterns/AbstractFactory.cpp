#include<bits/stdc++.h>
using namespace std;

// Product 01
class Burger{
    public:
    virtual void prepare() = 0;
};

class BasicBurger : public Burger{
    public:
    void prepare() override{
        cout<<"Preparing a basic burger with bun and patty."<<endl;
    }
};

class StandardBurger : public Burger{
    public:
    void prepare() override{
        cout<<"Preparing a standard burger with bun, patty, lettuce, and tomato."<<endl;
    }
};

class PremiumBurger : public Burger{
    public:
    void prepare() override{
        cout<<"Preparing a premium burger with bun, patty, lettuce, tomato, cheese, and bacon."<<endl;
    }
};

class BasicWheatBurger : public Burger{
    public:
    void prepare() override{
        cout<<"Preparing a basic wheat burger with wheat bun and patty."<<endl;
    }
};

class StandardWheatBurger : public Burger{
    public:
    void prepare() override{
        cout<<"Preparing a standard wheat burger with wheat bun, patty, lettuce, and tomato."<<endl;
    }
};

class PremiumWheatBurger : public Burger{
    public:
    void prepare() override{
        cout<<"Preparing a premium wheat burger with wheat bun, patty, lettuce, tomato, cheese, and bacon."<<endl;
    }
};

// product 02: Garlic Bread
class GarlicBread{
    public:
    virtual void prepare() = 0;
};

class BasicGarlicBread : public GarlicBread{
    public:
    void prepare() override{
        cout<<"Preparing basic garlic bread with bread and garlic butter."<<endl;
    }
};

class StandardGarlicBread : public GarlicBread{
    public:
    void prepare() override{
        cout<<"Preparing standard garlic bread with bread, garlic butter, and herbs."<<endl;
    }
};

class PremiumGarlicBread : public GarlicBread{
    public:
    void prepare() override{
        cout<<"Preparing premium garlic bread with bread, garlic butter, herbs, and cheese."<<endl;
    }
};

class BasicWheatGarlicBread : public GarlicBread{
    public:
    void prepare() override{
        cout<<"Preparing basic wheat garlic bread with wheat bread and garlic butter."<<endl;
    }
};

class StandardWheatGarlicBread : public GarlicBread{
    public:
    void prepare() override{
        cout<<"Preparing standard wheat garlic bread with wheat bread, garlic butter, and herbs."<<endl;
    }
};

class PremiumWheatGarlicBread : public GarlicBread{
    public:
    void prepare() override{
        cout<<"Preparing premium wheat garlic bread with wheat bread, garlic butter, herbs, and cheese."<<endl;
    }
};

// Factory and its concretions
class MealFactory{
    public:
    virtual Burger* createBurger(string & type) = 0;
    virtual GarlicBread* createGarlicBread(string & type) = 0;
};

class SinghBurger : public MealFactory{
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

    GarlicBread* createGarlicBread(string & type) override{
        if(type == "basic"){
            return new BasicGarlicBread();
        }else if(type == "standard"){
            return new StandardGarlicBread();
        }else if(type == "premium"){
            return new PremiumGarlicBread();
        }else{
            cout<<"invalid garlic bread type"<<endl;
            return nullptr;
        }
    }
};

class KingBurger : public MealFactory{
    public:
    Burger* createBurger(string & type) override{
        if(type == "basic"){
            return new BasicWheatBurger();
        }else if(type == "standard"){
            return new StandardWheatBurger();
        }else if(type == "premium"){
            return new PremiumWheatBurger();
        }else{
            cout<<"invalid wheat burger type"<<endl;
            return nullptr;
        }
    }

    GarlicBread* createGarlicBread(string & type) override{
        if(type == "basic"){
            return new BasicWheatGarlicBread();
        }else if(type == "standard"){
            return new StandardWheatGarlicBread();
        }else if(type == "premium"){
            return new PremiumWheatGarlicBread();
        }else{
            cout<<"invalid wheat garlic bread type"<<endl;
            return nullptr;
        }
    }
};

int main() {
    
    return 0;
}
//by ad73prem