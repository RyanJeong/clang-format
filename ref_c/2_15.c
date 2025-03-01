#include <stdio.h>

int main(void)
{
    /* x = 248, 1111 1000 */
    unsigned char x = 248;

    /* The result is 0011 1000 */
    printf("x & 077 = %d\n", x & 077); /* mask operation */

    /* The result is 1111 1111 */
    printf("x | 07 = %d\n", x | 07); /* set operation */

    /* The result is 1100 0000 */
    printf("x & ~077 = %d\n", x & ~077); /* better than 0x300 */
    /*
     * 0x300, which assumes that x is a 8-bit quantity
     * ~077 is independent of word length
     */

    return 0;
}
