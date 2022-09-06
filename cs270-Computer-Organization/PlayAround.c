#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main()
  {
  int w = 1;
  int x = 6;
  int y = 5;
  int z = 0;

  z = !z || !x && !y;
  printf("%d\n", z);
  z = x-- == y + 1;
  printf("%d\n", z);
  z = (x / y++) * z + (x % w);
  printf("%d\n", z);
  z = (x++ < (--y + w)) ? 10 : z;
  printf("%d\n", z);
  z += z;
  printf("%d\n", w);
  printf("%d\n", x);
}