#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    char name[101];
    int age;
    int num;
} member;

member sorted[100001];

void merge(member *array, int start, int mid, int end);
void Msort(member *array, int start, int end);

int main (void)
{
    int N;
    scanf("%d", &N);
    member *input = malloc(sizeof(member) * N);
    
    for(int i = 0; i<N; i++)
    {
        scanf("%d %s", &input[i].age, input[i].name);
        input[i].num = i;
    }

    Msort(input, 0, N-1);

    for(int i=0; i < N; i++)
        printf("%d %s\n", input[i].age, input[i].name);

    free(input);
    return 0;
}

void merge(member *array, int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = start;

    while(i <= mid && j <= end)
    {
        if(array[i].age < array[j].age)
            sorted[k++] = array[i++];
        else if (array[i].age > array[j].age)
            sorted[k++] = array[j++];
        else
        {
            if(array[i].num < array[j].num)
                sorted[k++] = array[i++];
            else
                sorted[k++] = array[j++];           
        }
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

void Msort(member *array, int start, int end)
{
    if(start < end)
    {
        int mid = (start + end)/2;
        Msort(array, start, mid);
        Msort(array, mid+1, end);
        merge(array, start, mid, end);
    }
}
