#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    char chess[50][50];

    for(int i=0; i<n; i++)
        scanf("%s", chess[i]);

    int cnt, cnt_min = 65;

    for(int i=0; i<n-7; i++)
        for(int j=0; j<m-7; j++)
        {
            cnt = 0;
            char start = chess[i][j];
            int startNum = i+j;
            for(int a=i; a<i+8; a++)
            {
                for(int b=j; b<j+8; b++)
                {
                    
                    if((a + b) % 2 == startNum % 2 && chess[a][b] != start)
                        cnt++;
                    else if ((a + b) % 2 != startNum % 2 && chess[a][b] == start)
                        cnt++;
                }
            }
            if(cnt > 32)
                cnt = 64 - cnt;
            if(cnt < cnt_min)
                cnt_min = cnt;
        }
        
    printf("%d\n", cnt_min);
    return 0;
}

