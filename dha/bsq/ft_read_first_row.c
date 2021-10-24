/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_first_row.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 10:56:38 by dha               #+#    #+#             */
/*   Updated: 2021/10/24 13:36:36 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_read_first_row(int fd, t_map *map)
{
	int		i;
	char	c;

	i = 0;
	map->grid[0] = (char *) malloc(sizeof(char) * 16);
	map->col = 16;
	while (1)
	{
		read(fd, &c, 1);
		if (c == '\n')
			break ;
		if (c != map->empty && c != map->obstacle) // C가 NULL 또는 non printable 이면?
			return (0);
		grid[0][i] = c;
		i++;
		if (i == map->col)
		{
			// realloc
		}
	}
	return (i);
}