#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <syscall.h>
#include <unistd.h>
#include <semaphore.h>

int i=0;

sem_t sem;
sem_init(&sem, 0, 1);

void *thread_function(void *arg){
  
  int tid;
  tid= syscall(SYS_gettid);
  sem_wait(&sem);
  
   for (i=0; i < 10 ; i++)  {
      printf(" thread pid %d %d %d\n", tid, i, *(int*)arg);
      usleep(100);
   }
   sem_post(&sem);
  
  return NULL;
}


int main()
{
   pthread_t p1, p2;
   int id1, id2;
   id1=1;
   id2=2;
                 // id, attr, função,         arg
   pthread_create(&p1, NULL, &thread_function, &id1);
   pthread_create(&p2, NULL, &thread_function, &id2);

   int tid;
   tid= syscall(SYS_gettid);
   printf(" thread main pid %d %d\n", tid, getpid());
   
   /*  Quantos threads eu tenho em execução no meu processo? */
  
   pthread_join(p1, NULL);
   pthread_join(p2, NULL);
   sleep(1);
   printf("Threads finalizadas \n");
   return 0;	
}




