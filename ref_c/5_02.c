#include <stdio.h>

int main(void)
{
    int a[] = { 1, 2, 3 };
    int *p = a + 2;

    /* 2 1 ???? */
    printf("%d %d %d\n", p[-1], p[-2], p[-3]);

    return 0;
}
