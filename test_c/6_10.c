struct {
  unsigned int a : 1;
  unsigned int b : 2;
  unsigned int c : 4;
  unsigned int : 1;
  unsigned int d : 8;
} bits;

int main(void) {
  bits.a = 1;   /*         1 */
  bits.b = 2;   /*        10 */
  bits.c = 15;  /*      1111 */
  bits.d = 128; /* 1000 0000 */

  return 0;
}
