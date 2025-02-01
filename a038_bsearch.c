#include <stdio.h>
#include <stdlib.h>

int should_be_ascending_order_compare(const void* a, const void* b)
{
    // a가 앞 b 가 뒤.
    // a > b 라면 앞의 것을 뒤로 보내라.
    // 결국 오름차순 정렬이 됨.
    return *(int*)a - *(int*)b;
}

int main()
{
    int a[] = {10, 20, 30, 50, 70, 100, 25, 11, 66, 439};

    int* ptr;   // bsearch의 반환
    int key;

    printf("찾고자 하는 값을 입력하세요 :");
    scanf("%d", &key);

    // int[10] 짜리 a 에서 key를 찾습니다.
    // 그런데 binary search를 하려면 무조건 오름차순 정렬이 요구됨.
    // 그렇지 않으면 bsearch 가 올바르게 동작하지 않음.
    ptr = (int*)bsearch(&key, a, 10, sizeof(int), should_be_ascending_order_compare);

    if (ptr != NULL)
        printf("%d is a[%d] \n", *ptr, ptr - a);
    else
        printf("%d is not in a \n", key);
}
