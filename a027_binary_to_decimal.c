#include <stdio.h>
#include <math.h>

// 이진수가 n에 1000110 과 같은 패턴으로 들어온다고 가정.
int binary_to_decimal(long long n)
{
  int dec = 0;
  int rem;  // 나머지

  for(int i = 0; i < 32; i++)
  {
    rem = n % 10;           // 10으로 나눈 나머지 (일의 자리부터 가져옴)
    dec += rem * pow(2, i); // 2^i 을 곱하여 십진수로 변환함.
    n /= 10;                // 다음 계산을 위해 n /= 10;
  }

  return dec;
}

int main()
{
  long long bin;
  int dec;

  printf("Enter binary number:");
  scanf("%lld", &bin);

  dec = binary_to_decimal(bin);
  printf("%lld is %d", bin, dec);
}
