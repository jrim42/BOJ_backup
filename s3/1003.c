#include <stdio.h>

int fibonacci(int n);

int main(void)
{
    int tc;
    int N;

    scanf("%d", &tc);
    for (int i = 0; i < tc; i++)
    { 
        scanf("%d", &N);
        if (N == 0)
            printf("1 0\n");
        else if (N == 1)
            printf("0 1\n");
        else 
            printf("%d %d\n", fibonacci(N - 1), fibonacci(N));
    }
    return (0);
}

int fibonacci(int n) 
{
    int fib[40] = {0};

    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n + 1; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    return (fib [n]);
}