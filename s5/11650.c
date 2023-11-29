#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    int x;
    int y;
} coord;

coord sorted[100001];

void merge(coord *array, int start, int mid, int end);
void Msort(coord *array, int start, int end);

int main (void)
{
    int N;
    scanf("%d", &N);
    coord *input = malloc(sizeof(coord) * N);
    
    for(int i = 0; i<N; i++)
    {
        scanf("%d %d", &input[i].x, &input[i].y);
    }

    Msort(input, 0, N-1);

    for(int i=0; i < N; i++)
        printf("%d %d\n", input[i].x, input[i].y);

    free(input);
    return 0;
}

void merge(coord *array, int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = start;

    while(i <= mid && j <= end)
    {
        if(array[i].x < array[j].x)
            sorted[k++] = array[i++];
        else if (array[i].x > array[j].x)
            sorted[k++] = array[j++];
        else
        {
            if(array[i].y < array[j].y)
                sorted[k++] = array[i++];
            else
                sorted[k++] = array[j++];           
        }
    }

    if(i > mid)
        while(j <= end)
            sorted[k++] = array[j++];
    else
        while(i <= mid)
            sorted[k++] = array[i++];

    for(int t=start; t<=end; t++)
        array[t] = sorted[t]; 
}

void Msort(coord *array, int start, int end)
{
    if(start < end)
    {
        int mid = (start + end)/2;
        Msort(array, start, mid);
        Msort(array, mid+1, end);
        merge(array, start, mid, end);
    }
}
