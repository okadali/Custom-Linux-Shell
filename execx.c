#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "sys/wait.h"
#include "string.h"

int main(int argc, char *argv[]) {
    if(strcmp(argv[1],"execx") == 0) {
        char *pass[80];
        int passIx = 0;
        for(int i = 3 ; i < argc ; i++) {
            pass[passIx++] = argv[i];
        }
        pass[passIx] = (char*)0;
        
        for (int x = 0; x < atoi(argv[0]); x++) {
            int f = fork();
            int i;
            if (f == 0) {
                i = execv("execx", pass);
                perror("writef failed\n");
                return 0;
            }
            else {
                wait(&i);
            }
        }
    }
    else if(strcmp(argv[1],"writef") == 0) {
        if (argc < 3) {
            printf("not enough parameters\n");
        }
        else {
            char *input[80];
            int inputIX = 0;
            for(int x = 2 ; x < argc ; x++) {
                input[inputIX++] = argv[x];
            }

            input[inputIX] = (char *)0;
            for(int i = 0 ; i < atoi(argv[0]) ; i++) {
                int f = fork();
                int i;
                if (f == 0) {
                    i = execv("writef", input);
                    perror("writef failed\n");
                    return 0;
                }
                else {
                    wait(&i);
                }
            }
        }
    }
    else {
        printf("not a valid input\n");
    }  
    
    return 0;
}