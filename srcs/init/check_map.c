/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 01:54:05 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/22 19:06:20 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	check_map_edge(char **map, t_data *data)
{
	int	x;
	int	y;
	int	length;

	y = 0;
	length = -1;
	while (map[y][++length])
		if (map[y][length] != WALL)
			free_and_exit("map not closed", MAP_ERROR, data);
	while (map[++y] != NULL)
	{
		x = ft_strlen(map[y]);
		if (x != length)
			free_and_exit("map isn't rectangle", MAP_ERROR, data);
		if (map[y][0] != WALL || map[y][x - 1] != WALL)
			free_and_exit("map is not closed", MAP_ERROR, data);
	}
	x = -1;
	while (map[y - 1][++x])
	{
		if (map[y - 1][x] != WALL)
			free_and_exit("map is not closed", MAP_ERROR, data);
	}
}

static void	check_map_content(char **map, t_data *data)
{
	int	x;
	int	y;
	int	player;
	int	exit;

	y = -1;
	player = 0;
	exit = 0;
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
		}
	}
	if (player != 1 || exit != 1 || data->collectible_count < 1)
		free_and_exit("map not valid", MAP_ERROR, data);
}

void	check_map(char **map, t_data *data)
{
	
	check_map_edge(map, data);
	check_map_content(map, data);
	check_map_ways(map, data);
	
}