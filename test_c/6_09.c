#include <stdio.h>

struct {
  unsigned int a : 4;
  int b : 4;
} bits;

int main(void) {
  bits.a = bits.b = 0x0F;            /* 1111 */
  printf("%d %d\n", bits.a, bits.b); /* 15 -1 */

  return 0;
}
