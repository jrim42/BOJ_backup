#include <stdio.h>
#include <stdlib.h>

void    find_square(int *num_map, int n, int m);
int     search_min(int row, int col, int *num_map, int m);
int     search_max(int *num_map, int n, int m);

int main(void)
{
    int n;
    int m;
    int *map;

    scanf("%d %d", &n, &m);
    map = (int *)malloc(n * m * sizeof(int));
    if (map == NULL)
        return (-1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%1d", &map[i * m + j]);
    find_square(map, n, m);
    free(map);
    return (0);
}

void	find_square(int *num_map, int n, int m)
{
	int	row;
	int	col;
	int	max_val;

	row = 1;
	while (row < n)
	{
		col = 1;
		while (col < m)
		{
			if (num_map[row * m + col] != 0)
				num_map[row * m + col] = search_min(row, col, num_map, m) + 1;
			col++;
		}
		row++;
	}
	max_val = search_max(num_map, n, m);
    printf("%d\n", max_val * max_val);
}

int	search_min(int row, int col, int *num_map, int m)
{
	int	min;
	int	left_dia;
	int	up;
	int	left;

	min = 9999999;
	left_dia = num_map[((row - 1) * m) + (col - 1)];
	up = num_map[((row - 1) * m) + col];
	left = num_map[row * m + (col - 1)];
	if (left_dia < min)
		min = left_dia;
	if (up < min)
		min = up;
	if (left < min)
		min = left;
	return (min);
}

int	search_max(int *num_map, int n, int m)
{
	int	i;
	int	max_val;

	i = 0;
	max_val = 0;
	while (i < n * m)
	{
		if (num_map[i] > max_val)
			max_val = num_map[i];
		i++;
	}
	return (max_val);
}