#include <stdio.h>

int fibo(int);

int main(void) {
  int n;
  scanf("%d", &n);
  printf("%d", fibo(n));
}

int fibo(int n) {
  if (n <= 1)
    return 1;
  else
    return fibo(n - 2) + fibo(n - 1);
}