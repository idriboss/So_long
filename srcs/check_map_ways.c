/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_ways.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:32:59 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/25 16:52:17 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	fill(char **map, int y, int x)
{
	int	count;

	count = 0;
	if (map[y][x] == EXIT)
	{
		map[y][x] = '2';
		++count;
	}
	else if (map[y][x] != WALL && map[y][x] != PLAYER &&
			map[y][x] != MONSTER && map[y][x] != '2')
	{
		map[y][x] = PLAYER;
		++count;
	}
	return (count);
}

int	extend(char **map, int x, int y)
{
	int	count;

	count = 0;
	count += fill(map, y + 1, x);
	count += fill(map, y - 1, x);
	count += fill(map, y, x + 1);
	count += fill(map, y, x - 1);
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

int	check_map_ways(char **map)
{
	extend_blob(map);
	if (count_char_2d(map, '2') != 1)
		return (EXIT_FAILURE);
	if (count_char_2d(map, COLLECT) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
