#include <stdio.h>
#include <string.h>

int main (void)
{
    char str[100];
    while(1)
    {
        scanf("%[^\n]s", str);

        if (strcmp(str, ".") == 0) 
            break;
        
        int cnt1 = 0;
        int cnt2 = 0;

        for(int j=0; str[j] == '.'; j++)
        {
            if(str[j]=='(')
                cnt1++;
            else if (str[j]==')')
                cnt1--;

            if(str[j]=='[')
                cnt2++;
            else if (str[j]==']')
                cnt2--;
        }

        if(cnt1 == 0 && cnt2 == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}