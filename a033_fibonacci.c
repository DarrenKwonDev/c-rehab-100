#include <stdio.h>
#include <time.h>


void printRes(int a[], int n, double t)
{
    for(int i = 1; i <= n; i++)
        printf("%d \t", a[i]);
    printf("\n 실행시간 = %lf \n", t);
}

int RecurFibo(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return RecurFibo(n - 1) + RecurFibo(n - 2);
}

int dp[100];
int DynaFibo(int n)
{
    if (n == 1 || n == 2)
        return 1;
    if (dp[n] != 0)
        return dp[n];
    else
        return dp[n] = DynaFibo(n - 1) + DynaFibo(n - 2);
}

int main()
{
    double start, end;
    int n;
    int f[100];

    printf("n 항 까지의 fibo 계산 :");
    scanf("%d", &n);


    //---------------------------------------
    start = clock() / CLOCKS_PER_SEC;

    f[1] = f[2] = 1;
    for(int i = 3; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];

    end = clock() / CLOCKS_PER_SEC;

    printRes(f, n, end - start);

    //----------------------------------------
    start = clock() / CLOCKS_PER_SEC;
    for(int i = 1; i <= n; i++)
        f[i] = RecurFibo(i);

    end = clock() / CLOCKS_PER_SEC;

    printRes(f, n, end - start);

    //----------------------------------------
    start = clock() / CLOCKS_PER_SEC;
    for(int i = 1; i <= n; i++)
        f[i] = DynaFibo(i);

    end = clock() / CLOCKS_PER_SEC;

    printRes(f, n, end - start);
}
