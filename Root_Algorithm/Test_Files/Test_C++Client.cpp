//
// Created by DongHoon Kim on 21/09/2018.
//

#include <iostream>
#include <string.h>
#include<unistd.h>
#include <arpa/inet.h>

int main(){

    int sock, nbyte;
    char buff_in[255];
    char buff_out[255];

    struct sockaddr_in servaddr;

    if((sock = socket(PF_INET, SOCK_STREAM,0))<0){
        perror("socket failed !");
        return -1;
    }

    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(55080);
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    if(connect(sock,(struct sockaddr*)&servaddr, sizeof(servaddr))<0){
        perror("Connection failed !");
        return -1;
    }
    puts("Connection Success !");
    while(true){


        std::cout<<"Txt = ";
        fgets(buff_out, 255, stdin);

        write(sock,buff_out,255);

        if(strncmp(buff_out,"quit",4)==0){
            close(sock);
            std::cout<<"Connection Finished"<<std::endl;
            exit(0);
        }

        read(sock,buff_in,255);
        std::cout<<buff_in<<std::endl;
    }


    close(sock);

    return 0;
}