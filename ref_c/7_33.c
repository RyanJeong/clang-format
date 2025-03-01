#include <stdlib.h>

void srand(unsigned int seed);
int rand(void);

#define frand() ((double) rand() / (RAND_MAX + 1.0))
