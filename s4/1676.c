#include <stdio.h>

int main (void)
{
    int N;
    scanf("%d", &N);
    int cnt = 0;

    for(int i=5; i<=N; i*=5)
    {
        cnt += (N/i);
    }
    printf("%d\n", cnt);
    
    return 0;
}