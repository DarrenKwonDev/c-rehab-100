#include <stdio.h>
#include <string.h>

size_t my_strlen(const char* s)
{
  size_t i =0;
  while(s[i] != '\0')
    i++;
  return i;
}

size_t my_strlen2(const char* s)
{
  const char* p = s;
  while(*p != '\0')
    p++;
  return p - s; // ptr offset
}

// 표준 strcmp와 같은 동작을 해야함
// ascii 기준 첫번째 문자열이 앞서면 "양수", 두번째 문자열이 앞서면 "음수"
// 짧은 문자열이 나오면 \0으로 간주하고 비교함.
// \0 이면 다른 문자와 비교시 항상 작음
// 즉, strcmp("abcd", "abc") 면 d > \0 이므로 "양수"을 반환함
// 양수, 음수라 쓴 이유는 항상 1, -1이 아님이란 의미. 2, 3, -5 를 반환할수도
// 있음
int my_strcmp(const char *s, const char *t)
{
  int i;
  for(i = 0; s[i] != '\0' && t[i] != '\0'; i++)
  {
    if (s[i] != t[i])
      break;
  }
  
  // 같지 않은 시점 혹은 \0를 만난 시점에 빠져나옴
  // \0의 ascii값은 0임. 비교가 가능함.

  if (s[i] > t[i])
    return 1; 
  else if (s[i] == t[i])
    return 0;   // 완전히 같음.
  else
    return -1;
}

int main()
{
  char s[] = "Hello World!";
  char t[] = "hello world!";

  printf("strlen : %u \n", strlen(s));
  printf("my_strlen : %u \n", my_strlen(s));
  printf("my_strlen2 : %u \n", my_strlen2(s));

  printf("strcmp : %d \n", strcmp(s, t));
  printf("strcmp2 : %d \n", my_strcmp(s, t));

}
