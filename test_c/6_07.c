#include <stdio.h>

union {
  char c;  /* 1 byte */
  short s; /* 2 bytes */
  int i;   /* 4 bytes */
} u;

int main(void) {
  u.i = 0x12345678;

  &u;   /* 0x */
  &u.c; /* 0x */
  &u.s; /* 0x */
  &u.i; /* 0x */

  u.c;
  u.s;
  u.i;

  return 0;
}
