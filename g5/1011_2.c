#include <stdio.h>

void Centauri (int d)
{
    int cnt;
    int s;
    for(s = 1; ; s++)
    {
        if(s*(s+1)/2 + s*(s-1)/2 == d)
        {
            cnt = 2*s-1;
            break;
        }
        else if (s*(s+1) == d)
        {
            cnt = 2*s;
            break;
        } 
    }
    printf("%d\n", cnt);
}

int main (void)
{
    int T;
    int x, y;
    scanf("%d", &T);
    for(int i=0; i<T; i++)
    {
        scanf("%d %d", &x, &y);
        Centauri (y-x);
    }
    return 0;
}