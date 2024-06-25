/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:10:31 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/25 03:18:08 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	put_trees(t_data *data, void *image_ptr)
{
	int	i;

	i = 0;
	while (i < data->wall_count_x2)
	{
		image_to_window(data, image_ptr,
				data->wall_pos[i + 1],data->wall_pos[i]);
		i += 2;
	}
}

int	animation(t_data *data)
{
	static int	frame = 0;
	float		count;
	static int	count2 = 0;
	int			between_sprite;

	between_sprite = 10000;
	count = ++frame % ((between_sprite * 6) * 4);
	if (count == 0)
		count2 = frame;
	else if (frame == count2 + between_sprite)
		put_trees(data, data->mlx->trees[5]);
	else if (frame == count2 + between_sprite * 2)
		put_trees(data, data->mlx->trees[1]);
	else if (frame == count2 + between_sprite * 3)
		put_trees(data, data->mlx->trees[2]);
	else if (frame == count2 + between_sprite * 4)
		put_trees(data, data->mlx->trees[3]);
	else if (frame == count2 + between_sprite * 5)
		put_trees(data, data->mlx->trees[4]);
	else if (frame == count2 + between_sprite * 6)
	{
		put_trees(data, data->mlx->trees[0]);
		count2 = 0;
	}
	return (0);
}
