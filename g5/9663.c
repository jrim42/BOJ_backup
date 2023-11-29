#include <stdio.h>

static int	g_cnt;

void	set_queen(int row, int *flag, char *queen, int limit);
int		check_dia(char *queen, int row, int col, int limit);

int	main(void)
{
	int		flag[15];
	char	queen[15];
    int     N;

    scanf("%d", &N);
	for (int i = 0; i < 15; i++)
	{
		flag[i] = 0;
		queen[i] = '0';
	}
	set_queen(0, flag, queen, N);
	printf("%d\n", g_cnt);
    return (0);
}

void	set_queen(int row, int *flag, char *queen, int limit)
{
	int	col;

	col = 0;
	if (row == limit)
	{
		g_cnt++;
		return ;
	}
	while (col < limit)
	{
		if (flag[col] != 1)
		{
			queen[row] = col + '0';
			if (check_dia(queen, row, col, limit) == 1)
			{
				flag[col] = 1;
				set_queen(row + 1, flag, queen, limit);
				flag[col] = 0;
			}
		}
		col++;
	}
}

int	check_dia(char *queen, int row, int col, int limit)
{
	int	i;

	i = 1;
	while (row - i >= 0 && col - i >= 0)
	{
		if (queen[row - i] == col - i + '0')
			return (0);
		i++;
	}
	i = 1;
	while (col + i <= limit - 1)
	{
		if (queen[row - i] == col + i + '0')
			return (0);
		i++;
	}
	return (1);
}