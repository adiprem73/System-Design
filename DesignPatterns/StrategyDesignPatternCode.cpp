#include<bits/stdc++.h>
using namespace std;

// Strategy interface for walking
class WalkableRobot{
    public:
    virtual void walk() = 0;
    virtual ~WalkableRobot(){}
};

// concrete strategies for walk
class NormalWalk : public WalkableRobot{
    public:
    void walk() override{
        cout<<" waling normally "<<endl;
    }
};

class NoWalk : public WalkableRobot{
    public:
    void walk() override{
        cout<<"cannot walk"<<endl;
    }
};

// strategy interfave for talk
class TalkableRobot{
    public:
    virtual void talk() = 0;
    virtual ~TalkableRobot(){}
};

// concrete strategirs for talk
class NormalTalk : public TalkableRobot{
    public:
    void talk() override{
        cout<<"Taling normally" <<endl;
    }
};

class NoTalk : public TalkableRobot{
    public:
    void talk() override{
        cout<<"cannot talk"<<endl;
    }
};

// Strategy interface for fly
class FlyableRobot{
    public:
    virtual void fly() = 0;
    virtual ~FlyableRobot(){}
};

// concrete strategies for fly
class NormalFly : public FlyableRobot{
    public:
    void fly() override{
        cout<<"flying normally"<<endl;
    }
};

class NoFly : public FlyableRobot{
    public:
    void fly() override{
        cout<<"cannot fly"<<endl;
    }
};

// robot base class
class Robot{
    protected:
    WalkableRobot* walkStrategy; // these are dummy methods which will be called by the client and will call the actual method of the strategy class
    TalkableRobot* talkStrategy;
    FlyableRobot* flyStrategy;

    public:
    Robot(WalkableRobot* walk, TalkableRobot* talk, FlyableRobot* fly)
        : walkStrategy(walk), talkStrategy(talk), flyStrategy(fly) {}

    void walk(){
        walkStrategy->walk();
    }

    void talk(){
        talkStrategy->talk();
    }

    void fly(){
        flyStrategy->fly();
    }

    virtual void projection() = 0; // this is a pure virtual function which will be implemented by the concrete robot classes

    ~Robot(){
        delete walkStrategy;
        delete talkStrategy;
        delete flyStrategy;
    }
};

class CompanionRobot : public Robot{
    public:
    CompanionRobot(WalkableRobot* walk, TalkableRobot* talk, FlyableRobot* fly)
        : Robot(walk, talk, fly) {}

    void projection() override{
        cout<<"I am a companion robot"<<endl;
    }
};

class WorkerRobot : public Robot{
    public:
    WorkerRobot(WalkableRobot* walk, TalkableRobot* talk, FlyableRobot* fly)
        : Robot(walk, talk, fly) {}

    void projection() override{
        cout<<"I am a worker robot"<<endl;
    }
};

// the benefit of this design pattern is that we can change the behavior of the robot at runtime by changing the strategy object. For example, we can change the walk strategy of the robot from normal walk to no walk without changing the robot class. This makes our code more flexible and maintainable.

// hence in this code we try to implement Composition rathern than inheritance to achieve the same functionality. We have created separate classes for each behavior (walk, talk, fly) and then we have composed these behaviors in the robot class. This way we can change the behavior of the robot at runtime by changing the strategy object.

int main() {
    Robot *robot1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();

    cout<<"-----------------------------"<<endl;

    Robot *robot2 = new WorkerRobot(new NoWalk(), new NoTalk(), new NormalFly());
    robot2->walk();
    robot2->talk(); 
    robot2->fly();
    robot2->projection();
    return 0;
}
//by ad73prem