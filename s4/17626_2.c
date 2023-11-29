#include <stdio.h>
#include <math.h>

int g_lag[50001];

int lagrange(int n);

int main(void)
{
    int n;

    scanf("%d", &n);
    printf("%d\n", lagrange(n));
    return (0);
}

int lagrange(int n)
{
    g_lag[0] = 0;
    g_lag[1] = 1;
    
    for (int i = 2; i <= n; i++)
    {
        g_lag[i] = 4;
        for (int j = 1; j <= sqrt(i); j++)
        {
            if (g_lag[i - (j * j)] < g_lag[i])
                g_lag[i] = g_lag[i - (j * j)] + 1;
        }
    }
    return (g_lag[n]);
}