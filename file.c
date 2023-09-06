#include <stdio.h>

int main(){
   int pid;
   FILE *f;
   char c;
   f= fopen("./teste.txt", "r");
   pid = fork();

    if  (pid == 0){  // filho                     
         fseek(f, 0, SEEK_SET);      
         printf("Processo filho %d\n", getpid());
         if (f== NULL) printf("F null");

         else {
         for (int i=0; i <3; i++){
   	       fread(&c, 1, 1, f);
	       printf("%c ", c);
            printf("child %d \n", ftell(f));
            fflush(f);
            fflush(stdout);
            sleep(1);
         }
         }


    }else{
         printf("Processo pai   %d\n", getpid());        
         for (int i=0; i <3; i++){
   	        fread(&c, 1, 1, f);
	          printf("%c  %d\n", c, ftell(f));                      
            fflush(stdout);
            fflush(f);
            sleep(1);
         }
         //fseek(f, 0, SEEK_END);
         printf("Pos %d \n", ftell(f));
         fclose(f);
        
         sleep(6);   
         return 0;
    }
    
    printf("\nfim da execução  %d\n", getpid());
}
