#include <stdio.h>
#include <math.h>

void hanoi_tower(int n, char from, char to, char via)
{
    if (n == 1)
        printf("Move : %c -> %c \n", from, to);
    else {
        hanoi_tower(n - 1, from, via, to);
        printf("Move : %c -> %c \n", from, to);
        hanoi_tower(n - 1, via, to, from);
    }
}

double mersenne(int i)
{
    return pow(2, i) - 1;
}

int main()
{
    hanoi_tower(4, 'A', 'C', 'B'); // from, to, via

    for(int i = 1; i <= 50; i++)
    {
        double m = mersenne(i);

        printf("mersenne num : %d = %.0f = %.1f day = %.1f year \n", 
                i, m, m / 3600 / 24, m / 3600 / 24 / 365);
    }
}
