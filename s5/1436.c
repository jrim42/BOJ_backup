#include <stdio.h>
#include <math.h>

int main (void)
{
    int N;
    scanf("%d", &N);
    int num = 665, idx = 0;

    while(idx < N)
    {
        num++;

        for(int i = 0; i < 10; i++)
            if(num / (int)pow(10, i) % 1000 == 666)
            {
                idx++;
                break;
            }
    }

    printf("%d\n", num);
    return 0;
}