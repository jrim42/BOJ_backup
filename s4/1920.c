#include <stdio.h>

void numFind (int *output[], int N, int input[], int M, int target[]);

int main (void)
{
    int N, M;
    int i;
    scanf("%d", &N);

    int input[N];
    for(i=0; i<N; i++)
        scanf(" %d", &input[i]);

    scanf("%d", &M);
    int target[M];
    for(i=0; i<M; i++)
        scanf(" %d", &target[i]);

    int *output[M];
    numFind (output, N, input, M, target);

    for(i=0; i<M; i++)
        printf("%d\n", *output[i]);
    return 0;
}

void numFind (int *output[], int N, int input[], int M, int target[])
{
    int i, j;
    for(i=0; i<M; i++)
    {
        *output[i] = 0;
        for(j=0; j<N; j++)
        {
            if(target[i] == input[j])
                *output[i] = 1;
        }
    }
}