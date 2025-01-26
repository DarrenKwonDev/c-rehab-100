#include <stdio.h>

int add3(int *p)
{
  int sum = 0;

  for(int i = 0; i < 3; i++)
    sum += *(p + 1);

  return sum;
}

int main()
{
  int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int *p;

  p = a;

  printf("%p %p %p \n", p, a, &a[0]);
  
  for(int i = 0; i < 10; i++)
  {
    *(p + i) = *(p + i) * 10;
  }

  printf("%d %d %d \n", a[2], *(p + 2), *(a + 2));

  printf("Add 3 elem : %d \n", add3(a));

  p++;

  printf("Add 3 elem : %d \n", add3(p)); // a[1] 부터 3개 더함
}
