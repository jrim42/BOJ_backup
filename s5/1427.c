#include <stdio.h>
#include <stdlib.h>

int sorted[11];

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

int main (void)
{
    int N;
    scanf("%d", &N);
    int n = N;
    int cnt = 0;

    while(n>0)
    {
        n /= 10;
        cnt++;
    }

    int *arr = malloc(sizeof(int) * cnt);
    
    for(int i=0; i<cnt; i++)
    {
        arr[i] = N % 10;
        N /= 10;
    }

    Msort(arr, 0, cnt-1);

    for(int i = cnt-1; i >= 0; i--)
        printf("%d", arr[i]);

    printf("\n");
    free(arr);
    return 0;

}