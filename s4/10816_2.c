#include <stdio.h>
#include <stdlib.h>

int card[500001];
int target[500001];

int cmp (const void *a, const void *b)
{
    int n1 = *(int *)a;
    int n2 = *(int *)b;
    return n1 > n2 ? 1 : n1 < n2 ? -1 : 0;
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
            result = bin_search(mid+1 , right, cnt, key);
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
    
    qsort(card, N, sizeof(int), cmp);

    for(int i=0; i<M; i++)
    {
        int key = target[i];
        printf("%d ", bin_search(0, N-1, 0, key));
    }
        
    printf("\n");

    return 0;
}