#include "../includes/common_include.hpp"


template <typename T>
T template_function(T t){
    return t;
}

template <typename T>
struct S{
    T t;
};

void template_struct(){
    S<int> s;
}

template <typename T, typename V>
class Holder {
    private:
        T t;
        V v;
    public:
        //v is a rvalue
        Holder (T & t, V &&v): t(t), v(v){

        }

        V getV(){
            return v;
        }
       T getT(){
            return t;
        }
};
void template_class(){
    int a = 1;
    int &ra = a;

    string b = "yuding";
    // after move b is no long valid
    Holder<int, string> h(ra, std::move(b));
    // b is a undefined state. because it is moved. dont do it like this
    cout <<"undefined state b:" << b << endl;

}

int main(){
    i("template class");
    template_class();
    i("template struct");
    template_struct();
    i("template func");
    template_function(1);
    return 0;
}