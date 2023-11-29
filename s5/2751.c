#include <stdio.h>
#include <stdlib.h>

int sorted[1000001];

void merge(int *arr, int start, int mid, int end);
void Msort(int *arr, int start, int end);

int main (void)
{
    int N;
    scanf("%d", &N);
    int *num_array = malloc(sizeof(int) * N);
    
    for(int i = 0; i<N; i++)
        scanf("%d", &num_array[i]);

    Msort(num_array, 0, N-1);

    for(int i=0; i < N; i++)
        printf("%d\n", num_array[i]);

    free(num_array);
    return 0;
}

void merge(int *arr, int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = start;

    while(i <= mid && j <= end)
    {
        if(arr[i] < arr[j])
            sorted[k++] = arr[i++];
        else
            sorted[k++] = arr[j++];
    }

    if(i > mid)
        while(j <= end)
            sorted[k++] = arr[j++];
    else
        while(i <= mid)
            sorted[k++] = arr[i++];

    for(int t=start; t<=end; t++)
        arr[t] = sorted[t]; 
}

void Msort(int *arr, int start, int end)
{
    if(start < end)
    {
        int mid = (start + end)/2;
        Msort(arr, start, mid);
        Msort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}