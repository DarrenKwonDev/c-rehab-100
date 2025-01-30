#include <stdio.h>
#include <math.h>

long long decimal_to_binary(int dec)
{
  long long bin = 0;
  int mask = 0x01; // 상위 비트는 0으로 자동 채워짐. 0x00000001 과 같음.
  int bit;

  for(int i = 0; i < 16; i++)
  {
    bit = dec & mask;
    bin += bit * pow(10, i);
    dec = dec >> 1; //
  }

  return bin;
}

int main()
{
  long long bin;
  int dec;

  printf("Enter decimal number:");
  scanf("%d", &dec);

  bin = decimal_to_binary(dec);
  printf("%d is %lld \n", dec, bin);
}
