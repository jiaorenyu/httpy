server_obj = server.o log.o network.o

#.PHONY clean

CC = gcc
CXX = g++
CFLAGS= -O

server : $(server_obj) 
	$(CC) $(CFLAGS) -o server $(server_obj)

server.o : server.c log.h network.h
log.o : log.c log.h
network.o : network.c network.h

clean: 
	rm $(server_obj) $(client_obj) server
