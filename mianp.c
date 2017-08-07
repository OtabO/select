//#include <stdio.h>
//#include <unistd.h>
//#include <sys/types.h>
//#include <signal.h>
//#include <stdlib.h>
//#include <poll.h>
//#include <netinet/in.h>
//#include <strings.h>
//
//#define IN_FILES 3
//#define TIME_DELAY 6000
//#define MAX_BUF_SIZE 1024;
//#define MAX(a,b) ((a>b)?(a):(b))
//int main(int argc,char ** argv){
//    struct sockaddr_in servaddr,cliaddr;
//    bzero(&servaddr, sizeof(servaddr));
//    bzero(&cliaddr, sizeof(cliaddr));
//    servaddr.sin_family=AF_INET;
//    servaddr.sin_port=htons(8091);
//    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
//    struct pollfd clients[IN_FILES];
//
//    int serverfd=socket(AF_INET,SOCK_STREAM,0);
//    if(serverfd<0){
//        perror("socket error");
//        exit(-1);
//    }
//
//    if(bind(serverfd,&servaddr, sizeof(servaddr))<0){
//        perror("bind error");
//        exit(-1);
//    }
//
//    if(listen(serverfd,100)<0){
//        perror("listen error");
//        exit(-1);
//    }
//
////    while(1){
//        int connfd=0;
//        if( (connfd = accept(serverfd, NULL,NULL)) == -1){
//            printf("accept socket error");
////            continue;
//        }
//        int clientip = cliaddr.sin_addr.s_addr;
//        printf("Client ip : %d.%d.%d.%d\n",clientip&255,(clientip>>8)&255,
//               (clientip>>16)&255,(clientip>>24)&255);
//        printf("Client prot : %d\n",ntohs(cliaddr.sin_port));
//        char buff[1024];
//        int n = recv(connfd, buff, 1024, 0);
//        printf("recv msg from client: %s\n", buff);
//        close(connfd);
////    }
//}