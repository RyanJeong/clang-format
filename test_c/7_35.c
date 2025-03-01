/* The template of random number generation */
#include <stdio.h>
#include <stdlib.h> /* srand(), rand() */
#include <time.h>   /* time() */

int main(void) {
  srand(time(NULL));
  printf("Random Number: %d\n", rand());

  return 0;
}
