#include <stdio.h>

// call by value
void swap(int x, int y)
{
  int tmp;
  tmp = x;
  x = y;
  y = tmp;
}

// call by reference (indeed, it is also call by value)
void swap2(int* px, int* py)
{
  int tmp;
  tmp = *px;
  *px = *py; // px는 x를 가리키고는 있지만 값은 *py로 변경
  *py = tmp; // py는 y를 가리키고는 있지만 값은 tmp로 변경
}

int main()
{
  int x = 3;
  int y = 4;

  swap(x, y);
  
  swap2(&x, &y);
  printf("x = %d | y = %d \n", x, y);
}
