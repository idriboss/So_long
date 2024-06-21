/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 00:36:06 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/22 01:32:11 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	next_pos(int next_x, int next_y, char sprite, t_data *data)
{
	if (data->map[next_y][next_x] != '1')
	{
		if (data->map[next_y][next_x] == COLLECT)
			data->collectible_count -= 1;
		data->map[next_y][next_x] = sprite;
		put_images(data->mlx, data, next_x, next_y);
		data->player->x = next_x;
		data->player->y = next_y;
		return (0);
	}
	return (1);
}

int	move(int code, t_data *data)
{
	static int	step_count;
	t_player	*player;
	int			val;

	val = 0;
	printf("code: %c\n", (char)code);
	player = data->player;
	data->map[player->y][player->x] = '0';
	put_images(data->mlx, data, player->y, player->x);
	if (code == 'w')
		val = next_pos(player->x, player->y + 1, PLAYER, data);
	else if (code == 'a')
		val = next_pos(player->x - 1, player->y, REVERSE_PLAYER, data);
	else if (code == 's')
		val = next_pos(player->x, player->y - 1, REVERSE_PLAYER, data);
	else if (code == 'd')
		val = next_pos(player->x + 1, player->y, PLAYER, data);
	if (val == 0)
		ft_printf("nombre de pas: %i\n", ++step_count);
	return (val);
}
