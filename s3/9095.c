#include <stdio.h>

int num[12];

int cnt_case(int N);

int main(void)
{
    int tc;
    int N;

    scanf("%d", &tc);
    for (int i = 0; i < tc; i++)
    {
        scanf("%d", &N);
        printf("%d\n", cnt_case(N));
    }
    return (0);
}

int cnt_case(int N)
{
    num[1] = 1;
    num[2] = 2;
    num[3] = 4;

    if (N > 3)
        for (int i = 4; i <= N; i++)
            num[i] = num[i - 1] + num[i - 2] + num[i - 3];
    return (num[N]);
}
