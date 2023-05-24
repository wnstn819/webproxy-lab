#include "csapp.h"

int main(int argc, char **argv){
    int clientfd;
    char *host, *port, buf[MAXLINE];
    rio_t rio;

    if(argc !=3 ){
        fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
        exit(0);
    }

    host = argv[1];
    port = argv[2];

    // Open_clientfd () - 접속을 원하는 서버와 포트의 주소를 getaddrinfo 함수를 통해 가져온다.
    // 생성된 addrinfo 연결리스트 내 주소들과 connect를 시도한다.
    // connect에 성공한 client를 반환한다.
    clientfd = Open_clientfd(host,port);

    // clientfd를 rio의 읽기 버퍼와 연결한다.
    Rio_readinitb(&rio, clientfd);

    while(Fgets(buf, MAXLINE, stdin) != NULL){
        Rio_writen(clientfd, buf, strlen(buf)); // buf에서 clientfd로 n바이트 전송
        Rio_readlineb(&rio, buf, MAXLINE); // 다음 텍스트 줄을 파일 rio에서 읽고, 이것을 buf로 복사
        Fputs(buf,stdout);

    }
    Close(clientfd);
    exit(0);


}