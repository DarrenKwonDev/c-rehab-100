#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CNT   (10)

int main()
{
  int check[CNT + 1] = {0}; // already exists 
  int rand_order[CNT] = {0};

  int rand_max = 10;
  int rand_min = 1;

  srand(time(0));

  for(int i = 0; i < CNT; i++)
  {
    int x;
    do 
    {
      // 0 ~ 1 -> 0 ~ 10 -> 1 ~ 11
      x = (int)(rand() / ((double)RAND_MAX + 1) * (rand_max - rand_min + 1) + rand_min);
    } while(check[x] == 1);

    check[x] = 1;
    rand_order[i] = x;
  }

  for(int i = 0; i < CNT; i++)
  {
    printf("%3d", rand_order[i]);
  }
  printf("\n");
}
