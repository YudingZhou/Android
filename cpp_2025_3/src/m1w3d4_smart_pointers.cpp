#include "../includes/common_include.hpp"

class A{
    public:
        void foo(){
            printf("A.foo()\n");
        }
};

int * p5 = new int;
A * p = nullptr;
void uniquePointer(){
    i("unique pointer");
    unique_ptr<int> p1 = make_unique<int>(10);
    int *p3 = new int;
    *p3 = 20;
    delete p3;
    int *p4 = new int;
    cout << "p4 addr " << p4 << endl;
    cout << "p1 addr " << p1.get() << endl;
    p4 = p1.get();
    p5 = p1.get();
    cout << "p4 addr after assign " << p4 << endl;
    cout << "p5  " << p5 << endl;
    cout << "p5 value " << *p5 << endl;

    unique_ptr<A> p2 = make_unique<A>();
    p = p2.get();
    p->foo();
}

int main(){
    uniquePointer();

    cout << "P1 out of scope" << endl;

    cout << "p5  " << p5 << endl;
    cout << "p5 value " << *p5 << endl;
    // here p2 is out of scope, p's behavior is undefined.
    p->foo();
    return 0;
}