/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_first_row.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 10:56:38 by dha               #+#    #+#             */
/*   Updated: 2021/10/26 16:16:36 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

int	ft_read_first_row(int fd, t_map *map)
{
	int		i;
	char	c;

	i = 0;
	map->grid[0] = (unsigned char *) malloc(sizeof(unsigned char) * 32);
	map->col = 32;
	while (1)
	{
		if (i == map->col)
		{
			map->grid[0] = str_realloc(map->grid[0], map->col, map->col * 2);
			map->col *= 2;
		}
		if (read(fd, &c, 1) < 1)
			return (0);
		if (c == '\n')
			break ;
		if (c != map->empty && c != map->obstacle)
			return (0);
		map->grid[0][i] = c;
		i++;
	}
	map->grid[0] = str_realloc(map->grid[0], map->col, i);
	map->col = i;
	return (i);
}
