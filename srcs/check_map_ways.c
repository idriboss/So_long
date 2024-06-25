/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_ways.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:32:59 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/25 05:05:38 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	extend(char **map, int x, int y)
{
	int	count;

	count = 0;
	if (map[y + 1][x] != WALL && map[y + 1][x] != PLAYER && map[y
		+ 1][x] != MONSTER)
	{
		count++;
		map[y + 1][x] = PLAYER;
	}
	if (map[y - 1][x] != WALL && map[y - 1][x] != PLAYER && map[y
		- 1][x] != MONSTER)
	{
		count++;
		map[y - 1][x] = PLAYER;
	}
	if (map[y][x + 1] != WALL && map[y][x + 1] != PLAYER && map[y][x
		+ 1] != MONSTER)
	{
		count++;
		map[y][x + 1] = PLAYER;
	}
	if (map[y][x - 1] != WALL && map[y][x - 1] != PLAYER && map[y][x
		- 1] != MONSTER)
	{
		count++;
		map[y][x - 1] = PLAYER;
	}
	return (count);
}

void	extend_blob(char **map)
{
	int	x;
	int	y;
	int	count;

	while (1)
	{
		y = 0;
		count = 0;
		while (map[y])
		{
			x = 0;
			while (map[y][x])
			{
				if (map[y][x] == PLAYER)
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
	extend_blob(map);
	while (map[y])
	{
		if (ft_strchr(map[y], EXIT) != NULL)
		{
			print_2d_array_nl(map);
			free_and_exit("exit cannot be reached", MAP_ERROR, data);
		}
		if (ft_strchr(map[y], COLLECT) != NULL)
		{
			print_2d_array_nl(map);
			free_and_exit("not all collectables can be taken",
							MAP_ERROR,
							data);
		}
		y++;
	}
}
