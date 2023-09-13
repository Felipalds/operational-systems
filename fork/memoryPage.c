#define SHM_SIZE 4096
#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main(){
    int shmid;
    char* saddr;
     // Allocate  
    shmid= shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT| S_IRUSR | S_IWUSR);

    saddr= (char *)shmat(shmid, 0, 0);

    if (fork()==0){//children
        saddr[0]=65;        
        printf("Filho %s", saddr);
	      exit(0);
    }    
    sleep(5);
    saddr[1]=66; 
    printf(" Pai %s" , saddr);
    shmctl(shmid, IPC_RMID, 0);
    exit(0);
}

