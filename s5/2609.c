#include <stdio.h>

void GCD_LCM (int m, int n, int *g, int *l);

int main (void)
{   
    int m, n;
    scanf("%d %d", &m, &n);

    int gcd, lcm;
    if(m >= n)
        GCD_LCM(m, n, &gcd, &lcm);       
    else
        GCD_LCM(n, m, &gcd, &lcm); 

    printf("%d\n%d\n", gcd, lcm);
    return 0;
}

void GCD_LCM (int m, int n, int *g, int *l)
{
    int a = m, b = n;
    int r;
    while(1)
    {
        r = a % b;
        if(r == 0)
        {
            *g = b;
            *l = (m * n) / *g;
            break;
        }
        a = b;
        b = r;
    }
    return ;
}
