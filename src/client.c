#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "../header/socket.h"
#include "../header/subject.h"

#define BUF_SIZE 256

void sendMessage(int socket, const char* message){
    write(socket, message, strlen(message) + 1);
}

void start(int argc, char** argv){
    if(argc < 4){
        printf("Ce programme prend 3 arguments en paramètre.\n");
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[2]);

    // Check if port is between 1 and 65535 (2^16 - 1)
    if(port <= 0 || port > 0xFFFF){
        printf("Port invalide.\n");
        exit(EXIT_FAILURE);
    }

    int socket = connectToServer(argv[1], port);

    sendMessage(socket, argv[3]);

    char response[BUF_SIZE];
    read(socket, response, BUF_SIZE);

    printf("Moyenne  : %s.\n", response);

    close(socket);
}

int main(int argc, char** argv){
    start(argc, argv);
    return EXIT_SUCCESS;
}