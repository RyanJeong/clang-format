#include <stdio.h>

int main(void)
{
    int i;

    fscanf(stdin, "%d", &i);    /* = scanf() */
    fprintf(stdout, "%d\n", i); /* = printf() */

    return 0;
}
