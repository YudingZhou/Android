#include <iostream>
#include <cstdio>
#include <string>

using namespace std;


class A{
    public:
        A(A && a){
            printf("move constructor\n");
            this->name = a.name;
            a.name = "name after move";
        }

        A(const A & a){
            printf("copy constructor\n");
            this->name = a.name;
        }

        A(string name, string arg2): name(name){
            printf("default constrcutor2\n");
        }

        A(string name){
            printf("default constructor1\n");
            this->name = name;
        }
        
        A(): name("default"){
            printf("default constructor3\n");
        }

        string getName(){
            return this->name;
        }

        string fakename(){
            return "fakename";
        }

    private:
        string name;
};

int main(){
    printf("main starts %s \n", "this is the format arg");   
    // NOT A a(), this is a declaration of inline method
    // result in this error 
    // /workspaces/Android/cpp_2025_3_vector/cpp_construtors.cpp:47:33: error: request for member ‘getName’ in ‘a’, which is of non-class type ‘A()’
    A a; // requires default constructor without argument
    printf("a.name -> %s \n", a.getName().c_str());

    A b("My name is B");
    printf("b.name -> %s \n", b.getName().c_str());

    printf("========move constructor move b to c========\n");
    A c = std::move(b);
    printf("c.name -> %s \n", c.getName().c_str());

    printf("b.name -> %s \n", b.getName().c_str());

    printf("========cocy constructor copy c to d========\n");
    A d = c;
    printf("d.name -> %s \n", d.getName().c_str());

    return 0;
}