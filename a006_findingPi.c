#include <stdio.h>
#include <stdbool.h>

int main()
{
  bool sign = false;
  double pi = 0;

  /*
   * pi = 4(1/1 - 1/3 + 1/5 - 1/7 + 1/9 ...)
   */

  for(int i = 1; i <= 1000000000; i +=2)
  {
    if (sign == false) 
    {
      pi += 1.0 / i;
      sign = true;
    }
    else
    {
      pi -= 1.0 / i;
      sign = false;
    }

    if (i < 20 || i > 999999990)
      printf("i = %10d, pi = %.18f\n", i, 4 * pi);
  }
}
