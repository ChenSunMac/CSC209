/* A simple server in the Internet domain 
   using TCP
   runs at localhost, e.g. "127.0.0.1"
   DEFAULT PORT = 12543

   $ server
   Take any char read from connected client
    

   Author: Chen Sun
   */

#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*Behavior Function*/
int listento(int fd) {
    char c;
    while(read(fd, &c, 1) > 0) {
        putchar(c);
    }
    return 0;
}

int port = 12543;

int main() {
    /* create listen socket*/
    int listenfd;
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    /*BIND THE SOCKET TO SERVER ADDRESS*/
    // Set sockaddr_in for socket & Bind the sockaddr_in to socket
    struct sockaddr_in r;
    memset(&r, 0, sizeof r);
    r.sin_family = AF_INET;
    r.sin_addr.s_addr = htonl(INADDR_ANY);
    r.sin_port = htons(port);

    if (bind(listenfd, (struct sockaddr *)&r, sizeof r)) {
        perror("bind");
        exit(1);
    }
    /*LISTEN FROM PORT*/
    if (listen(listenfd, 5)) {
        perror("listen");
        exit(1);
    }

    while(1) {
        int fd;
        struct sockaddr_in r;
        socklen_t socklen = sizeof r;
        if ((fd = accept(listenfd, (struct sockaddr *)&r, &socklen)) < 0) {
            perror("accept");
            exit(-1);
            /* exit or do some thing else */
        }

        int fr = fork();
        if(fr == 0) {
            /* child process */
            close(listenfd);
            /* work needed to be done */
            listento(fd);
            return 0;
        } else {
            /* parent process */
            close(fd);
        }
    }
    return 0;
}
