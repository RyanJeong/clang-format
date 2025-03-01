#include <string.h>

char *s, *t;
int n, c;

void f()
{
    strcat(s, t);     /* concatenate t to end of s */
    strncat(s, t, n); /* concatenate n characters of t to end of s */
    strcmp(s, t);     /* return negative, zero, or positive for s < t, s == t,
                         or s > t */
    strncmp(s, t, n); /* same as strcmp but only in first n characters */
    strcpy(s, t);     /* copy t to s */
    strncpy(s, t, n); /* copy at most n characters of t to s */
    strlen(s);        /* return length of s */
    strchr(s, c);     /* return pointer to first c in s, or
                         NULL if not present */
    strrchr(s, c);    /* return pointer to last c in s, or
                         NULL if not present */
}
