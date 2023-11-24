#include <stdio.h>

int main() {
  int sum;
  int score[4][3];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d ", score[i][j]);
    }
  }
  for (int i = 0; i < 4; i++) {
    sum = score[i][0] + score[i][1] + score[i][2];
    printf("%d\n", sum / 3);
    sum = 0;
  }
}