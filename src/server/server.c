#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <arpa/inet.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <netdb.h>

#define IP_ADDRESS "192.168.0.21"
#define PORT 5050

int main(int argc, char* argv[]){
    int sock, client_sock, c, read_size=0;
    struct sockaddr_in server, client;
    char buf[2], state;
    

    //create socket
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("could not create socket\r\n");
    }printf("socket created\r\n");

    //create sockaddr structure
    server.sin_addr.s_addr = inet_addr(IP_ADDRESS);
    server.sin_family = AF_INET;
    server.sin_port = htons( PORT );

    //Bind
    if( bind(sock, (struct sockaddr *) &server, sizeof(server)) < 0){
        perror("bind failed\r\n");
        return -1;
    }printf("bind succesful\r\n");

    //Listen
    if((listen(sock, 5)) != 0){
        printf("listen failed\r\n");
        exit(0);
    };
    printf("server listening\r\n");

    c = sizeof(struct sockaddr_in);
    state = 0;
    
    while(1){
        //Accept incoming connection
        client_sock = accept(sock, (struct sockaddr *)&client, (socklen_t*)&c);
        if (client_sock < 0){
            perror("connection failed\r\n");
            return 1;
        }
        printf("connection accepted\r\n"); 
    
        if(state == 0){
            state = 1;
        }else{
            state = 0;
        }
        sprintf(buf, "%d", state);
        write(client_sock, buf, strlen(buf));

        
    }
    return 0;
}
