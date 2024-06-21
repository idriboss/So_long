/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 06:30:03 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/21 19:14:08 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_map(t_data *data, char *map_path)
{
	char *_map;
	char **splited_map;

	_map = map(map_path, data);
	splited_map = ft_split(_map, '\n');
	if (splited_map == NULL)
		free_and_exit(MALLOC_FAILED, EXIT_FAILURE, data, false);
	check_map(splited_map, data);
	free_2d_array((void ***)&splited_map);
	data->map = ft_split(_map, '\n');
}

char	*map(const char *map_file, t_data *data)
{
	char	*gnl_map;
	char	*buff;
	int	fd;

	if (ft_strlen(map_file) <= 4 || ft_strcmp(&map_file[ft_strlen(map_file) - 4], ".ber") != 0)
		free_and_exit("map file is not '.ber'", MAP_ERROR, data, false);
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		free_and_exit(OPEN_FAIlED, EXIT_FAILURE, data, false);
	gnl_map = get_next_line(fd);
	buff = ft_strdup("");
	if (buff == NULL)
		free_and_exit(MALLOC_FAILED, EXIT_FAILURE, data, false);
	while (gnl_map != NULL)
	{
		buff = ft_re_strjoin(buff, gnl_map);
		ft_free((void **)&gnl_map);
		if (!buff)
			free_and_exit(MALLOC_FAILED, EXIT_FAILURE, data, false);
		gnl_map = get_next_line(fd);
	}
	if (buff == NULL)
		free_and_exit("Map incorrect", MAP_ERROR, data, false);
	return (buff);
}

