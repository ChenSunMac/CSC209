#include <sys/types.h>          
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>

#define PORT 12543
int main() {
    const char* ipaddr="127.0.0.1";
    int soc;
    char buf[256];
    struct hostent *hp;
    struct sockaddr_in peer;
    peer.sin_family = AF_INET;
    peer.sin_port = htons(PORT);
    /* fill in peer address */
    hp = gethostbyname(ipaddr);
    if ( hp == NULL ) {
        // fprintf(stderr, "%s: %s unknown host\n",
        //    argv[0], argv[1]);
        exit(1);
    }
    peer.sin_addr = *((struct in_addr *)hp->h_addr);
    /* create socket */
    if((soc = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
    }
    /* request connection to server */
    if (connect(soc, (struct sockaddr *)&peer, sizeof(peer)) == -1) {
        perror("client:connect"); close(soc);
        exit(1);
    }
    char c;
    while(read(1, &c, 1) > 0) {
        write(soc, &c, 1);
    }
}
