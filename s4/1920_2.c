#include <stdio.h>
#include <stdlib.h>

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
        else // arr[mid] > key
            right = mid - 1;
    }
    return 0;
}

int cmp (const void *a, const void *b)
{
    int n1 = *(int *)a;
    int n2 = *(int *)b;
    return n1 > n2 ? 1 : n1 < n2 ? -1 : 0;
}

int main (void)
{
    int i, N, M;

    scanf("%d", &N);
    int *input = (int *)malloc(N * sizeof(int));
    for(i=0; i < N; i++)
        scanf(" %d", &input[i]);

    scanf("%d", &M);
    int *target = (int *)malloc(M * sizeof(int));
    for(i=0; i < M; i++)
        scanf(" %d", &target[i]);

    qsort(input, N, sizeof(int), cmp);

    for(i=0; i < M; i++)
        printf("%d\n", binary_search(input, N, target[i]));

    free(input);
    free(target);
    return 0;
}