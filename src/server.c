#include <stdio.h>
#include <stdlib.h>
#include "../header/socket.h"



int main(int argc, char** argv){
    if(argc < 2)
        return EXIT_FAILURE;
    int port = atoi(argv[1]);
    return EXIT_SUCCESS;
}