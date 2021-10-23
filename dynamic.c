#include "map_admin.h"

int	allocate_memo(map_info *map, int ***memo_sq);
void	memoization(map_info *map, int ***memo_sq);
int ft_min(int left, int up, int left_up);

int	dynamic_programming(map_info *map)
{
	int	**memo_sq;

	if (!allocate_memo(map, &memo_sq))
		return (0);
	memoization(map, &memo_sq);
	update_by_memo();
	return (1);
}

int	allocate_memo(map_info *map, int ***memo_sq)
{	
	int	i;
	int	j;

	i = 0;
	j = 0;
	*memo_sq = (int **)malloc(map->row * sizeof(int *));
	while (i < map->row)
	{
		(*memo_sq)[i] = (int *)malloc(map->col *sizeof(int));
		while (j < map->col)
		{
			if (map->grid[i][j] == map->empty)
				memo_sq[i][j] = 1;
			else if (map->grid[i][j] == map->obstacle)
				memo_sq[i][j] = 0;
			else
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	memoization(map_info *map, int ***memo_sq)
{
	int	i;
	int	j;
	int	**memo;

	i = 1;
	memo = *memo_sq;
	while (i < map->row)
	{
		j = 1;
		while (j < map->col)
		{
			memo[i][j] = ft_min(memo[i - 1][j], memo[i][j - 1], \
				memo[i - 1][j - 1]) + 1;
			j++;
		}
		i++;
	}
}

int ft_min(int left, int up, int left_up)
{
	int	min;
	
	min = 2147483647;
	if (left < min)
		min = left;
	if (up < min)
		min = up;
	if (left_up < min)
		min = left_up;
	return (min);
}