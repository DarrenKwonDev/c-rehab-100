#include <stdio.h>

struct student {
    char dept[20];
    int year;
    int id;
    char name[20];
    char phone[20];
};

void printInfo(struct student *s)
{
    printf("\n학과 : %s\n", s->dept);
    printf("학년 : %d\n", s->year);
    printf("학번 : %d\n", s->id);
    printf("이름 : %s\n", s->name);
    printf("전화번호 : %s\n", s->phone);
}

int main()
{
    struct student s;

    printf("학과 :");
    scanf("%19s", s.dept);
    //getchar(); // clean \n in stdin buffer

    printf("학년 :");
    scanf("%d", &s.year);

    printf("학번 :");
    scanf("%d", &s.id);

    printf("이름 :");
    scanf("%s", s.name);

    printf("전화번호 :");
    scanf("%s", s.phone);

    // 여기서 전화번호 입력 후 stdin buffer에 \n가 남아 있음.

    printInfo(&s);
}
