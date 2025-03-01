#include <stdio.h>

int main(void) {
  char* str;
  char c0, c1, c2, c3;
  int i;
  float f;

  str = "DJU"; /* 'D'(44), 'J'(4A), 'U'(55), '\0'(00) */
  c0 = str[0];
  c1 = str[1];
  c2 = str[2];
  c3 = str[3];
  i = *((int*)str);
  f = *((float*)str);
  printf("1. string: %s\n", str);
  printf(
      "2. char: \n"
      "\tchar str[0] : %1c(%02X), \n"
      "\tchar str[1] : %1c(%02X), \n"
      "\tchar str[2] : %1c(%02X), \n"
      "\tchar str[3] : %2c(%02X), \n",
      c0,
      c0,
      c1,
      c1,
      c2,
      c2,
      c3,
      c3);
  printf("3. int: %d(%08X)\n", i, i);
  printf("4. float: %e\n", f);

  return 0;
}
