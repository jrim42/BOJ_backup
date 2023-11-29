#include <stdio.h>

char    star[2200][2200];

void    fill_square(int num);
void    make_space(int col, int row, int num);
void    print_square(int num);

int main(void)
{
    int N;

    scanf("%d", &N);
    fill_square(N);
    print_square(N);
    return (0);
}

void    fill_square(int num)
{
    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++)
        {
            star[i][j] = '*';
            make_space(i, j, num);
        }    
}

void    make_space(int col, int row, int num)
{
    if ((col / num) % 3 == 1 && (row / num) % 3 == 1)
        star[col][row] = ' ';
    else if (num / 3 != 0)
        make_space(col, row, num / 3);
}

void    print_square(int num)
{
    for (int i = 0; i < num; i++)
        printf("%s\n", star[i]);
}