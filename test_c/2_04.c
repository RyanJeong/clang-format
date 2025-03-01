#include <float.h>
#include <stdio.h>

int main(void) {
  float a, b, c, res1, res2;

  a = 1e20; /* scientific notation, 10 to the 20th power */
  b = -1e20;
  c = 1.0;

  /* Are the expressions a + (b + c) and (a + b) + c the same? */
  res1 = a + (b + c);
  res2 = (a + b) + c;
  printf(
      "Maximum float: %e\n"
      "The expressions a + (b + c) and (a + b) + c are %s.\n",
      FLT_MAX,
      (res1 == res2) ? "the same" : "not the same");

  return 0;
}
