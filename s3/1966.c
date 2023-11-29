#include <stdio.h>

int findMax(int Q[], int N, int front, int rear)
{
    int max = Q[front];
    int idx = 0;
    for (int i = front + 1; i <= rear; i++)
        if (max < Q[i]) 
        {
            max = Q[i];
            idx = i;
        }
    return idx;
}

int main(void)
{
    int caseNum;
    int N, M;
    int Q[10000];
    int front, rear, now;

    scanf("%d", &caseNum);
    while (caseNum--)
    {
        scanf("%d %d", &N, &M);
        front = now = 0;
        rear = N - 1;
        for (int i = 0; i < N; i++)
            scanf(" %d", &Q[i]);
        while (front - 1 != M)
        {
            int maxIndex = findMax(Q, N, front, rear);
            for (int i = front; i < maxIndex; i++)
            {
                Q[++rear] = Q[front++];
                M = (M == front - 1 ? rear : M);
            }
            front++;
            now++;
        }
        printf("%d\n", now);
    }
    return 0;
}
