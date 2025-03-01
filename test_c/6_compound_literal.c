/*
https://gcc.gnu.org/onlinedocs/gcc/Compound-Literals.html
*/
struct point {
  int x;
  int y;
};

// clang-format off
int a = 3;
int b = 4;
struct point global1 = { 3, 4 }; /* OK */
struct point global2 = { a, b }; /* Error */
struct point global3, global4;
global3 = { 3, 4 };               /* Error */
global4 = (struct point) { 3, 4 }; /* Error */
// clang-format on

int main(void) {
  // clang-format off
  int a = 5;
  int b = 6;
  struct point itnl1 = { 5, 6 }; /* OK */
  struct point itnl2 = { a, b }; /* OK */
  struct point itnl3, itnl4;
  itnl3 = { a, b };                /* Error */
  itnl4 = (struct point) { a, b }; /* OK */
  // clang-format on

  return 0;
}