#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000
#define CNT 1000

int binarySearch(int a[], int n, int v);
void swap(int v[], int i, int j);
void sort(int v[], int left, int right);
void printArr(int a[], int n);

int main()
{
    int a[CNT];
    int value, index;

    srand(time(0)); // rand seed
    
    for(int i = 0; i < CNT; i++)
        a[i] = rand() % MAX; // 0 ~ 9999
    
    sort(a, 0, CNT);
    printArr(a, CNT);

    printf("\n 찾고자 하는 값을 입력 :");
    scanf("%d", &value);

    if ( (index = binarySearch(a, CNT, value)) == -1 )
        printf("%d는 배열에 없습니다. \n", value);
    else
        printf("%d는 a[%d]에 있습니다. \n", value, index);
}

void sort(int v[], int left, int right)
{
    for(int i = left; i < right; i++)
        for(int j = 0; j < right - 1; j++)
            if(v[j] > v[j + 1])
                swap(v, j, j + 1);
}

void swap(int v[], int i, int j)
{
    int tmp;

    tmp = v[i];
    v[i] = v[j]; v[j] = tmp;
}

int binarySearch(int a[], int n, int v)
{
    int low = 0;
    int high = n - 1;
    int mid;

    while( low <= high )
    {
        mid = (low + high) / 2;
        if (a[mid] == v)
            return mid;
        else if (v > a[mid]) // 찾는 값이 더 크면 low를 오른쪽으로 옮긴다.
            low = mid + 1;
        else                // 찾는 값이 더 작으면 high를 왼쪽으로 옮긴다.
            high = mid - 1;
    }
    return -1;
}

void printArr(int a[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%c%6d", (i % 10 == 0) ? '\n' : ' ', a[i]);
}

