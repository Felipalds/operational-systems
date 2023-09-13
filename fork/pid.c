#include <sys/syscall.h>
#include <stdio.h>

int main(){
    long mypid, ppid;
    mypid = syscall(SYS_getpid);
    ppid = syscall(SYS_getppid);

    printf("My PID: %ld\n", mypid);
    printf("Parent PID: %ld\n", ppid);
    fflush(stdout);
    sleep(10);
}
