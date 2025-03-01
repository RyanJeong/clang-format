#include <stdio.h>

int main(void)
{
    char string[32] = "1 12.3 sscanf";
    int i;
    double d;
    char str[32];

    sscanf(string, "%d %lf %s", &i, &d, str);
    printf("int: %d, double: %f, string: %s\n", i, d, str);

    return 0;
}
