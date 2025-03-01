#include <stdio.h>

int main(void) /* rudimentary calculator */
{
  double sum, v;

  sum = 0;
  /* warning: the arguments to scanf and sscanf must be pointers. */
  /* > +1 -2 3.0 4.5e1 s */
  while (scanf("%lf", &v) == 1) printf("\t%.2f\n", sum += v);
  /*
        1.00
        -1.00
        2.00
        47.00
  */

  return 0;
}
