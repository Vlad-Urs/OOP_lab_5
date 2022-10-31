#pragma once
#include <iostream>
using namespace std;
#include "big_classes.h"
#include "colors.h"

class Reactor: public Hardware{
    public:

    int risk=0;

    void state(){
        if(risk > 90){
            red();
            cout << "the reactor has exploded\n";
        }
        else if(risk > 60){
            red();
            cout << "WARNING! the reactor is critically unstable\n";
        }
        else if(risk > 50){
            yellow();
            cout << "WARNING! the reactor is unstable\n";
        }
        else if(condition > 75){
            green();
            cout << "The reactor is in optimal condition\n";
        }
        else if(condition > 50){
            white();
            cout << "The reactor is in satisfactory condition\n";
        }
        else if(condition > 25){
            yellow();
            cout << "WARNING! the reactor is in dire need of repairs\n";
        }
        else if(condition <10){
            red();
            cout << "the reactor has stopped working\n";
        }
        else{
            red();
            cout << "WARNING! the reactor is in critical condition\n";
        }

    }
};

class Engine: public Hardware{
    public:

    Engine(int n){
        id = n;
    }

    void state(){
        if(condition > 75){
            green();
            cout << "Engine " << id << " is in optimal condition\n";
        }
        else if(condition > 50){
            white();
            cout << "Engine " << id << " is in satisfactory condition\n";
        }
        else if(condition > 25){
            yellow();
            cout << "Engine " << id << " is in dire need of repairs\n";
        }
        else if(condition < 10){
            red();
            cout << "Engine " << id << " has stopped working\n";
        }
        else{
            red();
            cout << "Engine " << id << " is in critical condition\n";
        }
    }

};

class Structural: public Hardware{
    public:

    void state(){
        white();
        cout << "the component is at ";
        yellow();
        cout << condition;
        cout << "%\n";
        if(condition==0){
            red();
            cout << "The component is off(or destroyed)\n";
        }
    }
};

class Shield: public Structural{
    public:

    void state(){
        white();
        cout << "the shield is at ";
        yellow();
        cout << condition;
        cout << "%\n";
        if(condition<=0){
            red();
            cout << "The shield was destroyed\n";
        }
    }
};

class Hull: public Structural{
    public:

    void state(){
       if (condition > 70){
        green();
        cout << "The hull is good condition\n";
       }
       else if(condition > 45){
        yellow();
        cout << "The hull is in need of repairs\n";
       }
       else if(condition > 9){
        red();
        cout << "The hull has been breached\n";
       }
       else{
        red();
        cout << "The hull has ruptured\n";
       }
    }
};

class Weapons: public Hardware{
    public:

    int accuracy;
    int damage;

    void shoot(){}
};

class Gun: public Weapons{
    public:

    int damage = 70;

    void shoot(){}
};

class Disruptor: public Weapons{
    public:

    void shoot(){}
};

class LifeSuport: public Hardware{
    public:

    int oxygen = 100;
    int food = 100;

    void state(){
        
        if(oxygen>=0){
            white();
            cout << "oxygen recycling at ";
            yellow();
            cout << oxygen;
            cout << "%\n";
        }
        if(oxygen<15){
            red();
            cout << "OXYGEN RECYCLING HAS HALTED\n";
        }

        if(food>=0){
            white();
            cout << "provisions remaining for ";
            yellow();
            cout << food;
            cout << " days\n";}
        if(food<=0){
            red();
            cout << "PROVISIONS HAVE RUN OUT\n";
        }
    }
};