#include <stdio.h>
#include <string.h>
#include <malloc.h>

char* my_strcpy(char *dest, char *source)
{
  dest = (char*)malloc(strlen(source) + 1); // should free
  int i = 0;
  while(dest[i] = source[i]) // 할당된 값을 반환함. \0이 할당되면 while 문을 빠져나옴.
    i++;
  dest[i] = '\0';
  return dest; // free 하기 위해서 ptr를 반환해야 함
}

char* my_strcat(char *str1, char *str2)
{
  char *result = (char*)malloc(strlen(str1) + strlen(str2) + 1);
  int i = 0;

  while(str1[i] != '\0')
  {
    result[i] = str1[i];
    i++;
  }

  // result 시작에서부터 str1의 문자 크기 이상을 가리키는 지점
  // ptr에 쓰고 result를 반환해도 정상적으로 합쳐진 문자열이 반환됨.
  // 그런데 이건 안티 패턴임!
  // 이런 식으로 작성하지 말아라.

  char* ptr = result + strlen(str1); // str1 다음 만큼 ptr offset 이동
  while(*str2 != '\0') // 밑의 *str2++ 에 의해 다음 포인터에 의해 이동되었으므로 문자 검사임.
    *ptr++ = *str2++; // *ptr = *str2 를 수행한 후 각각 ptr offset ++ 이동
  *ptr = '\0'; // str2의 \0를 만났으므로 *ptr에 \0를 부여함.

  return result;
}


int main()
{
  char s[] = "Hello World!";
  char u[] = "C programming language!";

  char *t = NULL;
  char *v = NULL;

  t = my_strcpy(t, s);
  v = my_strcat(s, u);

  printf("my_strcpy() : %s -> %s \n", s, t);
  printf("my_strcat() : %s \n", v);

  free(t);
  free(v);
}
