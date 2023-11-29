#include <stdio.h>

int arr[9];
int flag[9];

void find_arr(int N, int M, int idx);

int main(void)
{
    int N;
    int M;

    scanf("%d %d", &N, &M);
    for (int i = 0; i < 9; i++)
    {
        arr[i] = 0;
        flag[i] = 0;
    }
    find_arr(N, M, 0);
    return (0);
}

void find_arr(int N, int M, int idx)
{
    int num;

    num = 1;
    if (idx == M)
    {
        for (int i = 0; i < M; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return ;
    }
    while (num <= N)
    {
        if (flag[num] != 1)
        {
            arr[idx] = num;
            flag[num] = 1;
            find_arr(N, M, idx + 1);
            flag[num] = 0;
        }
        num++;
    }
}