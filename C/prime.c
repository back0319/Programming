#include <stdio.h>

int main() {
  int n, i;
  scanf("%d", &n);
  for (i = 2; i < n; i++) {
    if (n % i == 0) {
      printf("소수가 아니다.");
      break;
    } else
      printf("소수입니다");
    break;
  }
}