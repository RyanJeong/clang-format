#include <stdio.h>

int main(void)
{
    /* a minus sign with minimum width */
    printf("%6d\n", 100);
    printf("%-6d\n", 100);
    printf("%6d\n", 1000000);
    printf("%-6d\n", 1000000);

    char *s = "Hello, world"; /* 12 */

    /* string with precision */
    printf(":%s:\n", s);
    printf(":%10s:\n", s);
    printf(":%.10s:\n", s);
    printf(":%-10s:\n", s);
    printf(":%15s:\n", s);
    printf(":%.15s:\n", s);
    printf(":%-15s:\n", s);
    printf(":%15.10s:\n", s);
    printf(":%-15.10s:\n", s);

    /* floating type value with precision */
    printf("%9.2f\n", 3.141592);
    printf("%-9.2f\n", 3.141592);
    printf("%9.6f\n", 3.141592);
    printf("%-9.6f\n", 3.141592);

    /* integer type value with precision */
    printf("%.5d\n", 12);
    printf("%5.5d\n", 1234);
    printf("%8.5d\n", 1234);
    printf("%-8.5d\n", 1234);
    printf("%8.5d\n", 123456);
    printf("%-8.5d\n", 123456);

    /* convert integer type to short or long */
    printf("%.4hd\n", (short) 123);
    printf("%6.4hd\n", (short) 123);
    printf("%.2ld\n", (long) 123);
    printf("%6.5ld\n", (long) 123);
    printf("%-6.5ld\n", (long) 123);

    printf("%d\n", 1 << 16);
    printf("%hd\n", 1 << 16);
    printf("%6hd\n", 1 << 16);

    printf("%d\n", (long) 1 << 32);
    printf("%ld\n", (long) 1 << 32);
    printf("%-12ld\n", (long) 1 << 32);

    double d1 = 0.125;              /* 1 ÷ 8 */
    double d2 = 0.0000152587890625; /* 1 ÷ 65,536 */
    double d3 = 1234.56;

    printf("%f\n", d1);
    printf("%e\n", d1);
    printf("%g\n", d1);

    printf("%f\n", d2);
    printf("%E\n", d2);
    printf("%G\n", d2);

    printf("%g\n", d3);
    printf("%.2g\n", d3);

    printf("%p\n", &d3);
    printf("%%\n");

    printf("%*.*s\n", 3, 3, "ABCDE");
    printf("%*.*s\n", 4, 3, "ABCDE");
    printf("%*.*s\n", 4, 5, "ABCDE");

    printf(s);         /* Fail if s contains '%' */
    printf("%s\n", s); /* Safe */

    int i = 15;
    int o = 077;
    int h = 0xFF;
    unsigned u = 1 << 31; /* int: -2^31 ~ 2^31 - 1 */
    char c = 'Z';

    printf("%3d %3o %3x %3X\n", i, i, i, i);
    printf("%3d %3o %3x %3X\n", o, o, o, o);
    printf("%3d %3o %3x %3X\n", h, h, h, h);
    printf("%u\n", u);
    printf("%3c %3d %3x %3X\n", c, c, c, c);

    return 0;
}
