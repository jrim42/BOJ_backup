#include <stdio.h>

void    brdg_cnt(int n, int m);

int main(void)
{
    int tc;
    int N;
    int M;

    scanf("%d", &tc);
    for (int i = 0; i < tc; i++)
    {
        scanf("%d %d", &N, &M);
        brdg_cnt(N, M);
    }
    return (0);
}

void    brdg_cnt(int n, int m)
{
    double a;
    double b;

    a = 1;
    b = 1;
    for (int i = n + 1; i < m + 1; i++)
        a *= i;
    for (int i = 1; i <= m - n; i++)
        b *= i;
    printf("%.lf\n", a / b);
}