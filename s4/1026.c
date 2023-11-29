#include <stdio.h>
#include <stdlib.h>

int cmp (const void *a, const void *b)
{
    int n1 = *(int *)a;
    int n2 = *(int *)b;
    return n1 > n2 ? 1 : n1 < n2 ? -1 : 0;
}

int main (void)
{
    int N, S=0;
    scanf("%d", &N);
    int A[N];
    int B[N];

    for(int i=0; i<N; i++)
        scanf("%d", &A[i]);
    for(int i=0; i<N; i++)
        scanf("%d", &B[i]);

    qsort(A, N, sizeof(int), cmp);
    qsort(B, N, sizeof(int), cmp);

    for(int i=0; i<N; i++)
    {
        S += A[i]*B[N-1-i];
    }
    printf("%d\n", S);

    return 0;
}