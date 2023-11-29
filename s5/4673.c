//10,000 이하의 셀프 넘버를 한 줄에 하나씩 오름차순 출력
#include <stdio.h>

int sum (int n)
{
    int sum = n;
    while (n>0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main (void)
{
    int arr[10001] = {0};
    int check;

    for(int i=0; i<10000; i++)
    {
        check = sum(i);
        if(check < 10001)
            arr[check] = 1;
    }

    for(int i=0; i<10000; i++)
    {
        if(arr[i] == 0)
            printf("%d\n", i);
    }
    return 0;
}