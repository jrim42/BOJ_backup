#include <stdio.h>
#include <string.h>

int arr[20] = {0};

void    add(int num);
void    remove_num(int num);
void    check(int num);
void    toggle(int num);
void    all(void);
void    empty(void);

int main (void)
{
    int N;
    int num;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        char cmd[7];
        scanf("%s", cmd);
        if(strcmp(cmd, "add") == 0)
        {
            scanf("%d", &num);
            add(num);
        }
        else if (strcmp(cmd, "remove") == 0)
        {
            scanf("%d", &num);
            remove_num(num);
        }
        else if (strcmp(cmd, "check") == 0)
        {
            scanf("%d", &num);
            check(num);
        } 
        else if (strcmp(cmd, "toggle") == 0)
        {
            scanf("%d", &num);
            toggle(num);
        } 
        else if (strcmp(cmd, "all") == 0)
            all();
        else if (strcmp(cmd, "empty") == 0)
            empty();
    }
    return 0;
}

void    add(int num)
{
    if (arr[num - 1] == 0)
        arr[num - 1] = num;
}

void    remove_num(int num)
{
    if (arr[num - 1] != 0)
        arr[num - 1] = 0;
}

void     check(int num)
{
    if (arr[num - 1] == num)
        printf("1\n");
    else
        printf("0\n");       
}

void    toggle(int num)
{
    if (arr[num - 1] == 0)
        arr[num - 1] = num;
    else if (arr[num - 1] != 0)
        arr[num - 1] = 0;
}

void    all(void)
{
    for (int i = 0; i < 20 ; i++)
        arr[i] = i + 1;
}

void    empty(void)
{
    for (int i = 0; i < 20 ; i++)
        arr[i] = 0;
}