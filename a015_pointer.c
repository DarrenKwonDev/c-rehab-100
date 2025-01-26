#include <stdio.h>

int main()
{
  int x = 10, y = 20;
  int z[3] = {1, 2, 3};
  int* p;

  p = &x;       // p is pointer of x
  printf("p is %p\n", p);

  y = *p;       // y = x
  printf("p is %p\n", p);

  *p = *p + y;  // x turn to x + y
  printf("x is %d\n", x);

  p = &z[0];    // p is pointer of z[0];
  printf("p is %p\n", p);
  *p = 30;      // z[0] turn to 30;

  printf("z[0] is %d \n", z[0]);

  printf("[%p]: %d \n", p, *p);
  printf("[%p]: %d \n", p, *p + 1);
  printf("[%p]: %d \n", p + 1, *(p + 1));

  int a[3] = {10, 20, 30};
  int* q = a; // q is pointer of a[0] 
  printf("\n[%p] : %d\n", q, *q);
  q = q + 1; // q to next elem
  printf("\n[%p] : %d\n", q, *q);

  int* ip;
  char* cp;
  double* dp;

  printf("sizeof(int*)=%d | sizeof(char*)=%d | sizeof(double*)=%d\n",
      sizeof(ip), sizeof(cp), sizeof(dp));
}
