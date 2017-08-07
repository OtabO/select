//
// Created by zhangsx on 2017/8/4.
//

#ifndef UNTITLED_SERVER_H
#define UNTITLED_SERVER_H

#endif //UNTITLED_SERVER_H
typedef struct _ENDPOINT {        //客户端结构体
    int fd;        //客户端socket描述符
    struct sockaddr_in* addr;     //客户端地址信息结构体
} endpoint;