#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "../header/socket.h"
#include "../header/subject.h"

#define BUF_SIZE 256

void start(int port, Subject subject[], int subject_size){
    int socket = initServeur(port);
    while(1){
        struct sockaddr_in caller;
        socklen_t size = sizeof(caller);
        int dialogSocket = accept(socket, (struct sockaddr *)&caller, &size);
        if(dialogSocket < 0){
            perror("accept");
            close(dialogSocket);
            close(socket);
        }
        char buffer[BUF_SIZE];
        read(dialogSocket, &buffer, sizeof(buffer));
        if(strcpm(buffer, "end")){
            close(dialogSocket);
            break;
        }
        double avg = getAverage(atoi(buffer), subject, subject_size);
        write(dialogSocket, &avg, sizeof(avg));
    }
    close(socket);
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
    start(port, subjectArray, 5);

    return EXIT_SUCCESS;
}