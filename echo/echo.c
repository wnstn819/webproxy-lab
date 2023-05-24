#include "csapp.h"

void echo(int connfd){
    size_t n;
    char buf[MAXLINE];
    rio_t rio;

    Rio_readinitb(&rio,connfd); // 읽고 싶은 파일 식별자 'fd' 와 읽기 버퍼 'rp' 를 연결한다.
    while((n= Rio_readlineb(&rio, buf, MAXLINE)) != 0){ // 텍스트 라인 전체를 내부 읽기 버퍼 'rp' 에서 읽은 후, 메모리 버퍼 'usrbuf'로 보
        printf("server received &d bytes\n", (int)n);
        Rio_writen(connfd,buf,n);// buf에서 connfd로 n바이트 전송
    }
}