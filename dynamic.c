#include "map_admin.h"
#include <stdlib.h>

int	allocate_memo(map_info *map, int ***memo_sq);
void	memoization(map_info *map, int ***memo_sq);
int ft_min(int left, int up, int left_up);

int	dynamic_programming(map_info *map)
{
	int	**memo;

	if (!allocate_memo(map, &memo))
		return (0);
	memoization(map, &memo);
	find_square(map, &memo);
	update_by_memo(map, &memo);
	free_memo(&memo);
	return (1);
}

void	find_square(map_info *map, int ***memo)
{
	int	i;
	int	j;
	int	max;
	int **grid;

	i = 0;
	map->sq_size = 0;
	grid = *memo;
	while (i < map->col)
	{
		j = 0;
		while (j < map->row)
		{
			if (map->sq_size < grid[i][j])
			{
				map->sq_size = grid[i][j];
				map->sq_y = i;
				map->sq_x = j;
			}
			j++;
		}
		i++;
	}
}

void	update_by_memo(map_info *map, int ***memo)
{
	int	i;
	int	j;
	int x;
	int y;

	i = 1;
	j = 1;
	y = map->sq_y;
	x = map->sq_x;
	while (i < map->sq_size)
	{
		while (j < map->sq_size)
		{
			(*memo)[y - i][x - j] = map->fill;
			j++; 
		}
		i++;
	}
}

int	allocate_memo(map_info *map, int ***memo)
{	
	int	i;
	int	j;

	i = 0;
	j = 0;
	*memo = (int **)malloc(map->row * sizeof(int *));
	while (i < map->row)
	{
		(*memo)[i] = (int *)malloc(map->col *sizeof(int));
		while (j < map->col)
		{
			if (map->grid[i][j] == map->empty)
				memo[i][j] = 1;
			else if (map->grid[i][j] == map->obstacle)
				memo[i][j] = 0;
			else
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	memoization(map_info *map, int ***memo)
{
	int	i;
	int	j;
	int	**grid;

	i = 1;
	grid = *memo;
	while (i < map->row)
	{
		j = 1;
		while (j < map->col)
		{
			if (grid[i][j])
				grid[i][j] = ft_min(grid[i - 1][j], grid[i][j - 1], \
					grid[i - 1][j - 1]) + 1;
			j++;
		}
		i++;
	}
}