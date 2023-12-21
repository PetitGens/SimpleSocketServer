#ifndef __SER_SOCKET_H__
#define __SER_SOCKET_H__

/**
 * Connects to the server with the specified IP address and the specified port.
 * @return the socket that can be used to communicate with the server
*/
int connectToServer(const char* ipAdress, short int port);

/**
 * Initialize a TCP server on the specified port
*/
int initServeur(int port);

#endif //__SER_SOCKET_H__