#include <iostream>
#include <string>
#include <cstdio>


using namespace std;


class Tank{
    public:
        Tank(string name){
            this-> name = name;
        }
        virtual void fire(){
            printf("tank fires\n");
        }

        void move(){
            printf("tank moves\n");
        }
    private:
        string name = "tank";
};

class ATank: public Tank{
    public:
        ATank(string name): Tank(name){}

        void fire() override{
            printf("ATank fires\n");
    }
        void move(){
            printf("ATank moves\n");
        }
};

class BTank: public Tank{
    public:
        BTank(string name): Tank(name){}

        void fire(){
            printf("BTank fires\n");
        }

        void move(){
            printf("BTank moves\n");
        }
};

int main(){
    ATank at("at");
    BTank bt("bt");
    at.fire();
    bt.fire();

    // runtime polymorphism
    Tank * atp = & at;
    atp -> fire();
    atp->move();

    Tank t = move(at);
    t.fire();
    t.move();

    Tank & tr = at;
    // runtime polyphorphism
    tr.fire();

    // non-polymorphic
    tr.move();

    return 0;
}