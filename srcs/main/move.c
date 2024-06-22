/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 00:36:06 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/22 18:23:25 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	up(int x, int y, t_data *data)
{
	char	next_pos;

	next_pos = data->map[y - 1][x];
	if (next_pos == WALL)
		return (EXIT_FAILURE);
	if (next_pos == EXIT && data->collectible_count != 0)
		return (EXIT_FAILURE);
	else if (next_pos == EXIT)
	{
		//TODO: finish
		return (EXIT_SUCCESS);
	}
	if (next_pos == COLLECT)
		data->collectible_count -= 1;
	put_images(data, data->map[y][x], y - 1, x);
	put_images(data, FLOOR, y, x);
	--data->player->y;
	return (EXIT_SUCCESS);
}

int	down(int x, int y, t_data *data)
{
	char next_pos;

	next_pos = data->map[y + 1][x];
	if (next_pos == WALL)
		return (EXIT_FAILURE);
	if (next_pos == EXIT && data->collectible_count != 0)
		return (EXIT_FAILURE);
	else if (next_pos == EXIT)
	{
		//TODO: finish
		return (EXIT_SUCCESS);
	}
	if (next_pos == COLLECT)
		data->collectible_count -= 1;
	put_images(data, data->map[y][x], y + 1, x);
	put_images(data, FLOOR, y, x);
	++data->player->y;
	return (EXIT_SUCCESS);
}

int	left(int x, int y, t_data *data)
{
	char next_pos;

	next_pos = data->map[y][x - 1];
	if (next_pos == WALL)
	{
		put_images(data, REVERSE_PLAYER, y, x);
		return (EXIT_FAILURE);
	}
	if (next_pos == EXIT && data->collectible_count != 0)
		return (EXIT_FAILURE);
	else if (next_pos == EXIT)
	{
		//TODO: finish
		return (EXIT_SUCCESS);
	}
	if (next_pos == COLLECT)
		data->collectible_count -= 1;
	put_images(data, REVERSE_PLAYER, y, x - 1);
	put_images(data, FLOOR, y, x);
	--data->player->x;
	return (EXIT_SUCCESS);
}

int	right(int x, int y, t_data *data)
{
	char	next_pos;

	next_pos = data->map[y][x + 1];
	if (next_pos == WALL)
	{
		put_images(data, PLAYER, y, x);
		return (EXIT_FAILURE);
	}
	if (next_pos == EXIT && data->collectible_count != 0)
		return (EXIT_FAILURE);
	else if (next_pos == EXIT)
	{
		//TODO: finish
		return (EXIT_SUCCESS);
	}
	if (next_pos == COLLECT)
		data->collectible_count -= 1;
	put_images(data, PLAYER, y, x + 1);
	put_images(data, FLOOR, y, x);
	++data->player->x;
	return (EXIT_SUCCESS);
}

int	move(int code, t_data *data)
{
	static int	step_count;
	t_player	*player;
	int			val;

	val = 0;
	if (data->finish == true)
	{
		finish(data);
	}
	if (ft_strchr("wasd", code) == NULL)
		return (EXIT_FAILURE);
	player = data->player;
	if (code == 'w')
		val = up(player->x, player->y, data);
	else if (code == 'a')
		val = left(player->x, player->y, data);
	else if (code == 's')
		val = down(player->x, player->y, data);
	else if (code == 'd')
		val = right(player->x, player->y, data);
	if (val == EXIT_SUCCESS)
		ft_printf("nombre de pas: %i\n", ++step_count);
	return (val);
}
