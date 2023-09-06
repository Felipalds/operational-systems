#include <stdio.h>
#include<sys/syscall.h>

int main(){
  int pid, pid2;
  int v = 0;
  pid = fork();
  pid2 = fork();
  if(pid == 0){
    sleep(2);
    printf("Son %d\n", v);
  } else {
    v = 20;
    printf("Dad %d\n", v);
  }

  fflush(stdout);
  sleep(10);
}
