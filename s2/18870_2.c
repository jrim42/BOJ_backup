//시간초과

#include <stdio.h>
#include <stdlib.h>

int sorted[1000001];

void merge(int *array, int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = start;

    while(i <= mid && j <= end)
    {
        if(array[i] <= array[j])
            sorted[k++] = array[i++];
        else
            sorted[k++] = array[j++];
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
void Msort(int *array, int start, int end)
{
    if(start < end)
    {
        int mid = (start + end)/2;
        Msort(array, start, mid);
        Msort(array, mid+1, end);
        merge(array, start, mid, end);
    }
}

int lower_bound (int *arr, int key, int size)
{
    int start = 0;
    int end = size -1;
    while(start < end)
    {
        int mid = (start + end)/2;
        if(arr[mid] >= key)
            end = mid;
        else
            start = mid + 1;
    }

    int cnt = 0;
    for(int i = 0; i<start; i++)
    {
        if(arr[i] != arr[i-1])
            cnt++;
    }
    return cnt;
}

int main (void)
{
    int N;
    scanf("%d", &N);
    int *arr = malloc(N*sizeof(int));
    int *key = calloc(N, sizeof(int));

    for(int i=0; i<N; i++)
    {
        scanf(" %d", &arr[i]);
        key[i] = arr[i];
    }

    Msort(arr, 0, N-1); 

    for(int i=0; i<N; i++)
        printf("%d ", lower_bound (arr, key[i], N));
    
    printf("\n");
    free(arr);
    free(key);
    return 0;
}