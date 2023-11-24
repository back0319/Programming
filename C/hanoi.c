#include <stdio.h>

void H(int n, char x, char y, char z) {
  if (n == 1)
    printf("%c -> %c\n", x, y);
  else {
    H(n - 1, x, z, y);
    printf("%c -> %c\n", x, z);
    H(n - 1, y, x, z);
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  H(n, 'X', 'Y', 'Z');
}