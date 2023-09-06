// C program to implement one side of FIFO
// This side writes first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    FILE *fd;
    int pid;
    // FIFO file path
    char * myfifo = "/tmp/myfifo";

    // Creating the named file(FIFO)
    // mkfifo(<pathname>, <permission>)
    mkfifo(myfifo, 0666);
    // read, write, execute
    // user, group, all

    pid= fork();
    if (pid==0 ) { //child
        fd = fopen(myfifo, "w");             
        for (int i=0; i < 10; i++)
        {
            // Open FIFO for write only
            fwrite(&i, sizeof(int), 1, fd);
            printf("Writing %d\n", i);            
            fflush(fd);
            sleep(1);
        }
        fclose(fd);
        return 0; 
    } else { //father
        int value;
        fd = fopen(myfifo, "r");             
        for (int i=0; i < 10; i++)
        {
            // Open FIFO for write only
            fread(&value, sizeof(int), 1, fd);
            printf("Reading %d\n", value);
            fflush(stdout);
        }
        fclose(fd);
        return 0;
    }

}

