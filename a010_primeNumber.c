#include <stdio.h>

int main()
{
  int index;
  int primes = 0;

  for(int i = 2; i < 1000; i++)
  {
    for(index = 2; index < i; index++)
    {
      if (i % index == 0)
        break;
    }

    // break에 걸리지 않고 끝가지 for문을 돌았다는 의미임.
    // 즉, i는 소수임.
    if (index == i)
    {
      primes++;
      printf("%-4d%c", i, primes % 15 == 0 ? '\n' : ' ');
    }
  }
  printf("\n2 이상 1000 미만 사이의 소수 %d 개 \n", primes);
}
