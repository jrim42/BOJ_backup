#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrimeNum (int x)
{
    int end = (int)sqrt(x);
    for(int i=2; i<=end; i++)
        if(x%i == 0)
            return false;
    return true;
}

int main (void)
{
    int N, cnt = 0;
    scanf("%d", &N);
    int arr[N];
    for(int i = 0; i < N; i++)
    {
        scanf(" %d", &arr[i]);
        if(arr[i] == 1)
            cnt--;
        if(isPrimeNum(arr[i]) == 1)
            cnt++;
    }

    printf("%d\n", cnt);
    return 0;
}