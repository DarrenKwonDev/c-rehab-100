#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define SIZE    (32)

int checkOverflow(char buffer[]) {
  char intmax[11];
  snprintf(intmax, sizeof(intmax), "%d", INT_MAX); // char로 저장. 2147483647

  if(strlen(buffer) > strlen(intmax))
    return 1; // overflow 됨
  else if(strlen(buffer) == strlen(intmax)) 
  {
    for(int i = 0; i < 11; i++)
      if(buffer[i] > intmax[i])
        return 1; // overflow됨
  }

  return 0; 
}

void array_d2b(int n)
{
  int arr[SIZE] = {0};
  int i, length = 0; // 배열의 길이

  for(i = 0; n > 0; i++)
  {
    arr[i] = n % 2;
    n /= 2;
    length++;
  }
  length--;

  // 역순으로 출력함.
  while(length >= 0)
  {
    printf("%d", arr[length]);
    length--;
  }
}

// 역순으로 출력하지 않아도 재귀를 통해서 callstack이 풀려나며 출력되도록.
// 이 방버이 더 우아함.
void recursive_d2b(int n)
{
  if (n >= 2)
    recursive_d2b(n / 2);
  printf("%d", n % 2);
}

int main()
{
  int n;
  char number[11] = {0};

  printf("10진수 정수를 입력하세요:");
  scanf("%s", number);

  if (checkOverflow(number) == 1)
  {
    printf("입력한 정수가 숫자의 범위를 넘어갑니다. \n");
    exit(0);
  }

  n = atoi(number);

  printf("\n10진수 %d의 2진수 :", n);
  array_d2b(n);

  printf("\n10진수 %d의 2진수 :", n);
  recursive_d2b(n);
}
