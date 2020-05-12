// very simple http request. 01 of 68ex (https://github.com/jinto/68ex)
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFF_SIZE  (1024*10)

char* req = "GET /\n";

int main( int argc, char **argv)
{
    int     sock;
    char    buff[BUFF_SIZE+5];
    struct  sockaddr_in sock_addr;

    sock  = socket(PF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        printf("Cannot create sockert.\n");
        exit(1);
    }

    memset(&sock_addr, 0, sizeof(sock_addr));
    sock_addr.sin_family     = AF_INET;
    sock_addr.sin_port       = htons( 80);
    sock_addr.sin_addr.s_addr= inet_addr("172.217.31.142");     // ping google.com

    if(connect(sock, (struct sockaddr*)&sock_addr, sizeof(sock_addr)) == -1) {
        printf("Failed to conn (errno: %d)\n", errno);
        exit(1);
    }

    write(sock, req, strlen(req)+1);
    printf("SENT:\n%s", req);

    read(sock, buff, BUFF_SIZE);
    printf("READ:\n%s\n", buff);

    close(sock);
    return 0;
}
