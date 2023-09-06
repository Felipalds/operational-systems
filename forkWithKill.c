#include <stdio.h>
#include<sys/syscall.h>

int main(){
  int pid, pid2;
  pid = fork();
  if(pid == 0){
    printf("Son\n");
  } else {
    printf("Father\n");
    sleep(5);
    return 0;
  }
  // If father is killed, the son is not killed, 
  // so it gets up and be a son of the father of father! :)
  printf("Look at ps -fH\n");
  fflush(stdout);
  sleep(10);
}
