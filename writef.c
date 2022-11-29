#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "string.h"
#include <time.h>


int main(int argc, char *argv[]) {
    FILE *fp ;  

    time_t mytime = time(NULL);
    char * time_str = ctime(&mytime);
    time_str[strlen(time_str)-1] = '\0';

    if(strcmp(argv[0],"-f") == 0) {
        fp = fopen(argv[1],"a");
        for(int i = 2; i < argc ; i++) {
            fputs(argv[i],fp);
            fputs("\n",fp);
        }
    }
    else {
        fp = fopen("defaultMyShell.txt","a");
        for(int i = 0; i < argc ; i++) {
            fputs(argv[i],fp);
            fputs("\n",fp);
        }
    }

    fprintf(fp,"System Time: %s pid(): %d ppid(): %d\n",time_str,getpid(),getppid());
    fclose(fp); 

    return 0;
}