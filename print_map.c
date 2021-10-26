/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:50:32 by dha               #+#    #+#             */
/*   Updated: 2021/10/24 19:51:02 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

void	print_map(t_map *map)
{
	int				i;
	int				j;
	unsigned char	**grid;

	i = 0;
	grid = map->grid;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			write(1, &grid[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
