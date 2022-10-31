#include <iostream>
#include <cstdlib>
using namespace std;
#include "big_classes.h"
#include "colors.h"

class Crew: public Humans{
    public:

    void being(){
        if(health<25){
            red();
            cout << "the crew cannot work due to poor health\n";
        }

        if(hapiness<20){
            red();
            cout << "the crew have gone on strike\n";
        }
    }
};

class Engineers: public Crew{
    public:

    Engineers(int n,int s,string nme){
        numbers=n;
        skill=s;
        name=nme;
    }

    void FixReactor(int &r,int &rsk,int &c){
        if(numbers<=0) return;
        white();
            cout << "^\n";
            cout << "|\n";
            cout << "the engineers are repairing the reactor, days remaining: " << r;
            cout << "\n\n";
            rsk=0;
            c+=skill;
            r-=1;
            BusyStatus-=1;
            if(clock()%2) hapiness-=1;
            if(clock()%3) health-=1;
    }

    void FixEngine(int i,int &rt,int &con){
        if(numbers<=0) return;
        white();
            cout << "^\n";
            cout << "|\n";
            cout << "the engineers are repairing engine #" << i<<", days remaining: " << rt;
            cout << "\n\n";
            con+=skill;
            rt-=1;
            BusyStatus-=1;
            if(clock()%2) hapiness-=1;
            if(clock()%3) health-=1;
    }

    void FixLS(int &rt,int &o){
        white();
            cout << "^\n";
            cout << "|\n";
            cout << "the engineers are repairing the oxygen recycling system, days remaining: " << rt;
            cout << "\n\n";
            o+=skill;
            rt-=1;
            BusyStatus-=1;
            if(clock()%2) hapiness-=1;
            if(clock()%3) health-=1;
    }

    void FixHull(int &c,int &rt){
        white();
            cout << "^\n";
            cout << "|\n";
            cout << "the engineers are repairing the damaged hull, days remaining: " << rt;
            cout << "\n\n";
            c+=skill;
            rt-=1;
            BusyStatus-=1;
            if(clock()%2) hapiness-=1;
            if(clock()%3) health-=1;
    }

    void being(){
        if(numbers<=0){
            red();
            cout << "the engineers have all perished!\n";
        }
        if(health<25){
            red();
            cout << "the engineers cannot work due to poor health\n";
        }

        if(hapiness<20){
            red();
            cout << "the engineers have gone on strike\n";
        }
    }

};

class Medical: public Crew{
    public:

    Medical(int n,int m,string nme){
        numbers=n;
        skill=m;
        name = nme;
    }

    void heal(string s,int &ht,int &h){
        if(numbers<=0) return;
        white();
            cout << "^\n";
            cout << "|\n";
            cout << "the medics are healing the "<< s<<", days remaining: " << ht;
            cout << "\n\n";
            h+=skill;
            ht-=1;
            BusyStatus-=1;
    }

    void being(){
        if(numbers<=0){
            red();
            cout << "the medics have all perished!\n";
        }
        if(hapiness<20){
            red();
            cout << "the medics have gone on strike\n";
        }
    }
};



class Security: public Crew{
    public:

    Security(int n,string nme){
        numbers=n;
        name = nme;
    }

    void crackdown(int &h,int &num, string s){
        if(numbers<=0) return;
        red();
        cout << "security have beat the "<< s <<" into submission\n";
        h+=25;
        int dead=rand()%5;
        num-=dead;
        cout << dead<< " "<< s << " have perished in the crackdown\n";
    }

    void state(){
        if(numbers<=0){
            red();
            cout << "the security ops have all perished\n";
        }
    }
};

class Passengers: public Humans{
    public:

    Passengers(int n,string nme){
        numbers=n;
        name=nme;
    }

    void being(){
        if(health<25){
            red();
            cout << "the passengers are in very poor health\n";
        }

        if(hapiness>=20 && hapiness<50){
            yellow();
            cout << "the passengers have grown restless\n";
        }
        else if(hapiness<20){
            red();
            cout << "the passengers have begun to revolt\n";
        }
    }
};

