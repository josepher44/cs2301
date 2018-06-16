#include <stdio.h>

typedef enum {ONE, TWO, THREE} NUMBER;

int main () {
  NUMBER number = THREE;
  printf ("THREE == %d\n", THREE);

  return 0;
}
