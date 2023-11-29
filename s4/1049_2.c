#include <stdio.h>
#include <math.h>

int main (void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    int n1 = N / 6;
    int n2 = N % 6;

    double p[M], q[M];
    double pmin = 1001, qmin = 1001;
    int idx;

    for(int i=0; i<M; i++)
    {
        scanf("%lf %lf", &p[i], &q[i]);
        if(p[i] < pmin)
        {
            pmin = p[i];
            idx = i;
        }
        if(q[i] < qmin)
            qmin = q[i];  
    }

    int P, Q;
    if((int)ceil(pmin/q[idx])*qmin < pmin)
    {
        P = n1;
        Q = n2;
    }
    else
    {
        P = n1 + n2 / (int)ceil(pmin/q[idx]);
        Q = n2 - (int)ceil(pmin/q[idx]);
    }

    int price = P*pmin + Q*qmin;
    printf("%d\n", price);
    return 0;
}