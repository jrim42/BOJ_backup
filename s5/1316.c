#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check (char *word)
{
    int flag = 1;
    for(int i=0; i<strlen(word)-1; i++)
    {
        if(word[i] != word[i+1])
        {
            for(int j=0; j<i+1; j++)
                if(word[i+1] == word[j])
                    flag = 0;
        }
    }
    return flag;
}

int main (void)
{
    int N;
    int  cnt=0;
    scanf("%d", &N);
    char *word = malloc(101*sizeof(char));
    
    for(int i=0; i<N; i++)
    {
        scanf("%s", word);
        if(check(word) == 1)
            cnt++;
    }

    printf("%d\n", cnt);
    free(word);
    return 0;
}