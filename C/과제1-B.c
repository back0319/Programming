#include <stdio.h>
#include <stdlib.h>

// 집합을 나타내는 구조체
typedef struct {
  int size; /* 설정된 원소 저장 공간에 저장 가능한 최대 원소 수 */
  int nelems;   /* 현재 저장되어 있는 원소 수 */
  int *element; /* 원소 저장 공간의 시작 주소 */
} set_t;

// 집합을 생성하고 초기화하는 함수
set_t *createSet() {
  set_t *newSet = (set_t *)malloc(sizeof(set_t));  // set_t 구조체 메모리 할당
  if (newSet == NULL) {
    return NULL;  // 메모리 할당 실패 시 NULL 반환
  }
  newSet->size = 5;    // 최대 원소 수를 5로 초기화
  newSet->nelems = 0;  // 현재 원소 수를 0으로 초기화
  newSet->element =
      (int *)malloc(newSet->size * sizeof(int));  // 원소 저장 공간 메모리 할당
  if (newSet->element == NULL) {
    free(newSet);
    return NULL;  // 원소 저장 공간 메모리 할당 실패 시 NULL 반환
  }
  // 원소 저장 공간을 0으로 초기화
  for (int i = 0; i < newSet->size; i++) {
    newSet->element[i] = 0;
  }
  return newSet;
}

// 집합을 제거하는 함수
void deleteSet(set_t *s) {
  if (s != NULL) {
    free(s->element);  // 원소 저장 공간 메모리 해제
    free(s);           // 구조체 메모리 해제
  }
}

// 집합이 공집합인지 확인하는 함수
int isEmpty(set_t *s) { return (s->nelems == 0); }

// 집합의 기수(원소의 개수)를 반환하는 함수
int cardinality(set_t *s) { return s->nelems; }

// 원소 x가 집합 s에 속하는지 확인하는 함수
int isElement(int x, set_t *s) {
  for (int i = 0; i < s->size; i++) {
    if (s->element[i] == x) {
      return 1;  // 원소가 존재함
    }
  }
  return 0;  // 원소가 존재하지 않음
}

// 원소 x를 집합 s에 추가하는 함수
int addElement(int x, set_t *s) {
  if (s->nelems >= s->size) {
    // 저장 공간이 부족하면 확장
    int *newElement = (int *)realloc(s->element, 2 * s->size * sizeof(int));
    if (newElement == NULL) {
      return 0;  // 저장 공간 확장 실패
    }
    s->element = newElement;
    s->size *= 2;
  }

  // 원소를 추가하고 기수 증가
  s->element[s->nelems] = x;
  s->nelems++;
  return 1;  // 원소 추가 성공
}

// 원소 x를 집합 s에서 제거하는 함수
int removeElement(int x, set_t *s) {
  for (int i = 0; i < s->nelems; i++) {
    if (s->element[i] == x) {
      // 원소를 찾으면 해당 위치를 제거하고 기수 감소
      for (int j = i; j < s->nelems - 1; j++) {
        s->element[j] = s->element[j + 1];
      }
      s->nelems--;
      return 1;  // 원소 제거 성공
    }
  }
  return 0;  // 원소가 존재하지 않음
}

// 집합 a가 집합 b의 부분집합인지 확인하는 함수
int isSubset(set_t *a, set_t *b) {
  for (int i = 0; i < a->nelems; i++) {
    if (!isElement(a->element[i], b)) {
      return 0;  // a의 원소 중 b에 없는 것이 있음
    }
  }
  return 1;  // 모든 a의 원소가 b에 포함됨
}

// 두 집합 a와 b가 같은지 확인하는 함수
int isEqual(set_t *a, set_t *b) {
  if (a->nelems != b->nelems) {
    return 0;  // 원소 수가 다르면 다름
  }
  for (int i = 0; i < a->nelems; i++) {
    if (!isElement(a->element[i], b)) {
      return 0;  // a의 원소 중 b에 없는 것이 있음
    }
  }
  return 1;  // 모든 a의 원소가 b에 포함되고 원소 수도 같음
}

// 집합 a와 집합 b가 서로소(교집합이 공집합)인지 확인하는 함수
int isDisjoint(set_t *a, set_t *b) {
  if (a->nelems == 0 && b->nelems == 0) {
    return 1;  // 두 집합이 모두 공집합이면 서로소임
  }
  for (int i = 0; i < a->nelems; i++) {
    if (isElement(a->element[i], b)) {
      return 0;  // 교집합이 비어있지 않음
    }
  }
  return 1;  // 교집합이 공집합임
}

// 집합 a와 집합 b의 교집합을 생성해 리턴하는 함수
set_t *intersection(set_t *a, set_t *b) {
  set_t *result = createSet();  // 교집합 결과 집합 생성
  if (result == NULL) {
    return NULL;  // 메모리 할당 실패
  }
  for (int i = 0; i < a->nelems; i++) {
    if (isElement(a->element[i], b)) {
      addElement(a->element[i],
                 result);  // a의 원소가 b에도 있으면 교집합에 추가
    }
  }
  return result;
}

// 집합 a와 집합 b의 합집합을 생성해 리턴하는 함수
set_t *unionSet(set_t *a, set_t *b) {
  set_t *result = createSet();  // 합집합 결과 집합 생성
  if (result == NULL) {
    return NULL;  // 메모리 할당 실패
  }
  // a의 원소들을 결과 집합에 추가
  for (int i = 0; i < a->nelems; i++) {
    addElement(a->element[i], result);
  }
  // b의 원소들 중 결과 집합에 없는 것만 추가
  for (int i = 0; i < b->nelems; i++) {
    if (!isElement(b->element[i], result)) {
      addElement(b->element[i], result);
    }
  }
  return result;
}

// 집합 a와 집합 b의 차집합(집합 a - 집합 b)을 생성해 리턴하는 함수
set_t *difference(set_t *a, set_t *b) {
  set_t *result = createSet();  // 차집합 결과 집합 생성
  if (result == NULL) {
    return NULL;  // 메모리 할당 실패
  }
  for (int i = 0; i < a->nelems; i++) {
    if (!isElement(a->element[i], b)) {
      addElement(a->element[i],
                 result);  // a의 원소가 b에 없으면 결과 집합에 추가
    }
  }
  return result;
}

int main() {
  set_t *a = createSet();
  set_t *b = createSet();

  printf("집합 a를 입력하세요 (-1 입력시 종료): ");
  int x;
  while (1) {
    scanf("%d", &x);
    if (x == -1) {
      break;  // 입력 종료
    }
    addElement(x, a);
  }

  printf("집합 b를 입력하세요 (-1 입력시 종료): ");
  while (1) {
    scanf("%d", &x);
    if (x == -1) {
      break;  // 입력 종료
    }
    addElement(x, b);
  }

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
  set_t *intersectionResult = intersection(a, b);
  for (int i = 0; i < intersectionResult->nelems; i++) {
    printf("%d ", intersectionResult->element[i]);
  }
  printf("}\n");

  // 합집합 출력
  printf("집합 a와 집합 b의 합집합: { ");
  set_t *unionResult = unionSet(a, b);
  for (int i = 0; i < unionResult->nelems; i++) {
    printf("%d ", unionResult->element[i]);
  }
  printf("}\n");

  // 차집합 출력
  printf("집합 a와 집합 b의 차집합: { ");
  set_t *differenceResult = difference(a, b);
  for (int i = 0; i < differenceResult->nelems; i++) {
    printf("%d ", differenceResult->element[i]);
  }
  printf("}\n");

  // 할당된 메모리 해제
  deleteSet(a);
  deleteSet(b);
  deleteSet(intersectionResult);
  deleteSet(unionResult);
  deleteSet(differenceResult);

  return 0;
}