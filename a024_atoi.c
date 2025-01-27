#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int my_atoi(const char *s)
{
  int value = 0;

  while(*s) {
    if (*s >= '0' && *s <= '9')
    {
      value = value * 10 + (*s - '0'); // 자리수 이동 + 숫자 변환
      s++;
    }
    else
    {
        printf("non-number found. \n");
        return -1;
    }
  }
  return value;
}

char* my_itoa(int v)
{
  int digits = 0; // 자릿수
  int t = v;

  while(t)
  {
    digits++;
    t /= 10;
  }

  char* number = (char*)malloc(digits + 1);
  number[digits] = '\0';

  while(digits != 0)
  {
    number[--digits] = v % 10 + '0';
    v /= 10;
  }
  return number;
}


int main()
{
  char buffer[30];

  printf("atoi() : %d \n", atoi("1234567"));
  printf("my_atoi : %d \n", my_atoi("1234567"));

  printf("itoa : %s \n", my_itoa(12345));
}
