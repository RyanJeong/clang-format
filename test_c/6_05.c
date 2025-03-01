#include <stdio.h>

int main(void) {
  /* case #1 */
  struct {
    char c1;
    char c2;
    char c3;
  } ccc;

  /* case #2 */
  struct {
    short s;
    int i;
    char c;
  } sic;

  /* case #3 */
  struct {
    short s;
    char c;
    int i;
  } sci;

  printf("size of ccc is %ld\n", sizeof ccc);
  printf("size of sic is %ld\n", sizeof sic);
  printf("size of sci is %ld\n", sizeof sci);

  return 0;
}
