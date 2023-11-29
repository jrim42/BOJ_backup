#include <stdio.h>

int LCM(int A, int B);

int main(void)
{
    int tc;
    int A;
    int B;

    scanf("%d", &tc);
    for (int i = 0; i < tc; i++)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", LCM(A, B));
    }
    return (0);
}

int LCM(int A, int B)
{
    int a;
    int b;
    int r;
    int gcd;
    int lcm;

    a = A;
    b = B;
    while(1)
    {
        r = b % a;
        if(r == 0)
        {
            gcd = a;
            lcm = (A * B) / gcd;
            break;
        }
        b = a;
        a = r;
    }
    return (lcm);
}