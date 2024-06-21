#include "../../includes/so_long.h"

int	extend(char **map, int x, int y)
{
	int count;

	count = 0;
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'P')
	{
		count++;
		map[y + 1][x] = 'P';
	}
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'P')
	{
		count++;
		map[y - 1][x] = 'P';
	}
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'P')
	{
		count++;
		map[y][x + 1] = 'P';
	}
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'P')
	{
		count++;
		map[y][x - 1] = 'P';
	}
	return (count);
}

void	extend_blob(char **map)
{
	int	x;
	int y;
	int count;

	while (1)
	{
		y = 0;
		count = 0;
		while (map[y])
		{	
			x = 0;
			while (map[y][x])
			{
				if (map[y][x] == 'P')
					count += extend(map, x, y);
				x++;
			}
			y++;
		}
		if (count == 0)
			break ;
	}
}

void	check_map_ways(char **map, t_data *data)
{
	int	y;

	y = 0;
	(void)data;
	extend_blob(map);
	while (map[y])
	{
		if (ft_strchr(map[y], 'C') != NULL || ft_strchr(map[y], 'E'))
			free_and_exit("map not playable", MAP_ERROR, data, false);
		y++;
	}
}