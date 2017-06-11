/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#include "log.h"
#include "network.h"


int main(int argc, char *argv[])
{
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }

     int portno;

     portno = atoi(argv[1]);
    
     int sockfd = init_server(portno);
     serve(sockfd);
     return 0; 
}

