//홀수번째에 있는 숫자를 계속 지우기를 반복
#include <stdio.h>

int main (void)
{
    int N;
    scanf("%d", &N);
    int i = 2;
    
    while(i <= N)
    {
        i = i * 2;
    }

    printf("%d\n", i/2);
    return 0 ;
}