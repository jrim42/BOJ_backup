#include <stdio.h>

int num = 10000;
int arr[10001];

void primeSeive()
{
    //초기화
    for(int i=0; i <= num; i++)
        arr[i] = i;

    for(int i=2; i <= num; i++)
    {
        if(arr[i] == 0)
            continue; //이미 지워진 숫자는 무시
        for(int j = 2*i; j <= num; j += i)
            arr[j] = 0; //0으로 만들어 주는 것 == 지워주는 것
    }
    for(int i=2; i <= num; i++)
    {
        if(arr[i] != 0)
            printf("%d ", arr[i]);
    }
}

int main (void)
{
    primeSeive();
    return 0;
}