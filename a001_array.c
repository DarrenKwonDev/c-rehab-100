#include <stdio.h>

int main(int argc, char* argv[]) {
  int a[10];
  int min, max;
  int sum = 0;

  for(int i = 0; i < 10; i++) {
    printf("%d번째 숫자를 입력하세요: ", i + 1);
    scanf("%d", &a[i]);
  }

  for(int i = 0; i < 10; i++) {
    printf("%6d", a[i]);
  }
  printf("\n");

  min = max = a[0];
  for(int i = 1; i < 10; i++) {
    sum += a[i];
    if (a[i] < min)
      min = a[i];
    else if (a[i] > max)
      max = a[i];
  }

  printf("min = %d | max = %d | average = %.2f", min, max, sum/10.0);
}
