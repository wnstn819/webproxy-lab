#include "csapp.h"

void echo(int connfd);

int main(int argc, char **argv){
    int listenfd, connfd;
    socklen_t clientlen;
    struct sockaddr_storage clientaddr; /* Enough space for any address */
    char client_hostname[MAXLINE] , client_port[MAXLINE];

    if(argc != 2 ){
        fprintf(stderr, "usage: %s <port> \n", argv[0] );
        exit(0);

    }
    // 포트에 연결 요청을 받을 준비가 된 듣기 식별자를 리턴한다. 
    // getaddrinfo를 호출해서 결과 리스트를 socket과 bind로의 호출이 성공할때까지 탐색
    listenfd = Open_listenfd(argv[1]);
    while(1){
        clientlen = sizeof(struct sockaddr_storage);
        connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen); // 클라이언트로의 연결 요청이 듣기 식별자 listenfd에 도달하기를 기다리리고 연결 식별자를 리턴

        // getaddrinfo의 역으로 소켓 주소 구조체를 대응하는 호스트와 서비스이름 스트링으로 변환한다.
        Getnameinfo((SA *) &clientaddr, clientlen, client_hostname, MAXLINE, client_port, MAXLINE,0);
        printf("Connected to (%s, %s)\n", client_hostname, client_port);
        echo(connfd);
        Close(connfd);

    }
    exit(0);
}