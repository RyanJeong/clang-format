#include <stdio.h>

#define MAXLINE 100

/* rudimentary calculator */
int main(void)
{
    double sum, atof(char[]);
    char line[MAXLINE];
    int getline(char[], int);

    sum = 0;
    while (getline(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));

    return 0;
}
