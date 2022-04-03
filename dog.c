#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cat(const char *str) {
	FILE *file = fopen(str, "r");
  char err[strlen(str) + 6];
  *(err + 0) = 'c';
  *(err + 1) = 'a';
  *(err + 2) = 't';
  *(err + 3) = ':';
  *(err + 4) = ' ';

  if(!file) {
    strcat(err, str);
    perror(err);
    exit(-1);
  }

  int c;

  while((c = fgetc(file)) != EOF)
    putchar(c);

  fclose(file);
}

int main(int argc, const char **argv) {
	if(argc < 2) {
		putchar('\x0A');
		return -1;
	}

	for(unsigned short int i = 1; i < argc; i++)
		cat(*(argv + i));

	return 0;
}
