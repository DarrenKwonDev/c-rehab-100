#include <stdio.h>

int main()
{
  int i, a, b, c;
  int day, month, year;
  char s[100];

  setbuf(stdin, NULL); setbuf(stdout, NULL);

  int x = scanf("%d %c %d", &a, &i, &b);  // 공백 주의. 12 + 34 꼴로 입력해야 함
  printf("scanf의 리턴값 = %d \n", x);
  printf("(1) %d %c %d\n", a, i, b);
  c = getchar(); // stdin buffer에서서 \n을 제거하기 위함.

  scanf("%[0-9]", s); // 입력된 string 중 처음 발견된 [0-9]만을 읽겠다.
  printf("(2) %s\n", s);

  // 이 시점에 stdin buffer에 \n가 남아 있음.

  // scanf를 호출하더라도 stdin buffer가 남아 있어 사용자 입력 대기 하지 않음. 
  // 이 시점에 남은 stdin buffer를 읽어옴.
  scanf("%[^\n]%*c", s); // \n 앞 까지 읽겠다
  printf("(3) %s\n", s);

  // 이 시점에서 stdin buffer가 존재하지 않을 것으로 기대됨.
  // %*c를 통해 \n 읽고 버렸기 때문임

  scanf("%*d%s", &s); // %d를 읽지만 무시하겠다(%*d)
  printf("(4) %s \n", s);

  // 여기에서도 stdin buffer에 \n이 남아 있음.
  // 그러나 %d는 숫자 앞에 입력된 공백문자(스페이스, 탭, \n 등)을 무시하므로
  // 문제가 생기진 않음.

  scanf("%d%*c%d%*c%d", &day, &month, &year); // 30/08/2022 와 같은 형식을 입력 받길 기대함
  printf("(5) %d %d %d \n", year, month, day);

  // 여기서도 마찬가지로 %d 꼴로 데이터를 읽어오므로 stdin buffer에 남은 \n는
  // consume됨.

  scanf("%5d%[^\n]", &i, s);
  printf("(7) %d \n", i);

  scanf("%5d%2d", &a, &b);
  printf("(8) %d %d \n", a, b);

}
