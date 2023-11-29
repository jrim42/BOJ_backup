#include <stdio.h>
#include <string.h>

int main (void)
{
    int N;
    scanf("%d", &N);
    char *word [20000][50];
    int tmp;

    for(int i = 0; i<N; i++)
    {
        scanf("%s", &word[i]);
        
        //단어 수대로 정리 한 후에

        if(strlen(word[i]) == strlen(word[i+1]))
        {
            if(strcmp(word[i], word[i+1]) > 0)
                tmp = i;
                i = i+1;
                i+1 = tmp;
        }
    }
}