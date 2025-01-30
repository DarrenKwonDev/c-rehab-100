#include <stdio.h>
#include <time.h>

int main()
{
    double start, end;

    start = (double)clock() / CLOCKS_PER_SEC;

    int sum = 0;
    for(int i = 0; i < 1000000000; i++)
    {
        sum++;
    }

    end = (double)clock() / CLOCKS_PER_SEC;

    printf("exec time : %lf secs \n", end - start);
}
