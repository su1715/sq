/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 20:17:55 by dha               #+#    #+#             */
/*   Updated: 2021/10/26 21:01:15 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

int	main(int argc, char **argv)
{
	int		i;
	t_map	*map;

	i = 1;
	if (argc == 1)
	{
		map = (t_map *) malloc(sizeof(t_map));
		if (!input(0, map))
			ft_exit(map);
		else
			dynamic_programming(map);
		return (0);
	}
	while (i < argc)
	{
		map = (t_map *) malloc(sizeof(t_map));
		if (!input(argv[i], map))
			ft_exit(map);
		else
			dynamic_programming(map);
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
}
