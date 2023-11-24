#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int n;
  scanf("%d", &n);

  char *arr = (char *)malloc(sizeof(char) * n);
  arr = "abcde";
  printf("동적 할당된 메모리 크기는 %d bytes 입니다.", (int)strlen(arr));
}