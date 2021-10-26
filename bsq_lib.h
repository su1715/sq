/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_lib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 23:00:38 by dha               #+#    #+#             */
/*   Updated: 2021/10/27 00:54:41 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_LIB_H
# define BSQ_LIB_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "util.h"

typedef struct s_map {
	int		**grid;
	int		row;
	int		col;
	char	empty;
	char	obstacle;
	char	fill;
	int		sq_y;
	int		sq_x;
	int		sq_size;
}	t_map;

int		input(char *filename, t_map *map);
int		dynamic_programming(t_map *map);
int		ft_read_first_line(int fd, t_map *map);
int		ft_read_first_row(int fd, t_map *map);
int		ft_read_grid(int fd, t_map *map);
int		free_grid(t_map *map, int size);
int		put_each(t_map *map, int x, int y, char c);
void	ft_exit(t_map *map);
void	print_map(t_map *map);
void	free_memo(t_map *map, int ***memo);

#endif