#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    int w;
    int h;
    int rank;
} data;

int main (void)
{
    int N;
    scanf("%d", &N);
    data *input = malloc(sizeof(data) * N);
    
    for(int i=0; i<N; i++)
        scanf("%d %d", &input[i].w, &input[i].h);

    for(int i=0; i<N; i++)
    {
        input[i].rank = 0;
        for(int j=0; j<N; j++)
        {   
            if(input[i].w < input[j].w && input[i].h < input[j].h)
                input[i].rank++;            
        }
    }

    for(int i=0; i < N; i++)
        printf("%d ", input[i].rank + 1);

    printf("\n");
    free(input);
    return 0;
}