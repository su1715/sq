#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "map_admin.h"

void	ft_error();
int	ft_read_file(int fd, t_map *map);
int ft_atoi(char *str);

int	main(int argc, char *argv[])
{
	int			i;
	int 		fd;
	t_map	*map;

	i = 1;
	map = (t_map	*)malloc(sizeof(t_map));
	if (argc == 1)
	{
		//read by STDIN_FILENO
	}
	else if (argc >= 2)
	{
		while (i < argc)
		{
			if ( 0 > (fd = open(argv[i++], O_RDONLY)))
			{
				ft_error();
				continue;
			}
			if (ft_read_file(fd, map))
			{
				ft_error();
				continue;
			}
			close(fd);
			dynamic_programming(map);
			//print
		}
	}
	else
		ft_error();
	return (0);
}

int	ft_read_first_line(int fd, t_map *map)
{
	char	buf[14]; //line 10 (int) + char 3 + \n;
	int		i;

	i = 0;
	while (1)
	{
		if (i > 13)
			return (0);
		read(fd, &buf[i], 1);
		if (buf[i] == '\n')
		{
			map->empty = buf[i - 3];
			map->obstacle = buf[i - 2];
			map->fill = buf[i - 1];
			if (is_overlap(map->empty, map->obstacle, map->fill))
				return (0);
			buf[i - 3] = '\0';
			map->row = ft_atoi(buf);
			break;
		}
		i++;
	}
	return (1);
}

int ft_atoi(char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		result = result * 10 + (*str);
		str++;
	}
	return (result);
}

void	ft_read_first_row(int fd, t_map *map)
{
	int		len;
	char	c;

	len = 0;
	while (1)
	{
		read(fd, &c, 1);
		if (c == 0 || c == '\n')
			break;
		len++;
	}
	map->col = len;
}

int ft_read_line(int fd, t_map *map, int i)
{
	int		j;
	char	c;
	
	j = 0;
	map->grid[i] = (int *)malloc(sizeof(int) * map->row);
	while(j < map->row)
	{
		read(fd, &c, 1);
		if (c != map->empty && c != map->obstacle)
			return (0);
		if (c == map->empty)
			map->grid[i][j] = 1;
		else
			map->grid[i][j] = 0;
		j++;
	}
	if (c != '\n')
		return (0);
	else
		return (1);
}

int	ft_read_file(int fd, t_map *map)
{
	int	i;

	i = 0;
	if (!ft_read_first_line(fd, map))
		return (0);
	map->grid = (int **)malloc(sizeof(int *) * map->row);
	ft_read_first_row(fd, map);
	while (i < map->row)
	{
		if(!ft_read_line(fd, map, i))
			return (0);
		i++;
	}
	return (1);
}

void	ft_error()
{
	write(STDERR_FILENO, "map error\n", 10);
}