/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 23:06:13 by dha               #+#    #+#             */
/*   Updated: 2021/10/24 10:54:55 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	input(char *filename, t_map *map)
{
	int		fd;
	t_map	*map;

	if (filename == 0)
		fd = 0;
	else
		fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	map = (t_map *) malloc(sizeof(t_map));
	close(fd);
	if (!ft_read_first_line(fd, map))
		return (0);
	if (!ft_read_first_row(fd, map))
		return (0);
	if (!ft_read_grid(fd, map))
		return (0);
}
