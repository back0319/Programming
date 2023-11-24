#include <stdio.h>
struct calculate {
  int add;
  int sub;
  int mul;
  float div;
};
typedef struct calculate cal;
void calc(int a, int b, cal *p) {
  p->add = a + b;
  p->sub = a - b;
  p->mul = a * b;
  p->div = (float)a / b;
}
int main() {
  cal c;
  calc(125, 41, &c);
  printf("덧셈 : %d\n", c.add);
  printf("뺄셈 : %d\n", c.sub);
  printf("곱셈 : %d\n", c.mul);
  printf("나눗셈 : %f\n", c.div);
}