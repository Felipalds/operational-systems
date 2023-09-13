#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <syscall.h>
#include <unistd.h>
void *thread_function(){
  while(1){
    printf("thread %d %d\n", getpid(), gettid());
  }
  fflush(stdout);
  usleep(10); // process in wait state! we are forcing the context changing
}

int main(){
  pthread_t p1, p2;
  pthread_create(&p1, NULL, &thread_function, NULL);
  pthread_create(&p2, NULL, &thread_function, NULL);

  printf("thread main pid %d thread %d\n", getpid(), gettid());
  // we do not have the guarantee that is really paralell in two cores

  //pthread_join(p1, NULL);
  //pthread_join(p2, NULL);

  sleep(1);
  printf("Finished! \n");
  return 0;
}
