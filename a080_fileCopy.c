#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main()
{
    char* buffer;
    size_t fsize;

    FILE* fp = fopen("test.txt", "rb");
    FILE* ofp = fopen("output.txt", "wb");

    fseek(fp, 0, SEEK_END);
    fsize = ftell(fp);
    rewind(fp);
    printf("size of test.txt is %d bytes \n", fsize);

    buffer = (char*)malloc(fsize);
    memset(buffer, 0, fsize);

    fread(buffer, fsize, 1, fp);    // fp 를 읽어 buffer에 쓴다. 
    fwrite(buffer, fsize, 1, ofp);  // buffer에서 ofp로 쓴다.

    fclose(fp); fclose(ofp); 
    free(buffer);
    printf("copied to output.txt! \n");
}
