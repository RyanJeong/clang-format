#include <stdio.h>

add();

int main(void)
{
    printf("%d", add(4, 5));

    return 0;
}

add(a, b)
{
    return a + b;
}
