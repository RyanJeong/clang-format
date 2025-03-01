#include <stdio.h>

int main(void)
{
    int n;
    char c;

    scanf("%d", &n); /* expect '\n' */
    getchar();
    scanf("%c", &c);
    printf("int: %d, char: %c\n", n, c);

    return 0;
}
