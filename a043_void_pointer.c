#include <stdio.h>

#define INT     0
#define FLOAT   1
#define DOUBLE  2

void* add(void* a, void* b, void* result, int type)
{
  switch (type)
  {
    case INT:
      *(int*)result = *(int*)a + *(int*)b;
      break;
    case FLOAT:
      *(float*)result = *(float*)a + *(float*)b;
      break;
    case DOUBLE:
      *(double*)result = *(double*)a + *(double*)b;
      break;
  }
}

int main()
{
  int x = 10, y = 20, intres;
  float f1 = 1.3, f2 = 2.4, floatres;
  double d1 = 2.5, d2 = 3.3, doubleres;

  printf("%d \n", *(int*)add(&x, &y, &intres, INT));
  printf("%f \n", *(float*)add(&f1, &f2, &floatres, FLOAT));
  printf("%lf \n", *(double*)add(&d1, &d2, &doubleres, DOUBLE));
}
