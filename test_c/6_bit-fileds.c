#include <stdio.h>

struct {
  unsigned int a : 1;
  unsigned int b : 2;
  unsigned int : 0; /* next unsigned int */
  unsigned int c : 1;
  unsigned int d : 8;
} f;

struct {
  unsigned int a : 1;
  unsigned int b : 2;
  unsigned int c : 4;
  unsigned int : 1;
  unsigned int d : 8;
} bits;

int main(void) {
  f.a = 1;
  f.b = 2;
  f.c = 1;
  f.d = 128;
  printf("%u %u %u %u\n", f.a, f.b, f.c, f.d);

  void* p = &f;
  unsigned u1 = *((unsigned*)p);
  unsigned u2 = *((unsigned*)p + 1);
  /* 0000 0000 0000 0101 */
  printf("%u\n", u1);
  /* 0000 0001 0000 0001 */
  printf("%u\n", u2);

  bits.a = 1;   /*         1 */
  bits.b = 2;   /*        10 */
  bits.c = 15;  /*      1111 */
  bits.d = 128; /* 1000 0000 */
  void* pbits = &bits;
  /* 1000 0000 0111 1101 */
  printf("%u\n", *((unsigned*)pbits));

  return 0;
}
