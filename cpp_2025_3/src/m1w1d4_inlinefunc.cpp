#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

inline int mutiply(int a , int b ){
    return a * b;
}

int main(){
    int a = mutiply(5,6);
    printf("result %d\n", a);
    return 0;
}