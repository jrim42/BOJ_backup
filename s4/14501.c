#include <stdio.h>

int main (void)
{
    int N;
    scanf("%d", &N);
    int arr[N][2];
    int result;
    for(int i=0; i<N; i++)
    {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }


    printf("%d\n", result);
    return 0;
}