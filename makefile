all : client server

client : client.o
	gcc -o client.out -Wall bin/client.o

server : server.o
	gcc -o server.out -Wall bin/server.o

client.o :
	gcc -o bin/client.o -c src/client.c -Wall -Werror

server.o :
	gcc -o bin/server.o -c src/server.c -Wall -Werror

socket.o :
	gcc -o bin/socket.o -c src/socket.c -Wall -Werror

subject.o :
	gcc -o bin/subject.o -c src/subject.c -Wall -Werror