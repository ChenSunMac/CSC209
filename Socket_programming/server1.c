/* A simple server in the internet domain 
   using TCP
   The port number(2000~65535) is passed as 
   an argument 
    
   $ server1 2001
    
   Author: Chen Sun
   */
#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    // sockfd for socket()
    // newsockfd for accept()
    // clilen for accept()
     int sockfd, newsockfd, portno;
     unsigned int clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     /*CREATE SOCKET*/
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     //atoi() convert the string to integer
     portno = atoi(argv[1]);
     // initialize serv_addr
     serv_addr.sin_family = AF_INET;
     // IP address of the machine runs server (INADDR_ANY)
     serv_addr.sin_addr.s_addr = INADDR_ANY; 
     serv_addr.sin_port = htons(portno);// host to network byte
     /*BIND THE SOCKET TO SERVER ADDRESS*/
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     /*ALLOW PROCESS TO LISTEN ON SOCKET FOR CONNECTION*/
     listen(sockfd,5);
     /*ACCEPT BLOCK PROCESS UNTILL CLIENT CONNECT*/
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
     if (newsockfd < 0) 
          error("ERROR on accept");
     /*BEHAVIOR OF THE SERVER*/
     bzero(buffer,256);
     n = read(newsockfd,buffer,255);
     if (n < 0) error("ERROR reading from socket");
     printf("Here is the message: %s\n",buffer);
     n = write(newsockfd,"I got your message",18);
     if (n < 0) error("ERROR writing to socket");
     return 0; 
}