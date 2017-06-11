#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "network.h"
#include "log.h"

#define BUFLEN 1024

int init_socket(int type, const struct sockaddr *addr, socklen_t alen, int qlen) {
    int fd;
    if ((fd = socket(addr->sa_family, type, 0)) < 0)
        return -1;
    
    if (bind(fd, addr, alen) < 0) {
        close(fd);
        return -1;
    }

    if (type == SOCK_STREAM || type == SOCK_SEQPACKET) {
        if (listen(fd, qlen) < 0) {
            close(fd);
            return -1;
        }
    }
    
    return fd;
}


int init_server(int portno) {
#define QLEN 256
     int sockfd, newsockfd;
     socklen_t clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
    
     bzero((char *) &serv_addr, sizeof(serv_addr));
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     
     sockfd = init_socket(SOCK_STREAM, (struct sockaddr *)&serv_addr, sizeof(serv_addr),  QLEN);
     if (sockfd < 0) {
        error("Init server failed!");
     }

     return sockfd;
}


void serve(int sockfd) {
    int clfd;
    char buf[BUFLEN];
    ssize_t data_len;
    for(;;) {
        clfd = accept(sockfd, NULL, NULL);
        if (clfd < 0) {
            error("error");
        }
        
        data_len = recv(clfd, buf, BUFLEN, 0);
        printf("receive len: %ld, msg: %s", data_len,  buf);
        data_len = send(clfd, buf, BUFLEN, 0);
        close(clfd);
    }

}
