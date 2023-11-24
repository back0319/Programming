#include <stdio.h>

char upper(char a);

int main() {
  char c;
  while ((c = getchar()) != -1) putchar(upper(c));
}

char upper(char a) {
  if (a >= 'a' && a <= 'z')
    return (a - 32);
  else
    return (a);
}