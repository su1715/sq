/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_first_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 10:40:35 by dha               #+#    #+#             */
/*   Updated: 2021/10/27 01:40:04 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

void	get_map_char(t_map *map, char *buf, int i)
{
	map->empty = buf[i - 3];
	map->obstacle = buf[i - 2];
	map->fill = buf[i - 1];
}

int	ft_read_first_line(int fd, t_map *map)
{
	char	buf[14];
	int		i;

	i = 0;
	while (1)
	{
		if (i > 13 || read(fd, buf + i, 1) < 1)
			return (0);
		if (buf[i] == '\n')
		{
			if (i < 4)
				return (0);
			get_map_char(map, buf, i);
			if (is_overlap(map->empty, map->obstacle, map->fill))
				return (0);
			buf[i - 3] = '\0';
			map->row = ft_atoi(buf);
			if (map->row < 1)
				return (0);
			break ;
		}
		i++;
	}
	return (1);
}
