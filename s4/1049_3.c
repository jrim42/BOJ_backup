#include <stdio.h>
#include <math.h>

int main (void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    int n1 = N / 6;
    int n2 = N % 6;

    double p[M], q[M];
    double pmin = 1000000, qmin = 1000000;
    int idx;

    for(int i=0; i<M; i++)
    {
        scanf("%lf %lf", &p[i], &q[i]);
        if(p[i] < pmin)
            pmin = p[i];
        if(q[i] < qmin)
            qmin = q[i];  
    }

    int price;
    if(pmin >= 6*qmin)
    {
        price = N * qmin;
    }
    else 
    {
        if(n2 >= (int)ceil(pmin/qmin))
            price = (n1 + 1) * pmin;
        else
            price = n1 * pmin + n2 * qmin;
    }
    
    printf("%d\n", price);
    return 0;
}