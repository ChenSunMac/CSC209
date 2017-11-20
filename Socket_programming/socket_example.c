/*
 * gethostbyname() Example 
 * —— 用域名或主机名获取IP地址 
 * 
 * $ ./socket_example www.baidu.com
 * Author: Chen(Joseph) Sun 
 */

#include <sys/socket.h>
#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    char   *ptr, **pptr;
    // hostent defined in <arpa/inet.h>
    struct hostent *hptr;
    char   str[32];
    ptr = argv[1];

    // gethostbyname() defined in <netdb.h>
    if((hptr = gethostbyname(ptr)) == NULL)
    {
        printf(" gethostbyname error for host:%s\n", ptr);
        return 0;
    }

    printf("official hostname:%s\n",hptr->h_name);
    for(pptr = hptr->h_aliases; *pptr != NULL; pptr++)
        printf(" alias:%s\n",*pptr);

    switch(hptr->h_addrtype)
    {
        case AF_INET:
        case AF_INET6:
            pptr=hptr->h_addr_list;
            for(; *pptr!=NULL; pptr++)
                printf(" address:%s\n",
                       inet_ntop(hptr->h_addrtype, *pptr, str, sizeof(str)));
            printf(" first address: %s\n",
                       inet_ntop(hptr->h_addrtype, hptr->h_addr, str, sizeof(str)));
        break;
        default:
            printf("unknown address type\n");
        break;
    }

    return 0;
}