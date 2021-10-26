/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:50:32 by dha               #+#    #+#             */
/*   Updated: 2021/10/26 18:59:08 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

void	print_map(t_map *map)
{
	int	i;
	int	j;
	int	**grid;

	i = 0;
	grid = map->grid;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			if (grid[i][j] == 0)
				write(1, &map->obstacle, 1);
			else if (grid[i][j] == 1)
				write(1, &map->empty, 1);
			else //2 인경우로 가정,,,, 012 아닌경우도 해야하나?
				write(1, &map->fill, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
