#include <stdio.h>
#include <stdlib.h>

int main() {

  unsigned int num = 42;
  printf("Num = ");
  scanf("%u", &num);
  printf("%x\n", num);

  while (num != 0) {
  }

  return 0;
}