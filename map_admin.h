#ifndef MAP_ADMIN_H
# define MAP_ADMIN_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map {
	int	**grid;
	int	col;
	int	row;
	char empty;
	char obstacle;
	char fill;
	int sq_y;
	int sq_x;
	int sq_size;
} t_map;


int ft_min(int left, int up, int left_up);
int is_overlap(char empty, char obs, char fill);
void	free_memo(map_info *map, int ***memo);
int	dynamic_programming(map_info *map);
#endif