#include <cstdio>
#include <string>

using namespace std;

void i(string msg){
    printf(">%s\n", msg.c_str());
}

class Person{
    private:
        string name;
    public:
        Person(string name): name(name){}

        void sayHi(){
            printf("hi my name is %s\n", this->name.c_str());
        }
        friend void whatsYourName(Person & p);

        friend class AFriend;
};