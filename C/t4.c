#include <stdio.h>

int main() {
  char name[2][20];
  int y = 0;
  while (y < 2) {
    printf("이름 : ");
    scanf("%9s", name[y]);
    printf("\n");

    y += 1;
  }
  printf("\n");
  y = 0;
  while (y < 2) {
    printf("이름 : %s\n", name[y]);
    printf("\n");
    y += 1;
  }
}