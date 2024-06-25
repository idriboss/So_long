/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 01:54:05 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/25 16:37:54 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_map_edge(char **map)
{
	int	x;
	int	y;
	int	length;

	y = 0;
	length = -1;
	while (map[y][++length])
		if (map[y][length] != WALL)
			return (EXIT_FAILURE);
	while (map[++y] != NULL)
	{
		x = ft_strlen(map[y]);
		if (x != length)
			return (EXIT_FAILURE);
		if (map[y][0] != WALL || map[y][x - 1] != WALL)
			return (EXIT_FAILURE);
	}
	x = -1;
	while (map[y - 1][++x])
	{
		if (map[y - 1][x] != WALL)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	check_map_content(char **map, t_data *data)
{
	int	x;
	int	y;
	int	player;
	int	exit;

	free((player = 0, exit = 0, NULL));
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == PLAYER)
				++player;
			if (map[y][x] == EXIT)
				++exit;
			if (map[y][x] == COLLECT)
				data->collectible_count += 1;
			if (ft_strchr("10MECP", map[y][x]) == NULL)
				return (EXIT_FAILURE);
		}
	}
	if (player != 1 || exit != 1 || data->collectible_count < 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	check_map(char **map, t_data *data, char **to_free, char ***to_free2d)
{
	if (check_map_edge(map) == EXIT_FAILURE)
	{
		ft_free((void **)to_free);
		free_2d_array((void ***)to_free2d);
		free_and_exit("map invalid", EXIT_FAILURE, data);
	}
	if (check_map_content(map, data) == EXIT_FAILURE)
	{
		ft_free((void **)to_free);
		free_2d_array((void ***)to_free2d);
		free_and_exit("map invalid", EXIT_FAILURE, data);
	}
	if (check_map_ways(map) == EXIT_FAILURE)
	{
		ft_free((void **)to_free);
		free_2d_array((void ***)to_free2d);
		free_and_exit("map invalid", EXIT_FAILURE, data);
	}
}
