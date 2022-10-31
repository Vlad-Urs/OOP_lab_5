#include <iostream>
#include <unistd.h>
#include <cstdlib>
using namespace std;
#include "big_classes.h"
#include "colors.h"
#include "hardware.h"
class Hostile: OuterStuff{
    public:

    int damage;
};

class Pirates: public Hostile{
    public:

    int numbers;
    int shield_rating;

    void attack(int &shld, int &sec,int &e1,int &e2,int &e3,int &e4,int &reac,int &pass,int &rsk,int &eng){
        numbers = rand()%20;
        shield_rating = clock()%100;
        damage = rand()%100;
        int dead;

        white();
        cout << "an unidentified ship has been sighted\n";
        usleep(5000000);
        Disruptor MainDisruptor;
        Gun MainGuns;

        if(shld>=damage){
            shld-=damage;
            red();
            cout << "the unidentified ship has attacked! they're pirates!\n";
            cout << "the shield took some damage\n";
        }
        else if(shld>0){
            damage-=shld;
            shld=0;
            red();
            cout << "the unidentified ship has attacked! they're pirates!\n";
            cout << "the shield was destroyed\n";
        }
        else{
            red();
            cout << "the unidentified ship has attacked! they're pirates!\n";
            if(rand()%2) e1=0;
            if(rand()%2) e2=0;
            if(rand()%2) e3=0;
            if(rand()%2) e4=0;
            if(rand()%2) rsk+=40;
            cout << "they went for the engines\n";
        }

        usleep(3000000);

        if(reac>=80){
            white();
            cout << "the ship used its energy disruptor to fry the pirates' computers\n";
            reac-=40; 
            usleep(5000000);
            return;
        }
        else{
            white();
            cout << "the ship cannot use the energy disruptor due to the bad state of the reactor\n";
        }

        white();
        cout << "the guns are engaging to fight the pirates\n";
        usleep(3000000);
        if(shield_rating<=MainGuns.damage){
            green();
            cout << "the guns have succesfully destroyed the pirates\n";
            usleep(5000000);
            return;
        }
        else{
            white();
            cout << "the guns could not destroy the pirates\n";
            usleep(3000000);
            cout << "pirates have entered the ship\n";
            cout << "security are dealing with them\n";
        }

        if(sec>numbers){
            green();
            cout << "security has managed to deal with the invading pirates!\n";
            dead=clock()%12;
            white();
            cout << "unfortunately, "<< dead << " security ops have perished\n";
            sec-=dead;
            dead=clock()%32;
            white();
            cout << "unfortunately, "<< dead << " passengers have perished\n";
            pass-=dead;

            dead=clock()%22;
            white();
            cout << "unfortunately, "<< dead << " engineers have perished\n";
            eng-=dead; 


            usleep(5000000);
            return;
        }
        else{
            if(clock()%2 && sec>0){
                green();
                cout << "security has managed to deal with the invading pirates!\n";
                dead=clock()%24;
                white();
                cout << "unfortunately, "<< dead << " security ops have perished\n";
                sec-=dead;
                dead=clock()%40;
                white();
                cout << "unfortunately, "<< dead << " passengers have perished\n";
                pass-=dead;
                rsk+=20;
                usleep(5000000);
                return;
            }
            else{
                red();
                cout << "security were overwhelmed by the number of pirates\n";
                sec=0;
            }
        }
    }
};

class Asteroid: public Hostile{
    public:

    int size;

    void strike(int &shld, int &hll,int &rsk){
        size = rand()%50;
        white();
        cout << "An asteroid has been detected, the guns are engaging to destroy it\n";
        usleep(5000000);
        Gun MainGuns;
        if(clock()%2){
            if(MainGuns.damage>=size){
                green();
                cout << "the guns have destroyed the asteroid\n";
            }
            else{
                white();
                cout << "the guns have partially destroyed the asteroid\n";
                size-=MainGuns.damage;
                if(shld>=size){
                    white();
                    cout << "the shield has endured some damage\n";
                    shld-=size;
                }
                else if(shld!=0){
                    white();
                    cout << "the shield has endured some damage\n";
                    size-=shld;
                    shld=0;
                    cout << "the hull has endured some damage\n";
                    hll-=size;
                }
                else{
                    white();
                    cout << "the hull has endured some damage\n";
                    hll-=size;
                    rsk+=20;
                }
            }
        }
        else{
            red();
            cout << "the guns have missed\n";
            if(shld>=size){
                    white();
                    cout << "the shield has endured some damage\n";
                    shld-=size;
                }
                else if(shld!=0){
                    white();
                    cout << "the shield has endured some damage\n";
                    size-=shld;
                    shld=0;
                    cout << "the hull has endured some damage\n";
                    hll-=size;
                }
                else{
                    white();
                    cout << "the hull has endured some damage\n";
                    hll-=size;
                    rsk+=20;
                }
        }

        usleep(5000000);
    }
};

class Station: public OuterStuff{
    public:

    string name;
    int oxygen;
    int resources;

    void replenish(int &fd,int &eng, int &sec,int &shld){
        white();

        resources=clock()%30;
        cout << "the foodstocks have been replenished to last " << resources << " more days\n";
        fd+=resources;
        usleep(2000000);

        resources=clock()%10;
        cout  << resources << " more engineers have been hired\n";
        eng+=resources;
        usleep(2000000);

        resources=clock()%10;
        cout  << resources << " more security ops have been hired\n";
        sec+=resources;
        usleep(2000000);
        
        if(clock()%2){
            cout << "a new shield has been purchased\n";
            shld=100;
        }
    }

};