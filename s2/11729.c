#include <stdio.h>
#include <math.h>

void    hanoi(int N, int start, int pos);

int main(void)
{
    int N;

    scanf("%d", &N);
    printf("%d\n", (int)pow(2, N) - 1);
    hanoi(N, 1, 3);
    return (0); 
}

void    hanoi(int N, int start, int end)
{
    int other;

    other = 6 - start - end;
    if (N == 1)
        printf("%d %d\n", start, end);
    else
    {
        hanoi(N - 1, start, other);
        hanoi(1, start, end);
        hanoi(N - 1, other, end);
    }
}