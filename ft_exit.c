/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:00:46 by dha               #+#    #+#             */
/*   Updated: 2021/10/28 02:30:56 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

void	ft_exit(t_map *map)
{
	free(map);
	ft_error();
}

int	free_grid(t_map *map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	return (0);
}
