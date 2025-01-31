#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000
#define CNT 1000

int search(int a[], int v);
void printArr(int a[], int n);
void find_min_max(int a[], int n);

int main()
{
    int a[CNT];
    int value, index;

    srand(time(0)); // rand seed
    
    for(int i = 0; i < CNT; i++)
        a[i] = rand() % MAX; // 0 ~ 9999
    
    printArr(a, CNT);
    find_min_max(a, CNT);

    printf("\n 찾고자 하는 값을 입력 :");
    scanf("%d", &value);

    if ( (index = search(a, value)) == -1 )
        printf("%d는 배열에 없습니다. \n", value);
    else
        printf("%d는 a[%d]에 있습니다. \n", value, index);
}

// 단순한 loop 찾기
int search(int a[], int v)
{
    for(int i = 0; i < CNT; i++)
        if (a[i] == v)
            return i;

    return -1;
}

void printArr(int a[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%c%6d", (i % 10 == 0) ? '\n' : ' ', a[i]);
}

void find_min_max(int a[], int n)
{
    int min = a[0];
    int max = a[0];
    for(int i = 1; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }
    printf("\n min = %d | max = %d \n", min, max);
}
