#include <stdio.h>

int card[500001];
int target[500001];
int sorted[500001];

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

int binary_search(const int arr[], int size, int key)
{
    int left = 0;
    int right = size - 1;
    int mid;
    while(left < right)
    {
        mid = (left + right) / 2;
    
        if(arr[left] == key || arr[mid] == key || arr[right] == key)
            return 1;
        else if(arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 0;
}

int main (void)
{
    int N, M;
    
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf(" %d", &card[i]);

    scanf("%d", &M);
    int result[M];
    for(int i=0; i<M; i++)
    {
        scanf(" %d", &target[i]);   
        result[i] = 0;
    }
        
    Msort(card, 0, N-1);
    
    for(int i=0; i < M; i++)
        printf("%d ", binary_search(card, N, target[i]));
    printf("\n");

    return 0;
}