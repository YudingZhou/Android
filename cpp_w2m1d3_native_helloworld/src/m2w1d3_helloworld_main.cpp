#include <utils/Log.h>
#include <sys/syscall.h>
#include <unistd>

extern "C" void m2w1d3_hello_world();

int main(){
    ALOGI("m2w1d3 main()");
    m2w1d3_hello_world();
    pid_t pid = getpid();
    ALOGI("yuding native hello world, pid : %d", pid);
}