#include <stdio.h>
#include <stdbool.h>

#define N     (1000)

int main()
{
  bool a[N + 1]; // bool array 
  int primes = 0;

  // 정의상 소수는 2이상이어야 하므로
  a[0] = a[1] = false;

  // 모두 true로 세팅
  for(int i = 2; i <= N; i++)
    a[i] = true;
 
  // 2부터 N/2 까지만 반복하면 된다.
  for(int i = 2; i <= N / 2; i++)
    for(int j = 2; j <= N / i; j++) // i * j 가 N을 넘으면 안되므로 j <= N / i 까지만.
      a[i * j] = false;

  for(int i = 1; i <= N; i++)
    if (a[i] == true)
    {
      primes++;
      printf("%4d%c", i, primes % 15 == 0 ? '\n' : ' ');
    }

  printf("\n 2 이상 1000 미 사이의 소수 : %d  \n", primes);

  return 0;
}
