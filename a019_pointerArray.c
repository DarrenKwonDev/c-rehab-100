#include <stdio.h>


/*
 *  변수명    |   x     | ptr   | pptr  | ppptr
 *  값(가변)  |   10    | 0x100 | 0x200 | 0x300
 *  주소(불변)|   0x100 | 0x200 | 0x300 | 0x400
 */

int main()
{
  int x = 10;
  int *ptr = &x;
  int **pptr = &ptr;
  int ***ppptr = &pptr;

  printf("%d %d %d %d \n", x, *ptr, **pptr, ***ppptr);

  char s[] = "abcd";
  char *t =  "abcd";
  printf("[%p] = %s, [%p] = %s \n", s, s, t, t);

  char *p[] = {"tiger", "zebra"};
  for(int i = 0; i < 2; i++)
    printf("%s \n", p[i]);
}
