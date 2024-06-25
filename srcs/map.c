/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 06:30:03 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/25 16:09:09 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_player(t_data *data)
{
	char	**map;
	int		x;
	int		y;

	map = data->map;
	y = 1;
	while (map[y + 1])
	{
		x = 1;
		while (map[y][x + 1])
		{
			if (map[y][x] == PLAYER)
			{
				data->player_x = x;
				data->player_y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

void	init_map(t_data *data, char *map_path)
{
	char	*_map;
	char	**splited_map;

	_map = map(map_path, data);
	if (ft_strnstr(_map, "\n\n", ft_strlen(_map)) != NULL)
		free_and_exit("invalid map", EXIT_FAILURE, data);
	splited_map = ft_split(_map, '\n');
	if (splited_map == NULL)
		free_and_exit(MALLOC_FAILED, EXIT_FAILURE, data);
	check_map(splited_map, data, &_map, &splited_map);
	free_2d_array((void ***)&splited_map);
	data->map = ft_split(_map, '\n');
	if (data->map == NULL)
		free_and_exit(MALLOC_FAILED, EXIT_FAILURE, data);
	ft_free((void **)&_map);
}

char	*map(const char *map_file, t_data *data)
{
	char	*gnl_map;
	char	*buff;
	int		fd;

	if (ft_strlen(map_file) <= 4 || ft_strcmp(&map_file[ft_strlen(map_file)
			- 4], ".ber") != 0)
		free_and_exit("map file is not '.ber'", MAP_ERROR, data);
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		free_and_exit(OPEN_FAIlED, EXIT_FAILURE, data);
	gnl_map = get_next_line(fd);
	if (gnl_map == NULL)
	{
		close(fd);
		free_and_exit(MALLOC_FAILED, EXIT_FAILURE, data);
	}
	buff = ft_strdup("");
	if (buff == NULL)
	{
		close(fd);
		free_and_exit(MALLOC_FAILED, EXIT_FAILURE, data);
	}
	while (gnl_map != NULL)
	{
		buff = ft_re_strjoin(buff, gnl_map);
		ft_free((void **)&gnl_map);
		if (!buff)
		{
			close(fd);
			free_and_exit(MALLOC_FAILED, EXIT_FAILURE, data);
		}
		gnl_map = get_next_line(fd);
	}
	if (buff == NULL)
		free_and_exit("Failed opening the map", MAP_ERROR, data);
	close(fd);
	return (buff);
}
