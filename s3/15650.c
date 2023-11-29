#include <stdio.h>

void find_arr(int N, int M, int idx, int *arr);

int main(void)
{
    int N;
    int M;
    int arr[8];

    scanf("%d %d", &N, &M);
    for (int i = 0; i < 8; i++)
        arr[i] = 0;
    find_arr(N, M, 0, arr);
    return (0);
}

void find_arr(int N, int M, int idx, int *arr)
{
    if (idx == M)
    {
        for (int i = 0; i < M; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return ;
    }
    else if (idx == 0)
        for (int i = 1; i <= N; i++)
        {   
            arr[0] = i;
            find_arr(N, M, idx + 1, arr);
        }
    else
        for (int i = arr[idx - 1] + 1; i <= N; i++)
        {
            arr[idx] = i;
            find_arr(N, M, idx + 1, arr);
        }
}