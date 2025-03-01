#include <stdio.h>

int main(void) {
  float f1, f2;

  /* > 3.14 1.23e1 */
  scanf("%f %f", &f1, &f2);
  printf("%.2f %.2f\n", f1, f2);
  /* > 3.14 1.23e-1 */
  scanf("%e %e", &f1, &f2);
  printf("%.2f %.2f\n", f1, f2);
  /* > 3.14 1.23e0 */
  scanf("%g %g", &f1, &f2);
  printf("%.2f %.2f\n", f1, f2);

  return 0;
}
