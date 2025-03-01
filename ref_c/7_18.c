#include <stdio.h>

int main(void)
{
    short s;
    int i;
    long l;
    float f;
    double d;
    long double ld;

    /* integer */
    scanf("%hd %d %ld", &s, &i, &l);

    /* floating-point */
    scanf("%f %lf %Lf", &f, &d, &ld);

    return 0;
}
