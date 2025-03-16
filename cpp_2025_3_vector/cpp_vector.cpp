#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace yuding{
    template <typename T>

    void println(vector<T> & vec){
        std::cout << "[ ";
        int i = 0;
        for(; i < vec.size(); i ++){
            std::cout << vec[i] << ",";
        }
        std::cout <<" ]" << std::endl;
    }

    void println(string msg){
        cout << "msg addr" << &msg << std::endl;
        std::cout << msg << std::endl;
    }
}

int main(){
    vector<std::string> v = {"a", "b", "c"};
    yuding::println(v);

    yuding::println("reproduce sub_flow error");
    v.clear();
    yuding::println(v);
    //insert at position 0
    v.insert(v.begin(), "d");

    //insert at 10
    v.insert(v.begin() + 10, "e");
    yuding::println("after insert");
    yuding::println(v);
    return 0;
}