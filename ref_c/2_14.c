#include <stdio.h>

int main(void)
{
    /* a = 5, 0000 0101, b = 9, 0000 1001 */
    unsigned char a = 5, b = 9;

    /* The result is 0000 0001 */
    printf("a & b = %d\n", a & b);
    /* The result is 0000 1101 */
    printf("a | b = %d\n", a | b);
    /* The result is 0000 1100 */
    printf("a ^ b = %d\n", a ^ b);
    /* The result is 1111 1010 */
    printf("~a = %d\n", a = ~a);
    /* The result is 0001 0010 */
    printf("b << 1 = %d\n", b << 1);
    /* The result is 0000 0100 */
    printf("b >> 1 = %d\n", b >> 1);

    return 0;
}
