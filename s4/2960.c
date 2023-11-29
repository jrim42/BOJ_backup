#include <stdio.h>

int arr[1000];

int primeSeive(int num, int limit)
{
    int cnt = 0;
    
    for(int i=2; i <= num; i++)
        arr[i] = i;

    for(int i=2; i <= num; i++)
    {
        if(arr[i] == 0)
            continue;
        for(int j = i; j <= num; j += i)
        {
            if(arr[j] != 0)
            {
                arr[j] = 0;
                cnt++;
            }
            if(cnt == limit)
                return j;
        }       
    }
}

int main (void)
{
    int N, K;
    int result;
    scanf("%d %d", &N, &K);
    
    result = primeSeive(N, K);
    printf("%d\n", result);

    return 0;
}