/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 23:06:13 by dha               #+#    #+#             */
/*   Updated: 2021/10/26 18:55:38 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

int	input(char *filename, t_map *map)
{
	int		fd;

	if (filename == 0)
		fd = 0;
	else
		fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!ft_read_first_line(fd, map))
		return (0);
	map->grid = (int **) malloc(sizeof(int *) * map->row);
	if (!ft_read_first_row(fd, map))
		return (free_grid(map, 1));
	if (!ft_read_grid(fd, map))
		return (free_grid(map, map->row));
	close(fd);
	return (1);
}
