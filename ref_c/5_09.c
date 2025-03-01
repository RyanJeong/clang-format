/* strcpy: copy t to s; pointer version */
void strcpy1(char *s, char *t)
{
    int i;

    i = 0;
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

/* strcpy: copy t to s; pointer version 2 */
void strcpy2(char *s, char *t)
{
    while ((*s++ = *t++) != '\0') {}
}

/* strcpy: copy t to s; pointer version 3 */
void strcpy3(char *s, char *t)
{
    while (*s++ = *t++) {}
}
