//
// Created by DongHoon Kim on 21/09/2018.
//

#include <iostream>
#include<unistd.h>
#include <arpa/inet.h>

int main(){

    int sock, nbyte;

    struct sockaddr_in servaddr;

    if((sock = socket(PF_INET, SOCK_STREAM,0))<0){
        perror("socket failed !");
        return -1;
    }

    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(55080);
    servaddr.sin_addr.s_addr=inet_addr("kim-lab.net");

    if(connect(sock,(struct sockaddr*)&servaddr, sizeof(servaddr))<0){
        perror("Connection failed !");
        return -1;
    }

    puts("Connection Success !");
    close(sock);

    return 0;
}