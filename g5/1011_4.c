#include <stdio.h>

void Centauri (int d)
{
    int cnt = 0;
    long long int s = 0;
    int half = d % 2 == 0 ? d / 2 : d / 2 + 1;

    for(s = 0; (s+1)*(s+2)/2 <= half; s++)
        cnt++;
    
    int A = s*(s+1)/2;

    if(d == 1)
    {
        cnt = 1;
    }
    else if(d - A > A)
    {
        if(d - 2*A > s + 1)
            cnt = cnt*2 + 2;
        else if(d - 2*A == s + 1) 
            cnt = cnt*2 + 1;
        else if(d - 2*A == s) 
            cnt = cnt*2 + 1;
        else // d - 2*A < s
            cnt = cnt*2 + 1;
    }
    else // d - A <= A
    {
        cnt *= 2;
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