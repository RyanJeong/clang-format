#include <ctype.h>

/* atoi: convert s to integer; version 2 */
int atoi(char s[]) {
  int i, n, sign;

  /* skip white space */
  for (i = 0; isspace(s[i]); ++i) {}
  sign = (s[i] == '-') ? (-1) : 1;
  /* skip sign */
  if ((s[i] == '+') || (s[i] == '-')) ++i;
  for (n = 0; isdigit(s[i]); ++i) n = (n * 10) + (s[i] - '0');

  return sign * n;
}
