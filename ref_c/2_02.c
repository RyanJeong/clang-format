#include <stdio.h>

int main(void)
{
    float f1, f2, f3, f4, f5, f6, f7;

    f1 = 9999876.0;  /* 7 자리, 값이 정확히 출력될 것을 보장 */
    f2 = 99998765.0; /* 8 자리, 값이 정확히 출력될 것을 보장받지 못함*/
    f3 = 16777216.0; /* 1.00000000000000000000000 X 2^24 */
    f4 = 16777216.5; /* f3과 동일한 결과, 값을 표현할 bit 수 부족 */
    f5 = 16777217.0; /* f3과 동일한 결과, 값을 표현할 bit 수 부족 */
    f6 = 16777218.0; /* 1.00000000000000000000001 X 2^24 */
    f7 = 27.1;       /* 271 / 10, 10은 2^n 형태로 표현 불가 -> 순환소수 */

    printf("A single-precision only has about 7 decimal digits of precision.\n"
           "before: 9999876.0, after: %10.1f\n"
           "before: 99998765.0, after: %10.1f\n\n",
           f1, f2);
    printf("16777216.0, 16777216.5, 16777217.0 are represented exactly "
           "by the same value in the single-precision data type.\n"
           "before: 16777216.0, after: %10.1f\n"
           "before: 16777216.5, after: %10.1f\n"
           "before: 16777217.0, after: %10.1f\n"
           "before: 16777218.0, after: %10.1f\n\n",
           f3, f4, f5, f6);
    printf("27.1 (may be simply 271/10) cannot be expressed as 2^n.\n"
           "27.1 (precision is 6): %.6f\n"
           "27.1 (precision is 8): %.8f\n"
           "27.1 (precision is 10): %.10f\n\n",
           f7, f7, f7);

    return 0;
}
