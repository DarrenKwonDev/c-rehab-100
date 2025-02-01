#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fileCopy(FILE*, FILE*);


int main()
{
    FILE *ifp, *ofp;
    char sname[20], tname[20];
    
    printf("Enter source file name :");
    scanf("%s", sname);

    if ( (ifp = fopen(sname, "r")) == NULL )
    {
        printf("cannot open %s \n", sname);
        exit(1);
    }
    
    printf("Enter target file name :");
    scanf("%s", tname);

    if (!strcmp(tname, "stdout"))
        ofp = stdout;
    else
        ofp = fopen(tname, "w");

    fileCopy(ifp, ofp);

    fclose(ifp);
    fclose(ofp);
}

void fileCopy(FILE *ifp, FILE *ofp)
{
    int c;

    // cp char by char
    //while( (c = fgetc(ifp)) != EOF )
    //    fputc(c, ofp);
    

    // cp line by line
    char line[80];
    while( fgets(line, 80, ifp) != NULL)
        fputs(line, ofp);
}
