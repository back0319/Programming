#include <stdio.h>

int main() {
  int n, m, i, j;
  scanf("%d %d", &n, &m);
  printf("공약수 : ");
  for (i = 1; i <= n && i <= m; i++) {
    if (n % i == 0 && m % i == 0) {
      printf("%d ", i);
      j = i;
    }
  }
  printf("\n최대공약수 : %d", j);
}