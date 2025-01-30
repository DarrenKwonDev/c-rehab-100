#include <stdio.h>

#define INT     0
#define FLOAT   1

void sum_of_array(void* p, int length, void* result, int type)
{
  switch(type)
  {
    case INT:
      for(int i = 0; i < length; i++)
        *(int*)result += *((int*)p + i);
      break;

    case FLOAT:
      for(int i = 0; i < length; i++)
        *(float*)result += *((float*)p + i);
      break;
  }
}

int main()
{
  int a[5] = { 1, 2, 3, 4, 5};
  float b[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

  int iSum = 0;
  float fSum = 0;

  sum_of_array(a, 5, &iSum, INT);
  printf("iSum : %d \n", iSum);

  sum_of_array(b, 5, &fSum, FLOAT);
  printf("fSum : %f \n", fSum);
}
