#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "sys/wait.h"
#include "string.h"
#include <readline/readline.h>
#include <dirent.h> 

int main(int argc, char *argv[]) {
    char *input;
    while (1) {
        input = readline("MYSHELL>>");
        if(strlen(input) == 0) {
            continue;
        }
        

        int ix = 0;
        char *inputs[80];
        char *token = strtok(input," ");
        while( token != NULL ) {
            inputs[ix] = token;
            ix++;
            token = strtok(NULL," ");
        }
        
        if(strcmp(inputs[0],"exit") == 0) {
            return 1;
        }
        else if(strcmp(inputs[0],"clear") == 0) {
            system("clear");
        }
        else if(strcmp(inputs[0],"cat") == 0) {
            printf("cat:%s\n",inputs[1]);
        }
        else if(strcmp(inputs[0],"ls") == 0) {
            DIR *d;
            struct dirent *dir;
            d = opendir(".");
            if (d) {
                while ((dir = readdir(d)) != NULL) {
                    printf("%s\n", dir->d_name);
                }
                closedir(d);
            }
        }
        
        
    }
    
    return 0;
}
