#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "../header/socket.h"
#include "../header/subject.h"

void start(int argc, char** argv){
    if(argc < 3){
        printf("Ce programme prend 2 arguments en paramètre.\n");
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[2]);
    int socket = connectToServer(argv[1], port);
    char* msg = "Hello World!\n";
    write(socket, msg, strlen(msg));
    close(socket);
}

int main(int argc, char** argv){
    start(argc, argv);
    return EXIT_SUCCESS;
}