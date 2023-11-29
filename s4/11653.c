#include <stdio.h>

int main (void)
{
    int N;
    scanf("%d", &N);
    int arr[N]; 

    for(int i=0; i <= N; i++)
        arr[i] = i;

    for(int i=2; i <= N; i++)
    {
        if(arr[i] == 0)
            continue;
        for(int j = 2*i; j <= N; j += i)
            arr[j] = 0;
    }

    int n = N;
    for(int i=2; i <= N; i++)
    {
        if(arr[i] != 0)
        {
            if(n % arr[i] == 0)
            {
                printf("%d\n", arr[i]);
                n /= arr[i];
                i--;
            }
        } 
        if(n == 1)
            break;        
    }
    return 0;
}