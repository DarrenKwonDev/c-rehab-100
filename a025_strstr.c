#include <stdio.h>
#include <string.h>

char str[] = "ababacabcaab";
char sub[] = "abc";

char* my_strstr(const char *str, const char *sub)
{
  int len1 = strlen(str);
  int len2 = strlen(sub);

  if (len2 == 0)  // sub가 "" 라면 그냥 str ptr를 반환함
    return (char*)str;

  while(len1 >= len2)
  {
    char* s = (char*)str;
    char* t = (char*)sub;
    while(*s == *t && *t != NULL)
    {
      s++;
      t++;
    }
    if (*t == NULL)
      return (char*)str;

    // 매칭이 되지 않았다면 str ptr를 전진시킨다
    str++;
    len1--;
  }
  return NULL;
}

int main()
{
  printf("strstr() : %s \n", strstr(str, sub));
  printf("my_strstr() : %s \n", my_strstr(str, sub));
}
