#include <stdio.h>
#include <stdlib.h>

int GCD(int A, int B);

int main(void)
{
    int N;
    int *arr;
    int gcd;

    scanf("%d", &N);
    arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL)
        return (-1);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    
    for (int i = 1; i < N; i++)
    {
        if (arr[0] % arr[i] == 0)
            printf("%d/%d\n", arr[0] / arr[i], 1);
        else if (arr[0] > arr[i])
        {
            gcd = GCD(arr[0], arr[i]);
            printf("%d/%d\n", arr[0] / gcd , arr[i] / gcd);
        }
        else
        {
            gcd = GCD(arr[i], arr[0]);
            printf("%d/%d\n", arr[0] / gcd , arr[i] / gcd);
        } 
    }    
    return (0);
}

int GCD(int A, int B)
{
    int a;
    int b;
    int r;
    int gcd;

    a = A;
    b = B;
    while(1)
    {
        r = a % b;
        if(r == 0)
        {
            gcd = b;
            break;
        }
        a = b;
        b = r;
    }
    return (gcd);
}