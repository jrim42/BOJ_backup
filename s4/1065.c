#include <stdio.h>

int main (void)
{
    int N;
    scanf("%d", &N);
    int cnt = 0;

    if(N < 100)
        cnt = N;
    else
    {
        cnt = 99;
        for(int i=100; i<=N; i++)
        {
            int a = i / 100;
            int b = (i % 100) / 10;
            int c = i % 10;
            if(a + c == 2*b)
                cnt++;
        }
    }
    
    printf("%d\n", cnt);
    return 0;
}