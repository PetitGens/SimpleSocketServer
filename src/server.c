#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "../header/socket.h"
#include "../header/subject.h"

void start(int port){
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
        
    }
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
    start(port);

    return EXIT_SUCCESS;
}