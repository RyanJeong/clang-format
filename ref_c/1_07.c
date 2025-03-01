#include <stdio.h> /* Already defined EOF(-1) in stdio.h */

/* copy input to output; 1st version */
int main(void)
{
    int c;

    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }

    return 0;
}
