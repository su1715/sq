/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_first_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 10:40:35 by dha               #+#    #+#             */
/*   Updated: 2021/10/24 14:37:08 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"
int	ft_read_first_line(int fd, t_map *map)
{
	char	buf[14];
	int		i;

	i = 0;
	while (1) // 13번 인덱스까지만 확인(?)
	{
		if (i > 13)
			return (0);
		read(fd, buf + i, 1);
		if (buf[i] == '\n')
		{
			map->empty = buf[i - 3];
			map->obstacle = buf[i - 2];
			map->fill = buf[i - 1];
			if (is_overlap(map->empty, map->obstacle, map->fill))
				return (0);
			buf[i - 3] = '\0';
			map->row = ft_atoi(buf);
			break ;
		}
		i++;
	}
	return (1);
}
