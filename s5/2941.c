#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int croatian (char *w)
{
    int cnt = 0;
    for(int i=0; i<101; i++)
    {
        if(w[i] == 'c')
        {
            if(w[i+1] == '=' || w[i+1] == '-')
            {
                cnt++;
                i++;
            }
            else
            {
                cnt++;
            }            
        }
        else if(w[i] == 'd')
        {
            if(w[i+1] == 'z' && w[i+2] == '=')
            {
                cnt++;
                i += 2;
            }
            else if (w[i+1] == '-')
            {
                cnt++;
                i++;
            } 
            else
            {
                cnt++;
            }
        }
        else if (w[i] == 'l' || w[i] == 'n')
        {
            if(w[i+1] == 'j')
            {
                cnt++;
                i++;
            }
            else
            {
                cnt++;
            }  
        }  
        else if (w[i] == 's' || w[i] == 'z')
        {
            if(w[i+1] == '=')
            {
                cnt++;
                i++;
            }
            else
            {
                cnt++;
            } 
        } 
        else if(w[i] != '=' && w[i] != '-' && w[i] != 0)
        {
            cnt++;
        } 
    }
    return cnt;
}

int main (void)
{
    char *word = calloc(103, sizeof(char));
    scanf("%s", word);
    printf("%d\n", croatian(word));
    free(word);
    return 0;
}