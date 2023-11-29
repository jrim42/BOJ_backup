#include <stdio.h>
#include <string.h>

char stack[101];
int top = -1;

void push (char c)
{

}

void pop (void)
{

}



void checkBalance (char *str, int len)
{
    for(int i=0; i<len; i++)
    {
        if(str[i]=='(' || str[i]=='[')
            push(Stack, createNode(&str[i]));
        else if (str[i]==')' || str[i]==']')
            pop(Stack);
    }
    if(Stack->size == 0)
        printf("yes\n");
    else
        printf("no\n");
}

int main (void)
{
    char str[101];
    while(1)
    {
        scanf("%[^\n]s", str);
        if (strcmp(str, ".") == 0) 
            break;
        checkBalance(str, strlen(str));
    }
    return 0;
}