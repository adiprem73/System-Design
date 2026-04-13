#include<bits/stdc++.h>
using namespace std;

class Car{
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    
public:
    Car(string b, string m){
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
    }

    // Common methods for all Cars
    void startEngine(){
        isEngineOn = true;
        cout<<brand<<" "<<model<<" : Engine started"<<endl;
    }

    void stopEngine(){
        isEngineOn = false;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned off" << endl;
    }

    void accelerate(){
        if(!isEngineOn){
            cout<<brand<<" "<<model<<" : Cannot accelerate as Engine is Off"<<endl;
            return;
        }
        currentSpeed+=20;
        cout<<brand<<" "<<model<<" : Accelerating to "<<currentSpeed<<" km/h "<<endl;
    }

    void brake(){
        currentSpeed -= 20;
        if(currentSpeed < 0)currentSpeed=0;
        cout << brand << " " << model << " Braking. Speed is now: " << currentSpeed << " km/h " << endl;
    }

    virtual ~Car() {}
};

class manualCar : public Car{
private:
    int currentGear;

public:
    manualCar(string b, string m) : Car(b,m){
        currentGear = 0;
    }

    void shiftGear(int gear){
        currentGear = gear;
        cout<<brand<<" "<<model<<" : Shifted the gear to "<<currentGear<<endl;
    }
};

class electricCar: public Car{
private:
    int batteryLevel;

public:
    electricCar(string b, string m) : Car(b,m){
        batteryLevel = 100;
    }

    void chargeBattery(){
        batteryLevel = 100;
        cout<<brand<<" "<<model<<" : Battery is fully charged now"<<endl;
    }
};

int main() {
    manualCar* bmw = new manualCar("bmw", "m4");
    bmw->startEngine();
    bmw->shiftGear(1);
    bmw->accelerate();
    bmw->accelerate();
    bmw->brake();
    bmw->stopEngine();

    return 0;
}
//by ad73prem