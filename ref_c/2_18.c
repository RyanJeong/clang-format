#include <stdio.h>

/* bitcount: faster version of the bitcount */
void bitcount(unsigned x)
{
    int count;

    for (count = 0; x; ++count)
        x &= (x - 1);
    printf("count: %d\n", count);
}
