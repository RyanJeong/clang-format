#include <stdio.h>

/* fputs: put string s on file iop */
/* fputs is already included in stdio.h */
/* int fputs(char *s, FILE *iop) */
int knr_fputs(char* s, FILE* iop) {
  int c;

  while (c = *s++) putc(c, iop);

  /* returns EOF if an error occurs, and non-negative otherwise */
  return ferror(iop) ? EOF : 0;
}
