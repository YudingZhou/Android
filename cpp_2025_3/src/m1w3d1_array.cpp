#include <cstdio>
#include <string>

using namespace std;

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

int main(){

    Person people[] = {Person("yuding"), Person("jonny")};
    
    // head of the array is a pointer
    Person * p = people;

    // using index to access array references
    Person * p2 = & people[1];

    people[1].sayHi();
    p2->sayHi();
    Person * p3 = (& people[1]) - 1;
    p3->sayHi();
    // this is wrong, Person & p4 = people[0] + 1;
    return 0;
}