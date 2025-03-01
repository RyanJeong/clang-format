#include <stdio.h>

#define NSYM 100

struct {
    char *name;
    int flags;
    int utype;
    union {
        int ival;
        float fval;
        char *sval;
    } u;
} symtab[NSYM];

enum { INT, FLOAT, STRING };

void f()
{
    int i = 0;

    if (symtab[i].utype == INT)
        printf("%d\n", symtab[i].u.ival);
    else if (symtab[i].utype == FLOAT)
        printf("%f\n", symtab[i].u.fval);
    else if (symtab[i].utype == STRING)
        printf("%s\n", symtab[i].u.sval);
    else
        printf("bad type %d in utype\n", symtab[i].utype);
}
