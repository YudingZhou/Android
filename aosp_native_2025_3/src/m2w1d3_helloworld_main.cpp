#include <utils/Log.h>

extern "C" void m2w1d3_hello_world();

int main(){
    ALOGI("Yuding calling extern m2w1d3_hello_world()");
    m2w1d3_hello_world();
    ALOGI("Yuding try to find where libm2w1d3 is and where the binary m2w1d3.bin is ");
}