#include <stdio.h>

void Centauri (int d)
{
    int cnt = 2;
    int speed = 1;
    while(d > 0)
    {
        if(speed + 1 <= d)
        {
            d -= speed;
            speed++;
            cnt++;
        }
        else if (speed == d)
        {
            d -= speed;
            cnt++;
        }
        else if (speed - 1 == d)
        {
            d -= speed;
            speed--;
            cnt++;
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
        Centauri (y-x-2);
    }
    return 0;
}