#include <stdio.h>
#include <string.h>

int main()
{
  // 이중 arr에서 뒷 편은 배열 크기가 필수임.
  // array of char[20];
  char name1[][20] = {"kang", "cho", "kim"}; // 문자열 리터럴이므로 컴파일러가 \0를 알아서 넣어
  char name2[][20] = {
    {'k', 'a', 'n', 'g'}, // 배열 크기가 20으로 주어졌으므로 나머지는 \0로 초기화 됨.
    {'c', 'h', 'o'},
    {'k', 'i', 'm'}
  };

  for(int i = 0; i < 3; i++)
  {
    printf("%-28s", name1[i]);
  }
  printf("\n");

  for(int i = 0; i < 3; i++)
  {
    printf("%-28s", name2[i]);
  }
  printf("\n");

  strcpy(name1[0], "스티브 잡스");
  strcpy(name1[1], "빌 게이츠");
  strcpy(name1[2], "데니스 리치");

  for(int i = 0; i < 3; i++)
  {
    printf("%-28s", name1[i]);
  }
  printf("\n");

}
