#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "sys/wait.h"
#include "string.h"

int main(int argc, char *argv[]) {
    if(strcmp(argv[1],"execx") == 0) {
        char *pass[80];
        int passIx = 0;
        if(argc < 6 ){
            printf("not enough parameters\n");
        }
        else {
            char *input[80];
            int inputIX = 0;
            for(int x = 3 ; x < argc ; x++) {
                input[inputIX++] = argv[x];
            }

            input[inputIX] = (char *)0;
            for(int i = 0 ; i < atoi(argv[0]) ; i++) {
                int f = fork();
                int i;
                if (f == 0) {
                    i = execv(argv[4], input);
                    perror("execv failed\n");
                    return 0;
                }
                else {
                    wait(&i);
                }
            }
        }
        
        //argv[0] = times
        //argv[1] = selected program
        //argv[2] = -t
        //argv[3] = times
        //argv[4] = calisacak program
        //argv[5] = calisacak programin parametreleri

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
    
    return 0;
}