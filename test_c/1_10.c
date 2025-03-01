#include <stdio.h>

/* count characters in input; 2nd version */
int main() {
  double nc; /* long 형으로 모자랄 만큼 큰 파일이 있을 것에 대비 */

  for (nc = 0; getchar() != EOF; ++nc) {}
  printf("%.0f\n", nc);

  return 0;
}
