#include <stdio.h>

int main(void)
{
    int num;

    num = 50000;
    printf("%d\n", num * num); /* Maybe 2 500 000 000 ? */

    return 0;
}
