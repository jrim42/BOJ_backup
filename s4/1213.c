#include <stdio.h>
#include <string.h>

int main (void)
{
    char name[51];
    int arr[26] = {0};
    scanf("%s", name);

    int idx, cnt = 0;
    for(int i=0; i<26; i++)
    {
        for(int j=0; j<strlen(name); j++)
            if(name[j]-65 == i)
                arr[i]++;

        if(arr[i] % 2 != 0)
        {
            cnt++;
            idx = i;
        }
    }

    if(cnt > 1)
    {
        printf("I'm Sorry Hansoo");
    }
    else
    {
        for(int i=0; i<26; i++)
        {
            if(arr[i]!=0)
                for(int j=1; j<=arr[i]/2; j++)
                    printf("%c", i+65);
        }

        if(cnt == 1)
            printf("%c", idx+65);

        for(int i=25; i>=0; i--)
        {
            if(arr[i]!=0)
                for(int j=1; j<=arr[i]/2; j++)
                    printf("%c", i+65);
        }
    }

    printf("\n");
    return 0;
}