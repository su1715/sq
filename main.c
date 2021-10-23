#include <unistd.h>
#include <fcntl.h>
#include "map_admin.h"

void	ft_error();
int	ft_read_file(int fd, map_info *map);

int	main(int argc, char *argv[])
{
	int			i;
	int 		fd;
	map_info	*map;

	i = 1;
	map = (map_info	*)malloc(sizeof(map_info));
	if (argc == 1)
	{
		//read by STDIN_FILENO
	}
	else if (argc >= 2)
	{
		while (i < argc)
		{
			if ( 0 > (fd = open(argv[i++], O_RDONLY)))
				ft_error();
			ft_read_file(fd, map);
			close(fd);
			//dynamic programming
			//print
		}
	}
	else
		ft_error();
	return (0);
}

int	ft_get_first_line(int fd, map_info *map)
{
	char	buf[14]; //line 10 (int) + char 3 + \n;
	int		i;

	i = 0;
	while (1)
	{
		read(fd, buf[i], 1);
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

int	ft_read_file(int fd, map_info *map)
{
	int	i;

	i = 0;
	if (!ft_get_first_line(fd, map))
		return (0);
	map->grid = (int **)malloc(sizeof(int *) * map->row);
	//첫째줄 정보에 따라 라인수만큼 읽기
	//읽을 때마다 malloc해서 저장
	while (i < map->row)
	{
		
		i++;
	}
	return (1);
}

void	ft_error()
{
	write(STDERR_FILENO, "map error\n", 10);
}

int is_overlap(char empty, char obs, char fill)
{
	if (empty == obs)
		return (1);
	if (empty == fill)
		return (1);
	if (obs == fill)
		return (1);
	return (0);
}