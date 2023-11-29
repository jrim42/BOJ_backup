#include <stdio.h>

int main()
{
    int N;
    scanf("%d",&N);

    int card[1000005];
    int h=0,t=0;

    for(int i=1; i<=N; i++)
    {
        card[h]=i;
        h++;
    }

    while(h-t != 1){
        t++;
        int tmp = card[t];
        t++;
        card[h] = tmp;
        h++;
    }
    printf("%d\n", card[t]);
}
