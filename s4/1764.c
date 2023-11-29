#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    char n[N][21];
    char m[N][21];

    for(int i=0; i<N; i++)
    {
        scanf("%s", n[i]);
    }
    for(int i=0; i<M; i++)
    {
        scanf("%s", m[i]);
    }

    for(int i=0; i<N; i++)
    {
        printf("%s\n", n[i]);
    }
    for(int i=0; i<M; i++)
    {
        printf("%s\n", m[i]);
    }
    return 0;
}