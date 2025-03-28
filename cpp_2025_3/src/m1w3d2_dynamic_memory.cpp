#include <cstdio>
#include <iostream>
#include "./helper.cpp"

using namespace std;


void memoryLeak(){
    // local variable p is a pointer on the stack, it points to a memory address allocated on the heap by `new` keyword
    int *p = new int;
    *p = 10;
    return;// after return, the memory allocated by new is not deleted, but the pointer p is out of scope because it is a local variable. as a result, no pointer pointing to the memory allowcated, and thus the memory is leaked.
}

void memoryLeakFixed(){
    Person *p = new Person("johnny");
    p->sayHi();
    delete p; // delete the memory pointed by local variable p before p goes out of scope
    return;
}

void doubleDelete(){
    i("double delete");
    Person *p = new Person("Yuding");
    p->sayHi();
    delete p;
    if(nullptr == p){
        printf("P is nullptr\n");
    }
    delete p; // delete a nullptr, this will crash the program
    return;
}

void deleteNullPtr(){
    i("delete nullptr");
    Person *p = nullptr;
    delete p; // delete a nullptr, this is safe
    return;
}


int main(){
    memoryLeak();
    memoryLeakFixed();
    deleteNullPtr();
    doubleDelete();
    return 0;
}