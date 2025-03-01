#include <stdio.h>

int main(void) {
  int n;
  char c;

  /* C89, § 7.9.6.2. A directive composed of white-space character(s)
                     is executed by reading input up to the first
                     non-white-space character (which remains unread),
                     or until no more characters can be read. */
  scanf("%d ", &n); /* expect '\n' */
  scanf("%c", &c);
  printf("int: %d, char: %c\n", n, c);

  return 0;
}
