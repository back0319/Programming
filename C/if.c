#include <stdio.h>

int main(void) {
  int k, m;
  printf("국어 : ");
  scanf("%d", &k);
  if (k >= 90)
    printf("A");
  else if (k >= 80)
    printf("B");
  else if (k >= 70)
    printf("C");
  else if (k >= 60)
    printf("D");
  else
    printf("F");
  printf("\n");

  printf("수학 : ");
  scanf("%d", &m);
  if (m >= 90)
    printf("A");
  else if (m >= 80)
    printf("B");
  else if (m >= 70)
    printf("C");
  else if (m >= 60)
    printf("D");
  else
    printf("F");
  printf("\n");

  if (k >= 90 && m >= 90)
    printf("축하합니다\n");
  else if (k < 60 || m < 60)
    printf("분발하세요");
}