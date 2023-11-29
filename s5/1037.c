#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int *arr;
    int min;
    int max;

    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
        return (-1);
    min = 1000001;
    max = 1;
    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &arr[i]);
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    printf("%d\n", min * max);
    return (0);
}