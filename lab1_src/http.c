// http.c

#include "http.h"

#define BUFFER_SIZE (4096)
#define PATH_SIZE (1024)
#define SYNC_SIZE (32)

// 请完成这个函数
// 这个函数的参数是一个字符串，表示原始的请求，你可以用printf打印看看是啥
// 这个函数的返回值是response，表示输出的响应，你需要按照格式来自行构造
// 理论上，你写完这个函数，编译运行，能通过访问 http://127.0.0.1 来交互
// 你可以尝试着让你写的函数去访问htdocs里面的网页，方法是通过读取文件
// 如果你不会写，可以试试最暴力地方法，先自己构造一个静态的response在浏览器里看看效果
// 如果你实在不会，可以在answer文件夹里参考答案，然后自己独立实现出来
char *http_process(char *request) {
  char value[BUFFER_SIZE];
  char http_version[SYNC_SIZE];
  char *start_position = strstr(request,"HTTP/");
  char *end_position = strchr(start_position, '\n');
  size_t substring_length = end_position - start_position;
  memcpy(http_version, start_position, substring_length);
  http_version[substring_length] = '\0';

  char path[PATH_SIZE];
  char path2[PATH_SIZE];
  _getcwd(path, PATH_SIZE);

  static char response[BUFFER_SIZE];
  *response = '\0';

  FILE *rdfile;

  // printf("%s", request);
  
  strcat(path, "\\");
  strcat(path, "htdocs");

  char *start_position2 = strstr(request,"/");
  char *end_position2 = strchr(start_position2,' ');
  substring_length = end_position2 - start_position2;
  memcpy(path2, start_position2, substring_length);
  for (int i=0;path2[i]!='\0';i++) 
    if (path2[i] == '/') path2[i] = '\\';
  path2[substring_length] = '\0';
  strcat(path, path2);
  if (strcmp(path2, "\\") == 0) strcat(path, "\\index.html");

  strcat(response, http_version);
  strcat(response, " ");

  rdfile = fopen(path, "r");

  if(rdfile) {
    strcat(response, "200 OK\r\n");
  } else {
    strcat(response, "404 Not Found\r\n");
  }
  
  strcat(response, "Server: ExLab1\r\n");
  strcat(response, "Connection: close\r\n");
  strcat(response, "Content-type: text/html\r\n");
  
  strcat(response, "\r\n");
  
  if(rdfile) {
    while(fgets(value, BUFFER_SIZE, rdfile) != NULL) {
      strcat(response, value);
    }
    fclose(rdfile);
  } else {
    strcpy(path, "htdocs");
    strcat(path, "\\404.html");
    rdfile = fopen(path, "r");
    if(rdfile) {
      while(fgets(value, BUFFER_SIZE, rdfile) != NULL) {
        strcat(response, value);
      }
      fclose(rdfile);
    }
  }

  return response;
}
