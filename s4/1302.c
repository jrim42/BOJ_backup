#include <stdio.h>
#include <string.h>

int main (void)
{
    int N;
    scanf("%d", &N);
    int arr[1000] = {0};
    char book[1000][51];

    for(int i=0; i<N; i++)
    {
        scanf("%s", &book[i]);
        for(int j=0; j<=i; j++)
            if(strcmp (book[i], book[j])==0)
            {
                arr[i]++;
            }

    }
}