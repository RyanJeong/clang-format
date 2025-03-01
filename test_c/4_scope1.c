#include <stdio.h>

void foo(int);

int main(void) {
  int a = 100;
  foo(a);
  printf("%d\n", a); /* 100 */

  return 0;
}

void foo(int a) {
  a += 100;
  printf("%d\n", a); /* 200 */
}

void f(register int param) { register int exam; }

void g() {
  int i = 0;

  if (i == 0) {
    int i; /* declare a new variable i */

    for (i = 0; i < 10; ++i) {}
  }
}

int x;
int y;

void func(double x) {
  double y;
  /* ... Skipped ... */
}

void fff() {
  int x = 1;
  char squote = '\'';
  long day = 1000L * 60L * 60L * 24L; /* milliseconds / day */

  int i;

  for (i = 0; i < 10; ++i) {
    char c;

    c = getchar();
    /* ... Skipped ... */
  }
}

int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

char pattern_1[] = "ould";
/* is a shorthand for the longer but equivalent */
char pattern_2[] = {'o', 'u', 'l', 'd', '\0'};

#define foo \
  stmt1;    \
  stmt2;    \
  stmt3;

#define HELLO WORLD
#define HI HELLO /* HI -> WORLD */

int ttt() {
  int expression = 10;
  if (expression) {
    do {
      expression;
      expression;
      expression;
    } while (0);
  }
}

#define TOKENIZER "token"
#define TOKEN "token"

#define forever for (;;) /* infinite loop */
#define MAX(a, b) ((a > b) ? a : b)
int tttt() {
  printf("%s", "TOKEN");
  printf("%s", TOKENIZER);
}
