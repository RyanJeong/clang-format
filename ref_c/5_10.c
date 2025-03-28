/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
/*
 * s: "cmp", t: "cmp"
 * s: "cm", t: "cmp"
 * s: "cmp", t: "cm"
 * s: "str", t: "cmp"
 */
int strcmp(char *s, char *t)
{
    int i;

    for (i = 0; s[i] == t[i]; i++) {
        if (s[i] == '\0')
            return 0;
    }

    return s[i] - t[i];
}
