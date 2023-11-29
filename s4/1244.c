#include <stdio.h>
#include <stdlib.h>

void male (int *arr, int num, int size)
{   
    for(int i = 1; i*num<=size; i++)
    {
        if(arr[i*num]==1)
            arr[i*num] = 0;
        else
            arr[i*num] = 1; 
    }
}

void female (int *arr, int num, int size)
{
    for(int i = 0; num-i > 0 && num+i <= size; i++)
    {
        if(arr[num-i]==arr[num+i])
        {
            if(arr[num-i]==1)
            {
                arr[num-i] = 0;
                arr[num+i] = 0;
            }
            else
            {
                arr[num-i] = 1;
                arr[num+i] = 1;
            }
        }
        else
            break;
    }
}

int main (void)
{
    int N;
    scanf("%d", &N);
    int *arr = (int*)malloc((N+1)*sizeof(int));
    for(int i=1; i<=N; i++)
    {
        scanf(" %d", &arr[i]);
    }

    int student;
    int s, n;
    scanf("%d", &student);
    for(int i=0; i<student; i++)
    {
        scanf("%d %d", &s, &n);
        if(s == 1)
            male (arr, n, N);
        else
            female (arr, n, N);
    }

    for(int i=1; i<=N; i++)
    {
        printf("%d", arr[i]);
        if(i % 20 == 0 || i == N)
            printf("\n");
        else
            printf(" ");   
    }
    free(arr);
    return 0;
}