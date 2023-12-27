#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <signal.h>
#include "../header/socket.h"
#include "../header/subject.h"

#define BUF_SIZE 256

#define DEBUG

int serverSocket;

void onSignal(int sigNum){
    if(sigNum == SIGUSR1){
        close(serverSocket);
        exit(EXIT_SUCCESS);
    }
}

void processQuery(int dialogSocket, Subject*  subjects, int subjectCount){
    char buffer[BUF_SIZE];
    read(dialogSocket, &buffer, sizeof(buffer));

    if(strcmp(buffer, "end") == 0){
        close(dialogSocket);
        kill(getppid(), SIGUSR1);        
        exit(EXIT_SUCCESS);
    }

    double avg = getAverage(atoi(buffer), subjects, subjectCount);
    
    char response[BUF_SIZE];
    sprintf(response, "%lf", avg);

    write(dialogSocket, response, strlen(response) + 1);
    close(dialogSocket);
}

void start(int port, Subject subject[], int subject_size){
    serverSocket = initServeur(port);
    signal(SIGUSR1, onSignal);

    while(1){
        struct sockaddr_in caller;
        socklen_t size = sizeof(caller);
        int dialogSocket = accept(serverSocket, (struct sockaddr *)&caller, &size);
        if(dialogSocket < 0){
            perror("accept");
            close(dialogSocket);
            close(serverSocket);
            exit(EXIT_FAILURE);
        }
        
        int pid = fork();
        switch(pid){
            case -1:
                perror("fork");
                exit(EXIT_FAILURE);    
            case 0:
                processQuery(dialogSocket, subject, subject_size);
                exit(EXIT_SUCCESS);
        }
    }
    close(serverSocket);
}

int main(int argc, char** argv){
    if(argc < 2)
        return EXIT_FAILURE;
    
    Subject subjectArray[] = {
        {1, "Anglais", 12.5},
        {2, "Mathematique", 10.8},
        {3,"Informatique", 9.3},
        {4,"Culturte generale", 12.6},
        {5,"Physiques", 11.8},
        {6,"Programmation systeme", 12.3}
    };

    int port = atoi(argv[1]);
    if(port <= 0 || port > 0xFFFF){
        printf("Port invalide.\n");
        exit(EXIT_FAILURE);
    }
    start(port, subjectArray, 6);

    return EXIT_SUCCESS;
}