/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:10:03 by dha               #+#    #+#             */
/*   Updated: 2021/10/26 19:00:20 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

void	memoization(t_map *map);
void	find_square(t_map *map);
void	update_by_memo(t_map *map);

int	dynamic_programming(t_map *map)
{
	int	**memo;

	memoization(map);
	find_square(map);
	update_by_memo(map);
	print_map(map);
	return (1);
}

void	memoization(t_map *map)
{
	int	i;
	int	j;
	int	**grid;

	i = 1;
	grid = map->grid;
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

void	find_square(t_map *map)
{
	int	i;
	int	j;
	int	max;
	int	**grid;

	i = 0;
	map->sq_size = 0;
	grid = map->grid;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
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

int	is_square(t_map *map, int i, int j)
{
	int	y;
	int	x;
	int	size;

	y = map->sq_y;
	x = map->sq_x;
	size = map->sq_size;
	if (y - size < i && i <= y)
		if (x - size < j && j <= x)
			return (1);
	return (0);
}

void	update_by_memo(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			if (is_square(map, i, j))
				map->grid[i][j] = 2; //square 인 경우 2로 표시
			else if (map->grid[i][j] != 0)
			{
				map->grid[i][j] = 1;
			}
			j++;
		}
		i++;
	}
}
