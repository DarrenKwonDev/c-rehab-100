#include <stdio.h>

int main()
{
    int fsize = 0;
    FILE* fp = fopen("test.txt", "r");

    fseek(fp, 0, SEEK_END);
    fsize = ftell(fp);
    printf("filesize of \"test.txt\" = %d bytes \n", fsize);

    fseek(fp, 0, SEEK_SET);
    printf("fp = %d\n", ftell(fp));

    fseek(fp, -10, SEEK_CUR); // 앞으로 10 이동
    printf("fp = %d\n", ftell(fp)); // 이미 커서가 0이므로 앞으로 이동할 수 없어 0 반환

    fseek(fp, 10, SEEK_END); // 마지막에서 뒤로 10이
    printf("fp = %d\n", ftell(fp)); // 이 경우 파일보다 큰 값을 출력한다! 주의해야.

    fclose(fp);
}
