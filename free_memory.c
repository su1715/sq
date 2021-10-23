#include "map_admin.h"

void	free_memo(map_info *map, int ***memo)
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