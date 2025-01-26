#include <stdio.h>

int main()
{
  // 문자열 리터럴이 아닌 일반 char[] 은 \0를 수동으로 넣어주는게 안전
  char s[10] = {'a', 'b', 'c', 'd', 'e'};     // 배열 크기 명시가 있다면 뒷부분 모두 \0 초기화
  char t[] = {'a', 'b', 'c', 'd', 'e', '\0'}; // 크기 명시가 없으므로 \0을 반드시 적어둬야 함.

  // 문자열 리터럴 ("") 을 보면 컴파일러가 알아서 \0를 넣음
  char u[] = "abcde";                         // 자동으로 \0가 붙음
  char v[] = "안녕하세요";                    // 자동으로 \0가 붙음. 한글이라 1바이트 보다 큼.

  printf("s = |%s| size = %d\n", s, sizeof(s));
  printf("t = |%s| size = %d\n", t, sizeof(t)); // 5 문자 + 1 null char
  printf("u = |%s| size = %d\n", u, sizeof(u)); // 5 문자 + 1 null char
  printf("v = |%s| size = %d\n", v, sizeof(v)); // 5 한글 + 1 nullchar (3 * 5 + 1);
}
