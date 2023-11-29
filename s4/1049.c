//풀이 잘못된 것 같음

#include <stdio.h>
#include <math.h>

int main (void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    int price[M];
    int n1 = N / 6;
    int n2 = N % 6;

    double p, q;
    int P, Q;
    for(int i=0; i<M; i++)
    {
        scanf("%lf %lf", &p, &q);
        // (int)ceil(p/q) 개부터는 패키지로 사는 것이 이득
        P = n1 + n2 / (int)ceil(p/q);
        Q = n2 % (int)ceil(p/q);
        price[i] = P*p + Q*q;
    }

    int min = 100001;
    for(int i=0; i<M; i++)
    {
        if(price[i] < min)
            min = price[i];
    }

    printf("%d\n", min);
    return 0;
}