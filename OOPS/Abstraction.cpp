#include <iostream>
#include <string>

using namespace std;



class Car{
    public:
        virtual void startEngine()=0; // virtual means that the child function would need to define thiese methdos
        virtual void shiftGear(int gear) = 0;
        virtual void accelerate() = 0;
        virtual void brake() = 0;
        virtual void stopEngine() = 0;
        virtual ~Car(){}
};

class SportsCar: public Car{
    public:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;

        SportsCar(string b, string m){
            this->brand = b;
            this->model = m;
            isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0; // neautral
        }
};