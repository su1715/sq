/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:22:34 by dha               #+#    #+#             */
/*   Updated: 2021/10/24 19:13:16 by dha              ###   ########.fr       */
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
		map->grid[i] = (unsigned char *) malloc(sizeof(unsigned char) * map->col);
		cnt = 0;
		while (cnt < map->col)
		{
			read(fd, &c, 1);
			if (c != map->empty && c != map->obstacle)
				return (0);
			map->grid[i][cnt] = c;
			cnt++;
		}
		read(fd, &c, 1);
		if (c != '\n')
			return (0);
		i++;
	}
	return (1);
}
