#include <stdio.h>

int main() {
  int data[3][4] = {0};
  float avg[4] = {0.0};
  char *subject[4] = {"국", "영", "수", "컴"};

  for (int i = 0; i < 3; i++) {
    printf("%d 번째 학생의 점수\n", i + 1);
    for (int j = 0; j < 4; j++) {
      printf("%s : ", subject[j]);
      scanf("%d", data[i][j]);
      avg[j] += data[i][j];
    }
  }

  for (int i = 0; i < 4; i++) {
    printf("\n%s 평균 : %.2f\n", subject[i], avg[i] / 3);
  }
}