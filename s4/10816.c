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

int bin_search(int left, int right, int cnt, int key)
{
    int mid = (left + right) / 2;
    int result;
    
    if (left > right)
        return cnt;
    else
    {
        if (card[mid] > key)
            result = bin_search(left, mid-1, cnt, key);
        else if (card[mid] < key)
            result = bin_search(mid+1, right, cnt, key);
        else
        {
            result = bin_search(left, mid-1, cnt, key);
            result += bin_search(mid+1, right, cnt, key);
            result += 1;
        }
        return result;
    }
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
        printf("%d ", bin_search(0, N-1, 0, key));
    }
        
    printf("\n");

    return 0;
}