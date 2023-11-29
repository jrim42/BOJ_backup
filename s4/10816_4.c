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

int lower_bound (int key, int len)
{
    int start = 0;
    int end = len;
    while(start < end)
    {
        int mid = (start + end)/2;
        if(card[mid] >= key)
            end = mid;
        else
            start = mid + 1;
    }
    return start;
}

int upper_bound (int key, int len)
{
    int start = 0;
    int end = len;
    while(start < end)
    {
        int mid = (start + end)/2;
        if(card[mid] > key)
            end = mid;
        else
            start = mid + 1;
    }
    return start;
}

int main (void)
{
    int N, M;
    
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf(" %d", &card[i]);

    scanf("%d", &M);
    for(int i=0; i<M; i++)
        scanf(" %d", &target[i]);
    
    Msort(card, 0, N-1);

    for(int i=0; i<M; i++)
    {
        int key = target[i];
        printf("%d ", upper_bound(key, N) - lower_bound(key, N));
    }
        
    printf("\n");

    return 0;
}