#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    int arr[M];
    for(int i=0; i<M; i++)
    {
        scanf(" %d", &arr[i]);
    }

    int cnt = 0;
    int n = 1;
    for(int i=0; i<M; i++)
    {
        if(abs(arr[i]-n) <= N-abs(arr[i]-n))
        {
            cnt += abs(arr[i]-n);
        }
        else
        {
            cnt += N-abs(arr[i]-n);
        }
        n = arr[i];
        N--;
    }
    printf("%d\n", cnt);

    return 0;
}