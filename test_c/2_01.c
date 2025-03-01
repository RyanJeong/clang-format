#include <limits.h>
#include <stdio.h>

int main(void) {
  printf("Minimum signed char\t: %20d\n", SCHAR_MIN);
  printf("Maximum signed char\t: %20d\n", SCHAR_MAX);
  printf("Maximum unsigned char\t: %20u\n", UCHAR_MAX);
  printf("char size\t\t: %lu\n\n", sizeof(char));

  printf("Minimum signed short\t: %20d\n", SHRT_MIN);
  printf("Maximum signed short\t: %20d\n", SHRT_MAX);
  printf("Maximum unsigned short\t: %20u\n", USHRT_MAX);
  printf("short size\t\t: %lu\n\n", sizeof(short));

  printf("Minimum signed int\t: %20d\n", INT_MIN);
  printf("Maximum signed int\t: %20d\n", INT_MAX);
  printf("Maximum unsigned int\t: %20u\n", UINT_MAX);
  printf("int size\t\t: %lu\n\n", sizeof(int));

  printf("Minimum signed long\t: %20ld\n", LONG_MIN);
  printf("Maximum signed long\t: %20ld\n", LONG_MAX);
  printf("Maximum unsigned long\t: %20lu\n", ULONG_MAX);
  printf("long size\t\t: %lu\n\n", sizeof(long));

  return 0;
}
