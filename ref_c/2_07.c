#include <stdio.h>

#define ON 0
enum boolean { NO, YES };

int main(void)
{
    enum boolean state;

    state = 0;
    state = 1;
    state = ON;

    printf("%d\n", state);

    return 0;
}
