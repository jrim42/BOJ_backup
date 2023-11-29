#include <stdio.h>

int    sudoku[10][10];

void    solve_sudoku(int col, int row, int *flag);
int     check_row(int row);
int     check_col(int col);
int     check_square(int row, int col);

int main(void)
{
    int flag[10];

    for (int i = 0; i < 10; i++)
        flag[i] = 0;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            scanf(" %d", &sudoku[i][j]);
    solve_sudoku(0, 0, flag);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            printf("%d ", sudoku[i][j]);
        printf("\n");
    }
    return (0);
}

void    solve_sudoku(int col, int row, int *flag)
{
    if (row == 9)
        return ;
    else
    {
        if (col == 9)
        {
            for (int i = 0; i < 9; i++)
                flag[sudoku[row][i]] = 0;
            solve_sudoku(0, row + 1, flag);
        }
        else if (sudoku[row][col] != 0)
        {
            flag[sudoku[row][col]] = 1;
            solve_sudoku(col + 1, row, flag);
        }
        else if (sudoku[row][col] == 0)
        {  
            for (int num = 1; num <= 9; num++)
            {
                if (flag[num] == 0)
                {
                    sudoku[row][col] = num;
                    flag[num] = 1;
                    solve_sudoku(col + 1, row, flag);
                    flag[num] = 0;
                } 
            }
        }
    } 
}

int check_col(int col)
{
    int num[10];
    int idx;

    for (int i = 0; i < 10; i++)
        num[i] = 0;
    for (int i = 0; i < 9; i++)
    {
        idx = sudoku[i][col];
        if (num[idx] == 0)
            num[idx] = 1;
        else if (idx != 0 && num[idx] == 1)
            return (0);
    }
    return (1);
}

/*
int check_square(int row, int col)
{
    int     row_pos;
    int     col_pos;
    int     idx;
    char    num[10];

    row_pos = row / 3;
    col_pos = col / 3;
    for (int i = 0; i < 10; i++)
        num[i] = '0';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            idx = sudoku[row_pos * 3 + i][col_pos * 3 + j] - '0';
            if (idx != 0 && num[idx] == '0')
                num[idx] = '1';
            else if (idx != 0 && num[idx] == '1')
                return (0);
        }
    return (1);
}
*/