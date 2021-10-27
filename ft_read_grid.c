/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:22:34 by dha               #+#    #+#             */
/*   Updated: 2021/10/28 02:37:48 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

int	invalid_grid(t_map *map, int i)
{
	map->row = i + 1;
	return (0);
}

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
			if (read(fd, &c, 1) < 1)
				return (invalid_grid(map, i));
			if (!put_each(map, i, cnt, c))
				return (invalid_grid(map, i));
			cnt++;
		}
		if (read(fd, &c, 1) < 1 || c != '\n')
			return (invalid_grid(map, i));
		i++;
	}
	if (read(fd, &c, 1))
		return (0);
	return (1);
}
