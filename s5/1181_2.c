//병합정렬은 최상의 경우에도 최악의 경우에도 O(n*logn)...
//최악의 경우에도 같은 시간 복잡도를 가진다는 점이 퀵정렬과의 차이점이다.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    char word[51]; //50자 제한이니 \n 까지 생각해서 51로 설정
    int len;
} arr;

arr sorted[20001]; //병함 정렬에서 정렬 배열은 반드시 전역변수로 설정해야한다.
void merge(arr *block, int start, int mid, int end);
void Msort(arr *block, int start, int end);

int main (void)
{
    int N;
    scanf("%d", &N);
    arr *input = malloc(sizeof(arr) * N);
    
    for(int i = 0; i<N; i++)
    {
        memset(input[i].word, 0, 51);
        scanf("%s", input[i].word);
        input[i].len = strlen(input[i].word);
    }

    Msort(input, 0, N-1);

    printf("%s\n", input[0].word);
    for(int i=1; i < N; i++)
    {
        if(strcmp(input[i-1].word, input[i].word) != 0)
            printf("%s\n", input[i].word);
    }
    free(input);
    return 0;
}

void merge(arr *block, int start, int mid, int end)
{
    int i = start; //첫번째 조각 시작부분
    int j = mid + 1; //두번째 조각 시작부분
    int k = start; //합쳐서 만들 배열 시작부분

    //작은 순서대로 배열에 삽입해주자
    while(i <= mid && j <= end)
    {
        if(block[i].len < block[j].len)
        {
            sorted[k++] = block[i++];
        }
        else if (block[i].len > block[j].len)
        {
            sorted[k++] = block[j++];
        } 
        else // (block[i].len == block[j].len)
        {
            if(strcmp(block[i].word, block[j].word) < 0)
                sorted[k++] = block[i++];
            else
                sorted[k++] = block[j++];           
        }
    }
    //남은 데이터도 삽입해주자
    if(i > mid) //첫번째 조각의 배열이 끝나버렸다면
    {
        for(int t=j; t<=end; t++)
        {
            sorted[k] = block[t];
            k++;
        }
    }
    else
    {
        for(int t=i; t<=end; t++)
        {
            sorted[k] = block[t];
            k++;
        }
    }
    //정렬된 배열을 삽입해주자!
    for(int t=start; t<=end; t++)
        block[t] = sorted[t]; 
}

void Msort(arr *block, int start, int end)
{
    if(start < end)
    {
        int mid = (start + end)/2;
        Msort(block, start, mid);
        Msort(block, mid+1, end);
        merge(block, start, mid, end);
    }
}