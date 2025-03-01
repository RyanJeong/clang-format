#include <stdio.h>

/* copy input to output; 2nd version */
int main(void) {
  int c; /* instead of char type */

  /* 연산자 우선순위 !=가 =보다 높음 */
  while ((c = getchar()) != EOF) putchar(c);

  return 0;
}
