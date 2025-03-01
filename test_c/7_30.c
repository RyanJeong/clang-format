#include <stdio.h>

int skipwhite(FILE* f) {
  int c;

  do {
    c = getc(f);
  } while (isspace(c));

  return ungetc(c, f);
}
