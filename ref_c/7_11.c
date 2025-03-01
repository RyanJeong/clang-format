#include <stdio.h>

int main(void)
{
    int a, b;

    /*
       $ gcc test_scanf.c -o test_scanf -ansi -Wall

       Case #1
       $ cat in1
       1 3 2 4
       $ ./test_scanf.c < in1
       1 + 3 = 4
       2 + 4 = 6

       Case #2
       $ cat in2
       100 200 300
       $ ./test_scanf.c < in1
       100 + 200 = 300
       300 + 200 = 500
    */
    while (scanf("%d %d", &a, &b) != EOF) /* scanf("%d %d", &a, &b) != 2 */
        printf("%d + %d = %d\n", a, b, a + b);

    return 0;
}
