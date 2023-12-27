project : client.out server.out server2.out

client : client.out
server : server.out

client.out : bin/client.o
	gcc -o client.out -Wall bin/client.o bin/socket.o

server.out : bin/server.o
	gcc -o server.out -Wall bin/server.o bin/subject.o bin/socket.o

server2.out : bin/server2.o
	gcc -o server2.out -Wall bin/server2.o bin/subject.o bin/socket.o

bin/client.o : src/client.c bin/socket.o
	gcc -o bin/client.o -c src/client.c -Wall -Werror

bin/server.o : src/server.c bin/subject.o bin/socket.o
	gcc -o bin/server.o -c src/server.c -Wall -Werror

bin/server2.o : src/server2.c bin/subject.o bin/socket.o
	gcc -o bin/server2.o -c src/server2.c -Wall -Werror

bin/socket.o : src/socket.c
	gcc -o bin/socket.o -c src/socket.c -Wall -Werror

bin/subject.o : src/subject.c
	gcc -o bin/subject.o -c src/subject.c -Wall -Werror