#include <stdio.h>

int main(void) {
  int i = 0x00000001;

  /*
    if little endian, 01 00 00 00
    else,             00 00 00 01
  */
  printf("%s\n", *((char*)&i) ? "Little Endian" : "Big Endian");

  return 0;
}
