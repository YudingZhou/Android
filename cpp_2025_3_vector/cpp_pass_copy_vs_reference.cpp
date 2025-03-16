#include <iostream>
#include <string>

using namespace std;

namespace yuding{
    void println(string msg){
        cout << "msg addr" << &msg << std::endl;
        std::cout << msg << std::endl;
    }

    struct Person {
        string  name;
    };

    void println_person_reference(Person & p){
        cout << "person addr" << &p << std::endl;
        cout << p.name << std::endl;
    }

    void println_person_copy(Person p){
        cout << "person addr" << &p << std::endl;
        cout << p.name << std::endl;
    }

    void change_name_reference(Person & p, string new_name){
        p.name = new_name;
    }

    void change_name_copy(Person p, string new_name){
        p.name = new_name;
    }
    
}

int main(){
    yuding::Person a = {"yuding"};

    yuding::println("======printing reference=======");
    yuding::println_person_reference(a);
    yuding::println_person_reference(a);

    yuding::println("======printing copy=======");
    yuding::println_person_copy(a);
    yuding::println_person_copy(a);

    yuding::println("======printing original =======");
    cout << "addr" << &a  << ", name :" << a.name << endl;

    yuding::println("======change name reference=======");
    yuding::change_name_reference(a, "new_name");
    
    cout << "name :" << a.name << endl;

    yuding::println("======change name copy=======");
    yuding ::change_name_copy(a, "new_name2");

    cout<< "name :" << a.name << endl;

    return 0;
}