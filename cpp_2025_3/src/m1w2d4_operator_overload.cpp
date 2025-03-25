#include <cstdio>
#include <string>

using namespace std;

class MyString{
    private:
        string val;
    public:
        MyString(string val): val(val){}
        MyString operator+(const MyString & s){
            return MyString(this->val + s.val);
        }

        string toString(){
            return this->val;
        }
};

int main(){
    MyString s1("my");
    MyString s2(" ");
    MyString s3("name");
    MyString s4(" ");
    MyString s5("is");
    MyString s6(" ");
    MyString s7("Johnny");

    MyString result = s1+ s2 + s3 +s4 +s5 +s6 +s7;
    printf("result-> %s\n", result.toString().c_str());
    return 0;
}