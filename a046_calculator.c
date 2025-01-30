#include <stdio.h>

float add(float a, float b)
{ return a + b;}

float substract(float a, float b)
{  return a - b;}

float multiply(float a, float b)
{  return a * b;}

float divide(float a, float b)
{  return a / b;}

int main()
{
  float a, b;
  int choice;

  float (*funcptr[4])(float, float) = { add, substract, multiply, divide };

  printf("Enter two number :");
  scanf("%f %f%*c", &a, &b);
  printf("Enter choice [0:add 1:sub 2:mul 3:div] :");
  scanf("%d", &choice);

  printf("res : %f \n", funcptr[choice](a, b));
}
