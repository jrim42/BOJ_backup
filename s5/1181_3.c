#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    char word[51];
    int len;
} arr;

arr sorted[20001];

void merge(arr *array, int start, int mid, int end);
void Msort(arr *array, int start, int end);

int main (void)
{
    int N;
    scanf("%d", &N);
    arr *input = malloc(sizeof(arr) * N);
    
    for(int i = 0; i<N; i++)
    {
        scanf("%s", input[i].word);
        input[i].len = strlen(input[i].word);
    }

    Msort(input, 0, N-1);

    printf("%s\n", input[0].word);

    for(int i=1; i < N; i++)
        if(strcmp(input[i-1].word, input[i].word) != 0)
            printf("%s\n", input[i].word);

    free(input);
    return 0;
}

void merge(arr *array, int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = start;

    while(i <= mid && j <= end)
    {
        if(array[i].len < array[j].len)
            sorted[k++] = array[i++];
        else if (array[i].len > array[j].len)
            sorted[k++] = array[j++];
        else
        {
            if(strcmp(array[i].word, array[j].word) < 0)
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

void Msort(arr *array, int start, int end)
{
    if(start < end)
    {
        int mid = (start + end)/2;
        Msort(array, start, mid);
        Msort(array, mid+1, end);
        merge(array, start, mid, end);
    }
}