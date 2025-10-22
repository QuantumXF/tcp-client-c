#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define IP "142.250.182.164" // IP address of www.google.com  
#define PORT 80 // http


int main(){
  int s = socket(AF_INET,SOCK_STREAM,0);
  struct sockaddr_in sock;
  char *data;
  data = "HEAD / HTTP/1.0\r\n\r\n";
  char buff[512];

  if (s<0) {
    printf("socket() error\n");
    return -1;
  }

  sock.sin_addr.s_addr = inet_addr(IP);
  sock.sin_port = htons(PORT);
  sock.sin_family = AF_INET;
  if (connect(s,(struct sockaddr *)&sock,sizeof(struct sockaddr_in)) != 0) {
    printf("connect() error\n");
    close(s);
  }
  write(s, data, strlen(data));
  memset(buff,0,512);
  read(s,buff,511);
  close(s);
  printf("\n%s\n",buff);
  return 0;
}
