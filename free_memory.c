#include "map_admin.h"

void	free_memo(t_map *map, int ***memo)
{
	int	i;

	i = 0;
	while (i < map->row)
	{
		free((*memo)[i]);
		i++;
	}
	free(*memo);
}