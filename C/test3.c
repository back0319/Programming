#include <stdio.h>

int main() {
  struct grade {
    int 국;
    int 영;
    int 수;
    int 컴;
    int 학번;
    char 이름[3];
  } s[3];

  for (int i = 0; i < 3; i++) {
    printf("국 영 수 컴 학번 이름\n");
    scanf("%d %d %d %d %d %s", &s[i].국, &s[i].영, &s[i].수, &s[i].컴,
          &s[i].학번, s[i].이름);
  }

  for (int i = 0; i < 3; i++) {
    printf("국 : %d 영 : %d 수 : %d 컴 :%d 학번 : %d 이름 : %s\n", s[i].국,
           s[i].영, s[i].수, s[i].컴, s[i].학번, s[i].이름);
  }
}