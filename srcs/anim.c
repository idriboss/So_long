/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:10:31 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/25 16:36:12 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_trees(t_data *data, void *image_ptr)
{
	int	i;

	i = 0;
	while (i < data->wall_count_x2)
	{
		image_to_window(data, image_ptr, data->wall_pos[i + 1],
			data->wall_pos[i]);
		i += 2;
	}
}

void	put_animation(t_data *data, int index, int frame)
{
	if (frame == index + SPRITE_FRAME * 1)
		put_trees(data, data->mlx->trees[2]);
	else if (frame == index + SPRITE_FRAME * 2)
		put_trees(data, data->mlx->trees[4]);
	else if (frame == index + SPRITE_FRAME * 3)
		put_trees(data, data->mlx->trees[2]);
	else if (frame == index + SPRITE_FRAME * 4)
		put_trees(data, data->mlx->trees[0]);
	else if (frame == index + SPRITE_FRAME * 5)
		put_trees(data, data->mlx->trees[1]);
	else if (frame == index + SPRITE_FRAME * 6)
		put_trees(data, data->mlx->trees[3]);
	else if (frame == index + SPRITE_FRAME * 7)
		put_trees(data, data->mlx->trees[5]);
	else if (frame == index + SPRITE_FRAME * 8)
		put_trees(data, data->mlx->trees[3]);
	else if (frame == index + SPRITE_FRAME * 9)
		put_trees(data, data->mlx->trees[3]);
	else if (frame == index + SPRITE_FRAME * 10)
		put_trees(data, data->mlx->trees[0]);
}

int	animation(t_data *data)
{
	static int	frame = 0;
	float		count;
	static int	count2 = 1;

	count = ++frame % ((SPRITE_FRAME * 8) * 1);
	if (count == 0)
		count2 = frame;
	put_animation(data, count2, frame);
	return (0);
}
