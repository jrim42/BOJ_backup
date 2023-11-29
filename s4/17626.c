#include <stdio.h>

int lagrange(int n);
int max_square(int n, int flag);

int main(void)
{
    int n;

    scanf("%d", &n);
    printf("%d\n", lagrange(n));
    return (0);
}

int lagrange(int n)
{
    int cnt;
    int num;
    int flag;

    flag = 1;
    cnt = 5;
    while (cnt > 4)
    {
        cnt = 0;
        num = n;
        while (num > 0)
        {
            if (cnt == 0)
                num -= max_square(num, flag);
            else
                num -= max_square(num, 1);
            cnt++;
        }
        if (cnt <= 3)
            return (cnt);
        flag++;
    }
    return (4);
}

int max_square(int n, int flag)
{
    int rt;

    rt = 1;
    if (n == 1)
        return (1);
    while (rt * rt <= n && rt < 46301)
        rt++;
    rt -= flag;
    return (rt * rt);
}