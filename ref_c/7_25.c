#include <stdio.h>

/* fgets: get at most n chars from iop */
char *fgets(char *s, int n, FILE *iop)
{
    register int c;
    register char *cs;

    cs = s;
    /*
    1. n-1 characters will be read
    2. returns EOF for end of file or error
    */
    while (--n > 0 && (c = getc(iop)) != EOF) {
        /* reads the next input line (including the newline) from file iop */
        if ((*cs++ = c) == '\n')
            break;
    }
    *cs = '\0';

    /* normally fgets returns s(pointer);
       on end of file or error it returns NULL */
    return (c == EOF && cs == s) ? NULL : s;
}
