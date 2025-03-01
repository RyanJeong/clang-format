#include <stdio.h>

int main(void) {
  int day, month, year;

  /*
     case #1
     > 05/15/21
     3
     month: 5, day: 15, year: 21

     case #2
     > 05 15 21
     1
     month: 5, day: ??, year: ??
  */
  printf("%d\n", scanf("%d/%d/%d", &month, &day, &year));
  printf("month: %d, day: %d, year: %d\n", month, day, year);

  return 0;
}
