#include "m1_w1_d1_helloworld.hpp"


Person::Person(string name){
    printf("default constructor\n");
    this->name = name;
}

Person::Person(const Person &p){
    printf("copy constructor\n");
    this->name = p.name;
}

Person::Person(Person && p){
    printf("move constructor\n");
    this->name = p.name;
    p.name = "NO NAME(after move)";
}

Person::~Person(){
    printf("deconstructor:%s\n", this->name.c_str());
}

void Person::sayHello(){
    printf("hello world, my name is %s\n", this->name.c_str());
}

int main(){
    Person p("johnny");
    p.sayHello();
    Person p2 = p;
    p2.sayHello();
    Person p3 = std::move(p2);
    p2.sayHello();
    p3.sayHello();
    return 0;
}