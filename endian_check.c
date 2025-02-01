#include <stdio.h>

int main()
{
  union {
    int   i;
    char  c[4];
  } u;

  u.i = 0x01234567;

  // 67 이 출력되면 뒷순서부터이므로 litten endian
  // 01 이 출력되면 앞순서부터이므로 big endian
  
  if (u.c[0] == 01)
    printf("big endian. \n");
  else
    printf("little endian. \n");
  
  printf("print 0x01234567 first byte ret : %x \n", u.c[0]);

  return 0;
}
