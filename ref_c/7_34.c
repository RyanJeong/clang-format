#include <math.h>
#include <stdio.h>

int main(void)
{
    double theta;

    for (theta = 0.0; theta <= 180.0; theta += 30.0)
        printf("%f\n", pow(sin(theta), 2) + pow(cos(theta), 2));

    return 0;
}
