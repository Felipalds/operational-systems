#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <syscall.h>
#include <unistd.h>
#include <semaphore.h>

sem_t mutex, full, empty;

#define N 4
volatile int buffer[N];
volatile int count;

// void *thread_function(void *arg){
  
//   int tid;
//   tid= syscall(SYS_gettid);
  
//   int i;
//   sem_wait(&sem)
//   for (i=0; i < 10 ; i++)  {
//       printf(" thread pid %d %d %d\n", tid, i, *(int*)arg);
//       fflush(stdout);
//       usleep(100);
//   }
//   sem_post(&sem)
  
//   return NULL;
// }

void *produtor(void *arg){
  int in = 0;
  for(int i = 0; i < 100; i++){
      
      sem_wait(&empty);
      sem_wait(&mutex);
      buffer[in] = i;
      in = (in+1)%N;
      printf("Produziu %d na prosição %d\n", i, in);
      count++;
      sem_post(&mutex);
      sem_post(&full);
   }
   return NULL;
}

void *consumidor(void *arg){
  int out = 0;
  int dout;
  for(int i = 0; i < 100; i++){
      sem_wait(&full);
      sem_wait(&mutex);
      dout = buffer[out];
      out = (out+1)%N;
      printf("Consumiu %d na prosição %d\n", dout, out);
      count--;
      sem_post(&mutex);
      sem_post(&empty);
   }
   return NULL;
}

// Caso o consumidor e o produtor tenham velocidades parecidas, vale
// mais a pena usar o while.
//
// Caso não, vale mais a pena usar semáforos, 
// pois não fica gastando tempo de CPU
int main()
{
   sem_init(&mutex, 0, 1);
   sem_init(&empty, 0, N);
   sem_init(&full, 0, 0);
   pthread_t p1, p2;
   int id1, id2;
   id1=1;
   id2=2;
                 // id, attr, função,         arg
   pthread_create(&p1, NULL, &produtor, NULL);
   pthread_create(&p2, NULL, &consumidor, NULL);

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

