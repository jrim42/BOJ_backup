#include <stdio.h>
#include <stdlib.h>

double mean(int arr[], int n)
{
    double sum = 0;
    double num = n;
    for(int i=0; i<n; i++)
        sum += arr[i];

    return sum/num;
}

int median(int arr[], int n)
{
    int mid = n/2;
    if(n%2 != 0)
        return arr[mid];
    else
        return (arr[mid-1]+arr[mid])/2;
}

int mode(int arr[], int n)
{
    int cnt[8001] = {0};
    int i, max1 = 0, max2 = 0;
    int idx1, idx2;
    for(i= 0; i<8001; i++)
    {
        for(int j=0; j<n; j++)
        if(arr[j] == i - 4000)
            cnt[i]++;
    }
    for(i=0; i<8001; i++)
    {
        if(cnt[i] > max1)
        {
            max2 = max1;
            max1 = cnt[i];
            idx1 = i - 4000;
        }
        else if (cnt[i] > max2)
        {
            max2 = cnt[i];
            idx2 = i - 4000;
        }
    }
    if(max1 == max2)
        return idx1 < idx2 ? idx2 : idx1;
    else
        return idx1;
}

int range(int arr[], int n)
{
    int max = arr[n-1];
    int min = arr[0];
    
    return max-min;
}

int sorted [500001];

void merge(int *arr, int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = start;

    while(i <= mid && j <= end)
    {
        if(arr[i] <= arr[j])
            sorted[k++] = arr[i++];
        else
            sorted[k++] = arr[j++];
    }
    if(i > mid)
        for(int t=j; t<=end; t++)
        {
            sorted[k] = arr[t];
            k++;
        }
    else
        for(int t=i; t<=end; t++)
        {
            sorted[k] = arr[t];
            k++;
        }
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
    
    int *arr = malloc(N * sizeof(int));
    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);

    Msort(arr, 0, N-1);

    printf("%.0f\n", mean(arr, N)+0.5);
    printf("%d\n", median(arr, N));
    printf("%d\n", mode(arr, N));
    printf("%d\n", range(arr, N));

    free(arr);
    return 0;
}