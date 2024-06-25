/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 00:36:06 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/25 16:39:38 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	up(int x, int y, t_data *data)
{
	char	next_pos;

	next_pos = data->map[y - 1][x];
	if (next_pos == WALL)
		return (EXIT_FAILURE);
	if (next_pos == EXIT && data->collectible_count > 0)
		return (EXIT_FAILURE);
	else if (next_pos == EXIT || next_pos == MONSTER)
	{
		data->finish = true;
		if (next_pos == EXIT)
			data->mlx->final_image = data->mlx->gg;
		else if (next_pos == MONSTER)
			data->mlx->final_image = data->mlx->lose;
		return (EXIT_SUCCESS);
	}
	if (next_pos == COLLECT)
		data->collectible_count -= 1;
	put_images(data, data->map[y][x], y - 1, x);
	put_images(data, FLOOR, y, x);
	--data->player_y;
	return (EXIT_SUCCESS);
}

int	down(int x, int y, t_data *data)
{
	char	next_pos;

	next_pos = data->map[y + 1][x];
	if (next_pos == WALL)
		return (EXIT_FAILURE);
	if (next_pos == EXIT && data->collectible_count > 0)
		return (EXIT_FAILURE);
	else if (next_pos == EXIT || next_pos == MONSTER)
	{
		data->finish = true;
		if (next_pos == EXIT)
			data->mlx->final_image = data->mlx->gg;
		else if (next_pos == MONSTER)
			data->mlx->final_image = data->mlx->lose;
		return (EXIT_SUCCESS);
	}
	if (next_pos == COLLECT)
		data->collectible_count -= 1;
	put_images(data, data->map[y][x], y + 1, x);
	put_images(data, FLOOR, y, x);
	++data->player_y;
	return (EXIT_SUCCESS);
}

int	left(int x, int y, t_data *data)
{
	char	next_pos;

	next_pos = data->map[y][x - 1];
	if (next_pos == WALL)
	{
		put_images(data, REVERSE_PLAYER, y, x);
		return (EXIT_FAILURE);
	}
	if (next_pos == EXIT && data->collectible_count > 0)
		return (EXIT_FAILURE);
	else if (next_pos == EXIT || next_pos == MONSTER)
	{
		data->finish = true;
		if (next_pos == EXIT)
			data->mlx->final_image = data->mlx->gg;
		else if (next_pos == MONSTER)
			data->mlx->final_image = data->mlx->lose;
		return (EXIT_SUCCESS);
	}
	if (next_pos == COLLECT)
		data->collectible_count -= 1;
	put_images(data, REVERSE_PLAYER, y, x - 1);
	put_images(data, FLOOR, y, x);
	--data->player_x;
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
	if (next_pos == EXIT && data->collectible_count > 0)
		return (EXIT_FAILURE);
	else if (next_pos == EXIT || next_pos == MONSTER)
	{
		data->finish = true;
		if (next_pos == EXIT)
			data->mlx->final_image = data->mlx->gg;
		else if (next_pos == MONSTER)
			data->mlx->final_image = data->mlx->lose;
		return (EXIT_SUCCESS);
	}
	if (next_pos == COLLECT)
		data->collectible_count -= 1;
	put_images(data, PLAYER, y, x + 1);
	put_images(data, FLOOR, y, x);
	++data->player_x;
	return (EXIT_SUCCESS);
}

int	move(int code, t_data *data)
{
	int	exit_status;

	exit_status = 0;
	if (code == 65307)
		free_and_exit("Game exited !", EXIT_SUCCESS, data);
	if (data->finish == true)
	{
		return (EXIT_SUCCESS);
	}
	if (ft_strchr("wasd", code) == NULL)
		return (EXIT_FAILURE);
	if (code == 'w')
		exit_status = up(data->player_x, data->player_y, data);
	else if (code == 'a')
		exit_status = left(data->player_x, data->player_y, data);
	else if (code == 's')
		exit_status = down(data->player_x, data->player_y, data);
	else if (code == 'd')
		exit_status = right(data->player_x, data->player_y, data);
	if (exit_status == EXIT_SUCCESS)
		put_step_count(data);
	return (exit_status);
}
