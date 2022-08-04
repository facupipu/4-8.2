#include <stdio.h>
#define MAXLINE 100

int main (void) {
  char buffer [MAXLINE];
  int http_code[]= {200,201,307,404,500};
  char *http_message[] = {
    "OK",
    "Created",
    "Temporaru Redirect",
    "Not Found",
    "..."
  };

  while (fgets(buffer, MAXLINE, stdin) != NULL) {
    if (buffer[0] == '<') {
      char c;
      char protocol[10];
      int code;
      char message[50];
      sscanf(buffer, "%c %s %d %s", &c, protocol, &code, message);
      int i = 0;
      while ( i < 5 ) {
        if (code == http_code[i]) break;
        i ++;
      }
      printf("%s %s\n", code, http_message);
      return 0;
    }
  }

  return 0;
}
