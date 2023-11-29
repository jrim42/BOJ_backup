#include <stdio.h>
#include <math.h>

int arr[1000001];

void primeSeive(int M, int N)
{
    for(int i = 2; i <= N; i++)
    {
        arr[i] = i;
    }
        
    for(int i = 2; i <= N; i++)
    {
        if(arr[i] == 0)
            continue;
        for(int j = 2*i; j <= N; j += i)
            arr[j] = 0;
    }

    for(int i = M; i <= N; i++)
    {
        if(arr[i] != 0)
            printf("%d\n", arr[i]);
    }
}

int main (void)
{
    int M, N;
    scanf("%d %d", &M, &N);
    primeSeive(M, N);
    return 0;
}
