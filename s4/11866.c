#include <stdio.h>

void joseph (int N, int K)
{
    int arr[10001] = {0};
    int cnt;
    int j = 1;
    printf("<");
    for(int i=0; i<N; i++)
    {
        cnt = 0;
        while(1)
        {
            if(arr[j]==0)
                cnt++;
            if(cnt == K)
            {
                arr[j] = -1;
                if(i == N - 1)
                    printf("%d>\n", j);
                else
                    printf("%d, ", j);
                break;
            }
            j++;
            if(j > N)
                j = 1;
        }
    }
}

int main (void)
{
    int N, K;
    scanf("%d %d", &N, &K);
    joseph(N, K);
    return 0;
}