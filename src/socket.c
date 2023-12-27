#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

struct sockaddr_in initAddressStructure(const char* ipAddress, short int port){
    struct sockaddr_in addressStruture;
    addressStruture.sin_family = PF_INET;
    addressStruture.sin_port = htons(port);

    inet_aton(ipAddress, &addressStruture.sin_addr);
    return addressStruture;
}

int connectToServer(const char* ipAddress, short int port){
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0){
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in address = initAddressStructure(ipAddress, port);

    if(connect(sock, (struct sockaddr*)&address, sizeof(address)) != 0){
        perror("connect");
        close(sock);
        exit(EXIT_FAILURE);
    }

    return sock;
}

int initServeur(int port){
    int listeningSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(listeningSocket < 0){
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the SO_REUSEADDR so that the port can be used right back after stopping the server
    // (otherwise, we have to wait a bit for it to freed)
    int opt = 1;
    if (setsockopt(listeningSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }   

    struct sockaddr_in address = initAddressStructure("0.0.0.0", port);

    if(bind(listeningSocket, (struct sockaddr*)&address, sizeof(address)) < 0){
        perror("bind");
        close(listeningSocket);
        exit(EXIT_FAILURE);
    }

    if(listen(listeningSocket, 10) < 0){
        perror("listen");
        close(listeningSocket);
        exit(EXIT_FAILURE);
    }

    printf("server started\n");

    return listeningSocket;
}