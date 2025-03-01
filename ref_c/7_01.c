#include <stdio.h>

/* copy input to output; 2nd version */
int main(void)
{
    int c; /* instead of char type */

    while ((c = getchar()) != EOF)
        putchar(c);

    return 0;
}
