#include <ctype.h>

int c;

void f() {
  isalpha(c); /* non-zero if c is alphabetic, 0 if not */
  isupper(c); /* non-zero if c is upper case, 0 if not */
  islower(c); /* non-zero if c is lower case, 0 if not */
  isdigit(c); /* non-zero if c is digit, 0 if not */
  isalnum(c); /* non-zero if isalpha(c) or isdigit(c), 0 if not */
  isspace(c); /* non-zero if c is blank, tab, newline, return, formfeed,
                 vertical tab */
  toupper(c); /* return c converted to upper case */
  tolower(c); /* return c converted to lower case */
}
