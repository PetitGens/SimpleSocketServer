project : client.out server.out

client : client.out
server : server.out

client.out : bin/client.o
	gcc -o client.out -Wall bin/client.o bin/socket.o bin/subject.o

server.out : bin/server.o
	gcc -o server.out -Wall bin/server.o

bin/client.o : src/client.c bin/subject.o bin/socket.o
	gcc -o bin/client.o -c src/client.c -Wall -Werror

bin/server.o : src/server.c
	gcc -o bin/server.o -c src/server.c -Wall -Werror

bin/socket.o : src/socket.c
	gcc -o bin/socket.o -c src/socket.c -Wall -Werror

bin/subject.o : src/subject.c
	gcc -o bin/subject.o -c src/subject.c -Wall -Werror