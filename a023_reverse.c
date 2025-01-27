#include <stdio.h>
#include <string.h>

char* my_reverse(char* s)
{
  char* end = s + strlen(s) - 1; // "abc" 면 마지막 c를 가리킴.

  // ptr < end 일 때 까지만. 같게 되면 reverse 하지 않음
  for(char* ptr = s; ptr < end; ptr++, end--)
  {
    char tmp = *ptr;
    *ptr = *end;
    *end = tmp;
  }
  return s;
}

int main()
{
  char t[] = "abcd";
  
  printf("my_reverse : %s \n", my_reverse(t));
}
