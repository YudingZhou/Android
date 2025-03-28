#include "../includes/common_include.hpp"


void swapByReference(int & a, int & b){
    i("swap by reference");
    int temp = a;
    a = b;
    b = temp;
}

void swapByPointer(int * a, int * b){
    i("swap by pointer");
    // this is difference from original address of a, this another pointer, which also point to the value of a.
    cout << "a_arugment address:" << a << endl;
    if(nullptr == a || nullptr == b){
        i("swapbypointer: a or b is nullptr");
        return;
    }

/**
 *error code, a and b are local copies of original pointers

  a -> 1
  b -> 2

  a_cpy -> 1
  b_cpy -> 2

 this is swapping local copy pointers but the value that pointers pointing to.
     int *temp = a;
    a = b;
    b = temp;
*/

    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int  a = 10;
    int  b = 20;
    int &c = b;

    /**
     * An error learn
     * 
     * previous call
     * 
     *  i(stringstream() <<"before swap " << a <<","<< b);
     * 
     * Compiler is saying 
     * could not convert `xxxx` from `std::basic_osstream(char)` to `std::string`
     * 
     * xxx is the parameter of function i()
     * 
     * meaning, the func i( ) is expecting `std::string`, the compiler try to convert the passed parameter to `std::string` but it could not. 
     * 
     * And the passed parameter is a  `std:basic_osstream` 
     * 
     * /workspaces/Android/cpp_2025_3/src/m1w3d3_reference_vs_pointer.cpp:25:49: error: could not convert ‘(& std::operator<< <std::char_traits<char> >((* &(& std::operator<< <std::__cxx11::basic_stringstream<char>, char [12]>(std::__cxx11::basic_stringstream<char>(), "after swap "))->std::basic_ostream<char>::operator<<((* a))), ((const char*)",")))->std::basic_ostream<char>::operator<<((* b))’ from ‘std::basic_ostream<char>’ to ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’}
   25 |     i(stringstream() <<"after swap " << *a <<","<< *b);
      |       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~
      |                                                 |
      |                                                 std::basic_ostream<char>
make[2]: *** [CMakeFiles/m1w3d3.dir/build.make:63: CMakeFiles
     * 
    */
   cout <<"before swap " << a <<","<< b << endl;

    // although a is value
    // when they are passed to the func, compiler create references and binds them to the value of a.
    // like c, c is a reference which binds to b explicitly
    swapByReference(a, c);

    cout <<"after swap " << a <<","<< b << endl;

    cout << "a address:" << &a << endl;
    swapByPointer(&a, &b);
    
    
    // another learning 
    // parameter temporary value cannot be called upon like java. it has its scope and life-cyle which is shorter than the return value from str(). so somehow the compiler complains about it 
    /***
     * 
      i((stringstream() <<"after swap " << a <<","<< b).str());

     * /workspaces/Android/cpp_2025_3/src/m1w3d3_reference_vs_pointer.cpp:43:58: error: ‘class std::basic_ostream<char>’ has no member named ‘str’
   43 |     i((stringstream() <<"before swap " << *a <<","<< *b).str());
     * 
    */
   std::stringstream msg = stringstream();
   msg <<"after swap " << a <<","<< b;
    i(msg.str());


    return 0;
}