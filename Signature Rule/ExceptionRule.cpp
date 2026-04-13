#include<bits/stdc++.h>
using namespace std;

// Exception rule:
// A subclass should throw fewer or narrower exceptions (but not additional or broader exceptions) than its parent.

// C++ does not enforces this rule. Hence, there is no compilcation error.

/*
Logic error--> for logical errors that are detected before the runtime
    invalid_argument--> invalid function argument
    domain_error--> function argument domain error
    lentgh_error--> exceeding valid length limits
    out_of_range--> array or container indes out of bounds

runtime_error--> for errors that occur at runtime
    range_error--> numeric result out of range
    overflow_error--> arithmetic overflow
    underflow_error--> 
*/

class Parent {
public:
    virtual void getValue() noexcept(false){
        throw logic_error("Parent error");
    }
};

class Child: public Parent{
public:
    void getValue() noexcept(false) override{
        throw out_of_range("Child error");
    }
};

class Client{
private:
    Parent* p;

public:
    Client(Parent* p){
        this->p= p;
    }
    
}

int main() {
    
    return 0;
}
//by ad73prem