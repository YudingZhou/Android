#include <iostream>
#include <string>

using namespace std;


class Person{
    public:
        void sayHello();
        Person(string name);
        Person(const Person & p);
        Person(Person && p);
        ~Person();
    private:
        string name;
};