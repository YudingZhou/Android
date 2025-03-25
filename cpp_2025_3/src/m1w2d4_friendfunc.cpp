#include <cstdio>
#include <string>

using namespace std;

class Person{
    private:
        string name;
    public:
        Person(string name): name(name){}
        friend void whatsYourName(Person & p);

        friend class AFriend;
};

class AFriend: Person{
    public:
        AFriend(string name) : Person(name){}

        void whoIsYourFriend(Person & p){
            printf("my name is %s, and %s is my friend."
                , this->name.c_str(), p.name.c_str());
        }
};

void whatsYourName(Person &p){
    // %s is not for string, it is for a char*
    // string.c_str() returns a char*
    printf("my name is %s\n",p.name.c_str());
}

int main(){
    Person p("johnny");
    whatsYourName(p);

    AFriend afriend("Yuding");
    afriend.whoIsYourFriend(p);
    return 0;
}