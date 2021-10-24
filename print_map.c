#include "bsq_lib.h"

void	print_map(t_map *map)
{
	int		i;
	int		j;
	unsigned char	**grid;

	i = 0;
	grid = map->grid;

	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			write(1, &grid[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
