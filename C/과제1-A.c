#include <stdio.h>
#include <stdlib.h>

// 집합을 저장할 구조체 정의
typedef struct Set {
  int elements[100];
} Set;

// 집합 저장 공간을 할당하고 초기화하는 함수
int *createSet() {
  // 1. 메모리 할당: int 형 배열을 동적으로 할당하여 집합을 표현합니다.
  int *newSet = (int *)malloc(sizeof(int) * 100);
  if (newSet == NULL) {
    printf("메모리 할당 오류\n");
    exit(1);
  }
  // 2. 초기화: 모든 원소를 0으로 초기화하여 공집합으로 만듭니다.
  for (int i = 0; i < 100; i++) {
    newSet[i] = 0;
  }
  // 3. 생성된 집합의 포인터를 반환합니다.
  return newSet;
}

// 집합을 제거하는 함수
void deleteSet(int *s) {
  // 동적으로 할당된 메모리를 해제합니다.
  free(s);
}

// 집합이 공집합인지 확인하는 함수
int isEmpty(int *s) {
  // 1. 집합의 모든 원소를 확인하며 1인 원소가 있는지 체크합니다.
  for (int i = 0; i < 100; i++) {
    if (s[i] == 1) {
      return 0;  // 공집합이 아님
    }
  }
  // 2. 모든 원소가 0이면 공집합임을 반환합니다.
  return 1;  // 공집합임
}

// 집합의 원소 개수를 반환하는 함수
int cardinality(int *s) {
  int count = 0;
  // 집합의 원소를 카운트합니다.
  for (int i = 0; i < 100; i++) {
    if (s[i] == 1) {
      count++;
    }
  }
  // 카운트된 원소의 개수를 반환합니다.
  return count;
}

// 원소가 집합에 속하는지 확인하는 함수
int isElement(int x, int *s) {
  // 1. 주어진 원소 x의 범위를 확인하고, 해당 원소의 집합 내 포함 여부를
  // 체크합니다.
  if (x >= 0 && x <= 99 && s[x] == 1) {
    return 1;  // 원소가 집합에 속함
  }
  return 0;  // 원소가 집합에 속하지 않음
}

// 원소를 집합에 추가하는 함수
int addElement(int x, int **s) {
  // 1. 주어진 원소 x의 유효성을 검사하고, 해당 원소를 집합에 추가합니다.
  if (x >= 0 && x <= 99) {
    if ((*s)[x] == 0) {
      (*s)[x] = 1;
      return 1;  // 추가 성공
    } else {
      return 0;  // 이미 존재하는 원소
    }
  } else {
    return 0;  // 유효하지 않은 원소
  }
}

// 원소를 집합에서 제거하는 함수
int removeElement(int x, int *s) {
  // 1. 주어진 원소 x의 유효성을 검사하고, 해당 원소를 집합에서 제거합니다.
  if (x >= 0 && x <= 99) {
    if (s[x] == 1) {
      s[x] = 0;
      return 1;  // 제거 성공
    } else {
      return 0;  // 제거 대상 원소가 없음
    }
  } else {
    return 0;  // 유효하지 않은 원소
  }
}

// 집합 a가 집합 b의 부분집합인지 확인하는 함수
int isSubset(int *a, int *b) {
  // 1. 집합 a의 모든 원소가 집합 b에 포함되어 있는지 확인합니다.
  for (int i = 0; i < 100; i++) {
    if (a[i] == 1 && b[i] == 0) {
      return 0;  // a의 원소 중 b에 없는 것이 있음
    }
  }
  // 2. 모든 a의 원소가 b에 포함되어 있으면 부분집합임을 반환합니다.
  return 1;  // 모든 a의 원소가 b에 포함됨
}

// 집합 a와 집합 b가 같은지 확인하는 함수
int isEqual(int *a, int *b) {
  // 1. 두 집합의 모든 원소를 비교하여 같은지 확인합니다.
  for (int i = 0; i < 100; i++) {
    if (a[i] != b[i]) {
      return 0;  // 다른 원소가 있음
    }
  }
  // 2. 모든 원소가 같으면 두 집합이 같음을 반환합니다.
  return 1;  // 모든 원소가 같음
}

// 집합 a와 집합 b가 서로소(교집합이 공집합)인지 확인하는 함수
int isDisjoint(int *a, int *b) {
  // 1. 두 집합의 교집합이 비어있는지 확인합니다.
  for (int i = 0; i < 100; i++) {
    if (a[i] == 1 && b[i] == 1) {
      return 0;  // 교집합이 비어있지 않음
    }
  }
  // 2. 교집합이 비어있으면 서로소임을 반환합니다.
  return 1;  // 교집합이 공집합임
}

// 집합 a와 집합 b의 교집합을 생성해 반환하는 함수
int *intersection(int *a, int *b) {
  // 1. 교집합을 저장할 새로운 집합을 생성합니다.
  int *result = createSet();
  // 2. 두 집합의 각 원소를 비교하여 교집합을 계산합니다.
  for (int i = 0; i < 100; i++) {
    if (a[i] == 1 && b[i] == 1) {
      result[i] = 1;  // 교집합에 해당 원소를 추가
    }
  }
  // 3. 계산된 교집합을 반환합니다.
  return result;
}

// 집합 a와 집합 b의 합집합을 생성해 반환하는 함수
int *unionSet(int *a, int *b) {
  // 1. 합집합을 저장할 새로운 집합을 생성합니다.
  int *result = createSet();
  // 2. 두 집합의 각 원소를 비교하여 합집합을 계산합니다.
  for (int i = 0; i < 100; i++) {
    if (a[i] == 1 || b[i] == 1) {
      result[i] = 1;  // 합집합에 해당 원소를 추가
    }
  }
  // 3. 계산된 합집합을 반환합니다.
  return result;
}

// 집합 a와 집합 b의 차집합을 생성해 반환하는 함수
int *difference(int *a, int *b) {
  // 1. 차집합을 저장할 새로운 집합을 생성합니다.
  int *result = createSet();
  // 2. 집합 a의 각 원소가 집합 b에 속하지 않는지 확인하여 차집합을 계산합니다.
  for (int i = 0; i < 100; i++) {
    if (a[i] == 1 && b[i] == 0) {
      result[i] = 1;  // 차집합에 해당 원소를 추가
    }
  }
  // 3. 계산된 차집합을 반환합니다.
  return result;
}

int main() {
  int *a = createSet();
  int *b = createSet();

  printf("집합 a를 입력하세요 (0부터 99까지의 정수를 입력, -1 입력시 종료): ");
  int x;
  while (1) {
    scanf("%d", &x);
    if (x == -1) {
      break;  // 입력 종료
    }
    if (x >= 0 && x <= 99) {
      a[x] = 1;  // 입력된 원소를 집합 a에 추가
    } else {
      printf("유효하지 않은 원소입니다. 0부터 99까지의 정수를 입력하세요.\n");
    }
  }

  printf("집합 b를 입력하세요 (0부터 99까지의 정수를 입력, -1 입력시 종료): ");
  while (1) {
    scanf("%d", &x);
    if (x == -1) {
      break;  // 입력 종료
    }
    if (x >= 0 && x <= 99) {
      b[x] = 1;  // 입력된 원소를 집합 b에 추가
    } else {
      printf("유효하지 않은 원소입니다. 0부터 99까지의 정수를 입력하세요.\n");
    }
  }

  // 나머지 기능을 사용하거나 출력할 내용을 여기에 추가하세요.

  // 집합 연산 결과를 출력합니다.
  printf("집합 a의 원소 개수: %d\n", cardinality(a));
  printf("집합 b의 원소 개수: %d\n", cardinality(b));
  printf("집합 a가 공집합인가요? %s\n", isEmpty(a) ? "네" : "아니오");
  printf("집합 b가 공집합인가요? %s\n", isEmpty(b) ? "네" : "아니오");
  printf("집합 a와 집합 b가 서로소인가요? %s\n",
         isDisjoint(a, b) ? "네" : "아니오");
  printf("집합 a가 집합 b의 부분집합인가요? %s\n",
         isSubset(a, b) ? "네" : "아니오");
  printf("집합 b가 집합 a의 부분집합인가요? %s\n",
         isSubset(b, a) ? "네" : "아니오");
  printf("집합 a와 집합 b가 같은가요? %s\n", isEqual(a, b) ? "네" : "아니오");

  // 교집합 출력
  printf("집합 a와 집합 b의 교집합: { ");
  int *intersectionResult = intersection(a, b);
  for (int i = 0; i < 100; i++) {
    if (intersectionResult[i] == 1) {
      printf("%d ", i);
    }
  }
  printf("}\n");
  free(intersectionResult);

  // 합집합 출력
  printf("집합 a와 집합 b의 합집합: { ");
  int *unionResult = unionSet(a, b);
  for (int i = 0; i < 100; i++) {
    if (unionResult[i] == 1) {
      printf("%d ", i);
    }
  }
  printf("}\n");
  free(unionResult);

  // 차집합 출력
  printf("집합 a와 집합 b의 차집합: { ");
  int *differenceResult = difference(a, b);
  for (int i = 0; i < 100; i++) {
    if (differenceResult[i] == 1) {
      printf("%d ", i);
    }
  }
  printf("}\n");
  free(differenceResult);

  // 할당된 메모리 해제
  deleteSet(a);
  deleteSet(b);
  return 0;
}