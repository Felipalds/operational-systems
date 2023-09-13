#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    char *newargv[] = { "ps", "-Hf", NULL };

    pid_t pid;
    pid= fork();
    if (pid ==0){
        execve("/bin/ps", newargv, NULL);
        perror("execve");   /* execve() returns only on error */
        exit(EXIT_FAILURE);
    }
    wait(NULL);
}
