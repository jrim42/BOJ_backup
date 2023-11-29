#include <stdio.h>
#include <stdlib.h>

int cmp (const void *a, const void *b)
{
    int n1 = *(int *)a;
    int n2 = *(int *)b;
    return n1 > n2 ? 1 : n1 < n2 ? -1 : 0;
}

double mean(int arr[], int n)
{
    float sum = 0;
    for(int i=0; i<n; i++)
        sum += arr[i];

    return sum/n;
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
    for(i= 0; i<n; i++)
        cnt[arr[i] + 4000]++;

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

int main (void)
{
    int N;
    scanf("%d", &N);
    
    int arr[N];
    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);

    qsort(arr, N, sizeof(int), cmp);

    printf("%.0lf\n", mean(arr, N));
    printf("%d\n", median(arr, N));
    printf("%d\n", mode(arr, N));
    printf("%d\n", range(arr, N));

    return 0;
}