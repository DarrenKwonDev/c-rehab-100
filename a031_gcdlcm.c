#include <stdio.h>

int gcd(int x, int y);

int main()
{
    int a, b, GCD, LCM;
    
    printf("2 elem: ");
    scanf("%d %d", &a, &b);

    GCD = gcd(a, b);
    LCM = (a * b) / GCD;

    printf("%d %d GCD %d | LCM %d \n", a, b, GCD, LCM);
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
