#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <string>
#include <vector>
#include "MenuItem.h"
using namespace std;

class Restaurant {
    private:
    static int nextRestaurnatId; // static variable to keep track of the next restaurant id
    int restaurantId;
    string name;
    string location;
    vector<MenuItem> menu;

    public:
    Restaurant (const string& name, const string& location){
        this->name = name;
        this->location = location;
        this->restaurantId = nextRestaurnatId++;
    }

    ~Restaurant(){
        cout<< "Destroying Restaurant: "<<name<<", and clearing its menu."<<endl;
        menu.clear(); // clear the menu vector to release memory
    }

    // getters and setters
    string getName() const {
        return name;
    }

    string getLocation() const {
        return location;
    }
    void setlocation(const string& loc){
        location = loc;
    }

    void addMenuItem(const MenuItem& item){
        menu.push_back(item);
    }

    const vector<MenuItem>& getMenu() const {
        return menu;
    }

    

};

int Restaurant::nextRestaurnatId = 0; // initialize the static variable to 1

#endif // RESTAURANT_H