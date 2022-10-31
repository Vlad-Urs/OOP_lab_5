#pragma once
#include <iostream>
#include "colors.h"
using namespace std;
class Object{
    public:

    int id;
};

class Hardware: public Object{
    public:
    int condition=100;
    int RepairTime=0;
    

    virtual void state(){
       cout << "Tell state";
    }
    
};

class Humans: public Object{
    public:

    int skill;
    int numbers;
    int hapiness=100;
    int health=100;
    int HealingTime=0;
    int BusyStatus=0;
    string name;

    virtual void being(){
        cout << "tell being of any human";
    }
};

class OuterStuff: public Object{
    public:

    int distance;
};
