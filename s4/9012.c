#include <stdio.h>
#include <string.h>

int main (void)
{
    int T;
    scanf("%d", &T);
    char str[50];
    for(int i=0; i<T; i++)
    {
        int cnt = 0;
        scanf("%s", str);
        for(int j=0; j<strlen(str); j++)
        {
            if(cnt<0)
                break;
            if(str[j]=='(')
                cnt++;
            else if (str[j]==')')
                cnt--;
        }

        if(cnt == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}