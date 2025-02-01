#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student 
{
    int id;
    char name[20];
    int score;
};

int compare1(const void* p, const void* q)
{
    int a = ((struct student*)p)->id; // 앞에 있는 것
    int b = ((struct student*)q)->id; // 뒤에 있는 것

    // 비교 함수는 "현재 순서가 맞나요?"라고 물어보는 것이고, 
    // 음수나 0이 나오면 "네", 양수가 나오면 "아니오"
    // a - b > 0 이라면 순서를 swap 하라는 의미.
    //
    // 여기서는 앞에 있는 id가 뒤에 있는 id 보다 크다면 바꾸라는 의미
    // 결과적으로 오름차순(작은 것이 앞에)으로 감
    return a - b; 
}

int compare2(const void* p, const void* q)
{

    int a = ((struct student*)p)->score; // 앞에 있는 것
    int b = ((struct student*)q)->score; // 뒤에 있는 것

    // b > a 이면 swap 하라.
    // 뒤의 score가 더 크면 앞으로 보내라.
    // 결국 score 내림차순
    return b - a;
}

int compare3(const void* p, const void* q)
{
    char *a = ((struct student*)p)->name;
    char *b = ((struct student*)q)->name;

    // strcmp > 0 이면 a가 b 보다 사전순으로 더 뒤에 있음.
    // 사전순으로 뒤에 있으면 앞의 것(a) 를 뒤로 보내라는 것
    // 결국 사전 순으로 빠른 차순으로 정렬.
    return strcmp(a, b);
}

void printArr(struct student a[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%5d %20s, %4d \n", a[i].id, a[i].name, a[i].score);
    printf("\n");
}

int main()
{
    struct student a[] = {
        {1001, "steve", 88},
        {1003, "tom", 98},
        {1002, "jane", 76},
    };

    qsort(a, 3, sizeof(struct student), compare1);
    printArr(a, 3);
    
    qsort(a, 3, sizeof(struct student), compare2);
    printArr(a, 3);
    
    qsort(a, 3, sizeof(struct student), compare3);
    printArr(a, 3);
}
