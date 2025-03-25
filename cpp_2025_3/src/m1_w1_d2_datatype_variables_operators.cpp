#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class PrimitiveTypes{
    public:
        void intTypes(){
            
        }
        void floatTypes(){}
        void charTypes(){}
        void boolTypes(){}
        void voidTypes(){}
        float calculatesquare(float width, float length){
            return width * length;
        }
    private:
        int a;
        short b;
        long c;
        long long d;
        unsigned int e;
        unsigned short f;
        unsigned long g;
        unsigned long long h;

        float i;
        double j;
        long double k;

        bool l;
        
        //signed -128 to 127
        char m;
        //0-255
        unsigned char n;
        //2 or 4 bytes depend on the platform
        wchar_t o;
        //for UTF-16
        char16_t p;
        //for UTF-32
        char32_t q; 
};

int main(){

    PrimitiveTypes pt;
    float a = 0;
    float b = 0;
    cout << "input width:" << endl;
    cin >> a;
    cout << "input length:" << endl;
    cin >> b;

    float result = pt.calculatesquare(a, b);
    cout << "the size is " << result << endl;

    return 0;
}