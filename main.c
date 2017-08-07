/*单进程并发服务器实例。该程序采用单进程并发服务器算法实现的。*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <stdlib.h>
#include "list.h"

#define PORT 1234           //服务器端口
#define BACKLOG 5           //listen队列中等待的连接数
#define MAXDATASIZE 1024 //缓冲区大小

typedef struct _ENDPOINT {        //客户端结构体
    int fd;        //客户端socket描述符
    struct sockaddr_in addr;     //客户端地址信息结构体
} endpoint;

void nodeFree(endpoint *ep){
    free(ep);
}
//int main(void) {
//    list *list=listInit();
//    list->free=nodeFree;
//    for(int i=0;i<3;i++){
//        endpoint *ep=malloc(sizeof(endpoint));
//        if(ep==NULL)
//            continue;
//        ep->fd=i;
//        list=listAdd(list,ep);
//    }
//
//    listIter *iter=listGetIter(list,LIST_START_HEAD);
//    node *n=NULL;
//    do{
//        n=listIterNext(iter);
//        endpoint *ep=n->entry;
//        printf("%d",ep->fd);
//        printf("\n");
//        listDelNode(list,n);
//    }while(n!=NULL);
//}

main() {
    fd_set fds;
    int listenfd, connectfd;     //socket文件描述符
    struct sockaddr_in server;     //服务器地址信息结构体
    char recvbuf[MAXDATASIZE];    //缓冲区
    int sin_size;            //地址信息结构体大小

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {    //调用socket创建用于监听客户端的socket
        perror("Creating socket failed.");
        exit(1);
    }

    int opt = SO_REUSEADDR;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));    //设置socket属性

    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = htonl (INADDR_ANY);

    if (bind(listenfd, (struct sockaddr *) &server, sizeof(struct sockaddr)) == -1) {    //调用bind绑定地址
        perror("Bind error.");
        exit(1);
    }

    if (listen(listenfd, BACKLOG) == -1) {      //调用listen开始监听
        perror("listen() error");
        exit(1);
    }
    list *l=listInit();
    endpoint ep;
    ep.fd=listenfd;
    ep.addr=server;
    listAdd(l,&ep);
    while(1){
        FD_ZERO(&fds);
        FD_SET(listenfd,&fds);

    }
}
