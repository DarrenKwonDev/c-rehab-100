#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRAIALS 1000000

int main() {
  int cnt[13] = {0}; // cnt array
  int rand_min = 1;
  int rand_max = 6;
  int dice;   // sum of dice

  srand(time(0));

  int v = rand_max - rand_min + 1; // 범위의 크기
  for(int i = 0; i < TRAIALS; i++) {
    // rand() 를 RAND_MAX + 1 로 나누어 0~1 사이의 실수로 만듦
    // 범위의 크기 (6-1+1) 을 곱하고 최솟값(1)을 더해서 1 ~ 6 사이의 값 생성
    dice = (int)(rand() / ((double)RAND_MAX + 1) * v + rand_min);
    dice += (int)(rand() / ((double)RAND_MAX + 1) * v + rand_min);
    cnt[dice]++;
  }

  int total = 0;
  for(int i = 2; i <= 12; i++) {
    printf("cnt[%2d] = %8d, %5.2f%%\n", i, cnt[i], (double)cnt[i]/TRAIALS * 100);
    total += cnt[i];
  }

  printf("TRAIALS = %d \n", total);
}
