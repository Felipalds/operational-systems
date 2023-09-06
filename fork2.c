#include <stdio.h>
#include<sys/syscall.h>

int main(){
  int pid, pid2;
  int v = 0;
  pid = fork();
  if(pid == 0){
    printf("Son %d\n", v);
  } else {
    v = 20;
    pid2 = fork();
    if(pid2 == 0) {
      fork();
    }
    printf("Dad %d\n", v);
  }

  fflush(stdout);
  sleep(10);
}
