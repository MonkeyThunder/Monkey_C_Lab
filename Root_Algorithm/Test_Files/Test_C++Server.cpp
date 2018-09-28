#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/stat.h>

int main(){

    struct sockaddr_in servaddr, cliaddr;

    int sockfd;
    int bindfd;
    int accepted_socket;
    int Sizeof_cliaddr;

    sockfd=socket(PF_INET,SOCK_STREAM,0);

    if(sockfd<0){
        std::cout<<"Socket failed"<<std::endl;
        return -1;
    }

    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(55080);
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    bindfd=bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

    if(bindfd<0){
        std::cout<<"Bind Failed"<<std::endl;
        return -1;
    }

    listen(sockfd,3);

    while(true){
        Sizeof_cliaddr= sizeof(cliaddr);
        std::cout<<"Waiting...."<<std::endl;

        accepted_socket=accept(sockfd,(struct sockaddr*)&cliaddr, &Sizeof_cliaddr);

        if(accepted_socket < 0){
            std::cout<<"Accept Failed"<<std::endl;
            return -1;
        }

        std::cout<<"Connected Client"<<std::endl;
    }

    close(sockfd);

    return 0;
}