#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "sys/wait.h"
#include "string.h"

int main(int argc, char *argv[]) {
    char input[100];
    while (strcmp(input,"exit")) {
        scanf("%s",input);

        if (strcmp(input,"clear") == 0) {
            system("clear");
        }
        
    }
    
    return 0;
}
