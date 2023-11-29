#include <stdio.h>
#include <string.h>

void chess(char *cmd, char *A1, int *A2)
{
    char a1 = *A1;
    int a2 = *A2;

    if(strcmp(cmd, "R") == 0)
        a1++;
    else if (strcmp(cmd, "L") == 0)
        a1--;
    else if (strcmp(cmd, "B") == 0)
        a2--;
    else if (strcmp(cmd, "T") == 0)
        a2++;
    else if (strcmp(cmd, "RT") == 0)
    {
        a1++;
        a2++;
    }
    else if (strcmp(cmd, "LT") == 0)
    {
        a1--;
        a2++;
    }
    else if (strcmp(cmd, "RB") == 0)
    {
        a1++;
        a2--;
    }
    else if (strcmp(cmd, "LB") == 0)
    {
        a1--;
        a2--;
    }

    //말이 체스판 내부에 있다면 이동 후의 결과를 대입해주기
    if(a1 >= 65 && a1 <= 72 && a2 >= 1 && a2 <= 8)
    {
        *A1 = a1;
        *A2 = a2;
    }
}

void rev_chess(char *cmd, char *A1, int *A2)
{
    char a1 = *A1;
    int a2 = *A2;
    
    if(strcmp(cmd, "R") == 0)
        a1--;
    else if (strcmp(cmd, "L") == 0)
        a1++;
    else if (strcmp(cmd, "B") == 0)
        a2++;
    else if (strcmp(cmd, "T") == 0)
        a2--;
    else if (strcmp(cmd, "RT") == 0)
    {
        a1--;
        a2--;
    }
    else if (strcmp(cmd, "LT") == 0)
    {
        a1++;
        a2--;
    }
    else if (strcmp(cmd, "RB") == 0)
    {
        a1--;
        a2++;
    }
    else if (strcmp(cmd, "LB") == 0)
    {
        a1++;
        a2++;
    }

    *A1 = a1;
    *A2 = a2;
}

int main (void)
{
    int N;
    char K1, X1;
    int K2, X2;
    scanf("%c%d %c%d %d", &K1, &K2, &X1, &X2, &N);

    for(int i=0; i<N; i++)
    {
        char cmd[3];
        scanf("%s", cmd);
        chess(cmd, &K1, &K2);
        if(K1 == X1 && K2 == X2)
        {
            chess(cmd, &X1, &X2);
        }
        if(K1 == X1 && K2 == X2)
        {
            rev_chess(cmd, &K1, &K2);
        }
    }

    printf("%c%d\n", K1, K2);
    printf("%c%d\n", X1, X2);

    return 0;
}