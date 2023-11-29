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

int search(int *arr, int size, int key)
{
    int left = 0;
    int right = size;
    int mid;
    int idx;
    
    while(left < right)
    {
        mid = (left + right) / 2;
    
        if(arr[left] == key)
            return left;
        else if(arr[mid] == key)
            return mid;
        else if(arr[right] == key)
            return right;
        else if(arr[mid] < key)
            left = mid + 1;
        else // arr[mid] > key
            right = mid - 1;
    }
    return 0;
}

int main (void)
{
    int N;
    scanf("%d", &N);
    int *arr = malloc(N*sizeof(int));
    int *arr2 = calloc(N, sizeof(int));
    int *key = calloc(N, sizeof(int));

    for(int i=0; i<N; i++)
    {
        scanf(" %d", &arr[i]);
        key[i] = arr[i];
    }

    Msort(arr, 0, N-1); 

    //중복 제거
    int j = 0;
    for(int i=0; i<N; i++)
    {
        if(arr[i] != arr[i+1])
        {
            arr2[j] = arr[i]; 
            j++;
        }
    }

    for(int i=0; i<N; i++)
        printf("%d ", search(arr2, j, key[i]));
    
    printf("\n");
    free(arr);
    free(arr2);
    free(key);
    return 0;
}