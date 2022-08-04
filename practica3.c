#include <stdio.h>

int main (int argc, char *argv[]) {
  char *filename = argv[1];
  FILE *fp;
  fp = fopen(filename, "r");
  int c;
  int char_count = 0;
  int line_count = 0;
  int word_count = 0;
  int in_word = 0;
  while ((c = fgetc(fp)) != EOF){
    if (c == '\n') line_count++;
    if (c != ' ' && c != '\n') in_word=1 ;
    else{
      if (in_word != 0)
        word_count++;
        in_word=0;
    }
    char_count++;
  }
  fclose(fp);
  printf("\n");
  printf("cantidad de chars: %d\n", char_count);
  printf("cantidad de lineas: %d\n", line_count);
  printf("cantidad de palabras: %d\n", word_count);
  return 0;
}
