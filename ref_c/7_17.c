#include <stdio.h>

int main(void)
{
    char str1[2], str2[10], str3[10];
    int a, b, c;

    /* > suppression */
    scanf("%2c %*2c %4s %6s", str1, str2, str3);
    /* su ress ion */
    printf("%c%c %s %s\n", str1[0], str1[1], str2, str3);
    /* > 123 456789 */
    scanf("%2d %d %*4d %d", &a, &b, &c);
    /* 12 3 89 */
    printf("%d %d %d\n", a, b, c);

    return 0;
}
