/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:22:34 by dha               #+#    #+#             */
/*   Updated: 2021/10/26 18:58:38 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

int	ft_read_grid(int fd, t_map *map)
{
	int		i;
	int		cnt;
	char	c;

	i = 1;
	while (i < map->row)
	{
		map->grid[i] = malloc(sizeof(int) * map->col);
		cnt = 0;
		while (cnt < map->col)
		{
			read(fd, &c, 1);
			if (c == map->empty)
				map->grid[i][cnt] = 1;
			else if (c == map->obstacle)
				map->grid[i][cnt] = 0;
			else
			{
				map->row = i + 1;
				return (0);
			}
			cnt++;
		}
		read(fd, &c, 1);
		if (c != '\n')
		{
			map->row = i + 1;
			return (0);
		}
		i++;
	}
	return (1);
}
