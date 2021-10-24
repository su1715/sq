/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:10:03 by dha               #+#    #+#             */
/*   Updated: 2021/10/24 14:25:36 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

int     allocate_memo(t_map *map, int ***memo_sq);
void	memoization(t_map *map, int ***memo_sq);
void	find_square(t_map *map, int ***memo);
void	update_by_memo(t_map *map, int ***memo);

int	dynamic_programming(t_map *map)
{
	int	**memo;

	if (!allocate_memo(map, &memo))
		return (0);
	memoization(map, &memo);
	find_square(map, &memo);
	update_by_memo(map, &memo);
	free_memo(map, &memo);
	return (1);
}

void	find_square(t_map *map, int ***memo)
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

void	update_by_memo(t_map *map, int ***memo)
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

int	allocate_memo(t_map *map, int ***memo)
{	
	int	i;
	int	j;

	i = 0;
	j = 0;
	*memo = (int **)malloc(map->row * sizeof(int *));
	while (i < map->row)
	{
		(*memo)[i] = (int *)malloc(map->col * sizeof(int));
		while (j < map->col)
		{
			if (map->grid[i][j] == map->empty)
				(*memo)[i][j] = 1;
			else if (map->grid[i][j] == map->obstacle)
				(*memo)[i][j] = 0;
			else
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	memoization(t_map *map, int ***memo)
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