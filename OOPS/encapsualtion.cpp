#include <iostream>
#include <string>

using namespace std;

class Car
{
public:
    virtual void startEngine() = 0; // virtual means that the child function would need to define thiese methdos
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;
    virtual ~Car() {}
};

class SportsCar : public Car
{
public:
// charcaters
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    SportsCar(string b, string m)
    {
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0; // neautral
    }

    void startengine(){
        isEngineOn = true;
        cout<<brand << " "<<model<<" : Engine starts with a roar!"<<endl;
    }

    void shiftGear(int gear){
        if(!isEngineOn){
            cout<<brand<<" "<<model<<" : Enginer is off! cannot shiftt gear right now"<<endl;
            return;
        }
        currentGear = gear;
        cout<<brand<<" "<<model<<" : Shifted to gear "<< currentGear <<endl;

    }

    void accelerate(){
        if(!isEngineOn){
            cout<<brand<<" "<<model<<" Engine is Off! cannot accelerate,"<<endl;
            return;
        }
        currentSpeed+=20;
        cout<<brand<<" "<<model<<" : Accelerating to "<<currentSpeed<<"km/h"<<endl;
    }
};