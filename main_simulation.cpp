#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "big_classes.h"
#include "hardware.h"
#include "humans.h"
#include "colors.h"
#include "outerstuff.h"
using namespace std;

float mood(int a, int b, int c){
    return (a+b+c)/4;
}

int main(){

    Reactor MainReactor;
    Shield MainShield;
    LifeSuport systemLS;
    Hull MainHull;

    Engine EngineOne(1);
    Engine EngineTwo(2);
    Engine EngineThree(3);
    Engine EngineFour(4);

    Engineers EngineerCore(20,9,"engineers");
    Medical MedicalCore(15,7,"medics");
    Security SecurityCore(50,"security");
    Passengers PassengersCore(200,"passengers");

    Asteroid asteroid1;
    Pirates pirateship;
    Station Astation;

    int days;
    system("clear");
    cout << "number of engineers: ";
    cin >> EngineerCore.numbers;
    cout << "number of medics: ";
    cin >> MedicalCore.numbers;
    cout << "number of security ops: ";
    cin >> SecurityCore.numbers;
    cout << "number of passengers: ";
    cin >> PassengersCore.numbers;
    cout << "journey length(days): ";
    cin >> days;

    
    systemLS.food=days+10;
    int i;
    int aux, GeneralMood;

    for(i=0;i<days;i++){
        system("clear");
        white();
        cout << "DAYS REMAINING: " << days-i;
        cout << "     DAYS TRAVELED: " << i;
        cout << "\n\n";
        
        MainReactor.state();
        cout << "\n";
        if(MainReactor.condition<50 && EngineerCore.health>25){
            MainReactor.RepairTime=(100-MainReactor.condition)/EngineerCore.skill;
            EngineerCore.BusyStatus=MainReactor.RepairTime;
        }
        if(MainReactor.RepairTime!=0){
            EngineerCore.FixReactor(MainReactor.RepairTime,MainReactor.risk,MainReactor.condition);
        }


        EngineOne.state();
        if(EngineOne.condition<48 && EngineerCore.BusyStatus==0 && EngineerCore.health>25){
            EngineOne.RepairTime=(100-EngineOne.condition)/EngineerCore.skill;
            EngineerCore.BusyStatus+=EngineOne.RepairTime;
        }
        if(EngineOne.RepairTime!=0){
            EngineerCore.FixEngine(EngineOne.id,EngineOne.RepairTime,EngineOne.condition);
        }

        EngineTwo.state();
        if(EngineTwo.condition<48 && EngineerCore.BusyStatus==0 && EngineerCore.health>25){
            EngineTwo.RepairTime=(100-EngineTwo.condition)/EngineerCore.skill;
            EngineerCore.BusyStatus+=EngineTwo.RepairTime;
        }
        if(EngineTwo.RepairTime!=0){
            EngineerCore.FixEngine(EngineTwo.id,EngineTwo.RepairTime,EngineTwo.condition);
        }

        EngineThree.state();
        if(EngineThree.condition<48 && EngineerCore.BusyStatus==0 && EngineerCore.health>25){
            EngineThree.RepairTime=(100-EngineThree.condition)/EngineerCore.skill;
            EngineerCore.BusyStatus+=EngineThree.RepairTime;
        }
        if(EngineThree.RepairTime!=0){
            EngineerCore.FixEngine(EngineThree.id,EngineThree.RepairTime,EngineThree.condition);
        }

        EngineFour.state();
        if(EngineFour.condition<48 && EngineerCore.BusyStatus==0 && EngineerCore.health>25){
            EngineFour.RepairTime=(100-EngineFour.condition)/EngineerCore.skill;
            EngineerCore.BusyStatus+=EngineFour.RepairTime;
        }
        if(EngineFour.RepairTime!=0){
            EngineerCore.FixEngine(EngineFour.id,EngineFour.RepairTime,EngineFour.condition);
        }

        cout << "\n";
        MainHull.state();
        if(MainHull.condition<43 && EngineerCore.health>25){
            MainHull.RepairTime=(100-MainHull.condition)/EngineerCore.skill;
            EngineerCore.BusyStatus+=MainHull.RepairTime;
        }
        if(MainHull.RepairTime!=0){
            EngineerCore.FixHull(MainHull.condition,MainHull.RepairTime);
        }
        cout << "\n";

        MainShield.state();
        cout << "\n";
        systemLS.state();
        if(systemLS.oxygen<48){
            systemLS.RepairTime=(100-systemLS.oxygen)/EngineerCore.skill;
            EngineerCore.BusyStatus+=systemLS.RepairTime;
        }
        if(systemLS.RepairTime!=0 && EngineerCore.health>25){
            EngineerCore.FixLS(systemLS.RepairTime,systemLS.oxygen);
        }

        cout << "\n";

        EngineerCore.being();
        if(EngineerCore.health<25){
            EngineerCore.HealingTime=(100-EngineerCore.health)/MedicalCore.skill;
            MedicalCore.BusyStatus=EngineerCore.HealingTime;
        }
        if(EngineerCore.HealingTime!=0){
            MedicalCore.heal(EngineerCore.name,EngineerCore.HealingTime,EngineerCore.health);
        }
        if(EngineerCore.hapiness<15){
            SecurityCore.crackdown(EngineerCore.hapiness,EngineerCore.numbers,EngineerCore.name);
        }

        MedicalCore.being();
        PassengersCore.being();
        if(PassengersCore.health<25){
            PassengersCore.HealingTime=(100-PassengersCore.health)/MedicalCore.skill;
            MedicalCore.BusyStatus=PassengersCore.HealingTime;
        }
        if(PassengersCore.HealingTime!=0){
            MedicalCore.heal(PassengersCore.name,PassengersCore.HealingTime,PassengersCore.health);
        }
        if(PassengersCore.hapiness<17){
            SecurityCore.crackdown(PassengersCore.hapiness,PassengersCore.numbers,PassengersCore.name);
        }

        GeneralMood=mood(EngineerCore.hapiness,MedicalCore.hapiness,PassengersCore.hapiness);
        if(GeneralMood>75){ 
            green();
            cout << "mood on the ship is great\n";
        }
        else if (GeneralMood>40){
            white();
            cout << "mood on the ship satisfactory\n";
        }
        else if (GeneralMood>30){
            yellow();
            cout << "mood on the ship has become to decline\n";
        }
        else{
            red();
            cout << "mood on the ship is abysmal\n";
        }
        cout << "\n";
        
        

        //random backround wear for the components
        if(clock()%2) MainReactor.condition-=1;
        if(clock()%2) EngineOne.condition-=1;
        if(clock()%2) EngineTwo.condition-=1;
        if(clock()%2) EngineThree.condition-=1;
        if(clock()%2) EngineFour.condition-=1;
        if(clock()%2) systemLS.oxygen-=1;
        systemLS.food-=1;

        //game over conditions
        if(MainReactor.risk>90){
            red();
            cout << "THE SHIP WAS DESTROYED!\n";
            return 0;
        }

        if(systemLS.oxygen<10){
            red();
            cout << "THE PEOPLE ON BOARD HAVE SUFFOCATED!\n";
            return 0;
        }

        if(systemLS.food<=-10){
            red();
            cout << "THE PEOPLE ON BOARD HAVE STARVED WITHOUT PROVISIONS!\n";
            return 0;
        }

        if(PassengersCore.numbers<=0){
            red();
            cout << "ALL THE PASSENGERS HAVE PERISHED!\n";
            return 0;
        }

        if(MainHull.condition<=9){
            red();
            cout << "THE HULL WAS DESTROYED AND THE SHIP WITH IT!\n";
            return 0;
        }

        //if the engines get slower the trip takes more days
        if((EngineOne.condition+EngineTwo.condition+EngineThree.condition+EngineFour.condition)/4<45)
            days+=2;

        if(i==10 || i==30 || i==50 || i==70 || i==120 || i==140 || i==170 ) 
            if (rand()%2) asteroid1.strike(MainShield.condition,MainHull.condition,MainReactor.risk);
        if(i==20 || i==60 || i==80 || i==100 || i==130 || i==150 || i==190)
        if(rand()%2) {
            pirateship.attack(MainShield.condition,SecurityCore.numbers,
                              EngineOne.condition,EngineTwo.condition,
                              EngineThree.condition,EngineThree.condition,
                              MainReactor.condition,PassengersCore.numbers,
                              MainReactor.risk,EngineerCore.numbers);
            if(SecurityCore.numbers==0){
                red();
                cout << "THE SHIP WAS RANSACKED BY PIRATES!\n";
                return 0;
            }
        }

        if((systemLS.food<days-i) || EngineerCore.numbers<=0 || SecurityCore.numbers<=10){
            white();
            cout << "due to shortcomings, a detour to a nearby station became inevitable\n";
            usleep(3000000);
            Astation.replenish(systemLS.food,EngineerCore.numbers,SecurityCore.numbers, MainShield.condition);
            aux=clock()%10;
            cout << "the detour to the station added " << aux << " days to the journey\n";
            days+=aux;
            usleep(5000000);
        }
        usleep(1000000);
    }

    green();
    cout << "\nTHE SHIP HAS ARRIVED!\n";

    return 0;
}