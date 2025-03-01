#include <stdio.h>

int main(void) {
  char str[100];
  int len, a, b;

  a = 3, b = 5;
  len = sprintf(str, "%d + %d = %d", a, b, a + b);
  /* 3 + 5 = 8, return value of sprintf() : 9 */
  printf("%s, return value of sprintf(): %d\n", str, len);

  return 0;
}
