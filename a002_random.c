#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int a[10];
  int dice[30];
  int rand_min = 1;
  int rand_max = 6;

  // start rand (srand)
  srand(time(0)); // 현재 시간으로 랜덤 시드 결정

  printf("RAND_MAX = %x, %d \n", RAND_MAX, RAND_MAX);
  printf("\n");

  for(int i = 0; i < 30; i++) {
    // 1과 6 사이의 랜덤 넘버를 지정합니다.
    // rand()를 RAND_MAX로 나누어 0~1 사이의 실수를 만듦
    // 이를 범위 크기(6-1+1 = 6)와 곱하고 최소값(1)을 더해서 1~6 사이의 값을 생성
    // 더 정확한 분포의 난수를 생성할 수 있음
    dice[i] = (int)(rand() / ((double)RAND_MAX + 1) * (rand_max - rand_min + 1) + rand_min);

    // 아래 방법이 좀 더 간단하지만 분포가 균등하지 않음
    // dice[i] = rand() % rand_max + rand_min;
  }

  for(int i = 0; i < 30; i++) {
    printf("%6d%c", dice[i], (i + 1) % 10 != 0 ? ' ' : '\n');
  }
  
}
