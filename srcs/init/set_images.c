/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 00:40:29 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/23 05:23:40 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	image_to_window(t_data *data, void *type, int y, int x)
{
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
							type, x * IMAGE_SIZE, y * IMAGE_SIZE);
	if (type == data->mlx->wall)
		data->map[y][x] = WALL;
	if (type == data->mlx->floor)
		data->map[y][x] = FLOOR;
	if (type == data->mlx->exit)
		data->map[y][x] = EXIT;
	if (type == data->mlx->player)
		data->map[y][x] = PLAYER;
	if (type == data->mlx->reverse_player)
		data->map[y][x] = REVERSE_PLAYER;
}

void	put_images(t_data *data, char type, int y, int x)
{
	if (type == WALL)
		image_to_window(data, data->mlx->wall, y, x);
	else if (type == PLAYER)
		image_to_window(data, data->mlx->player, y, x);
	else if (type == REVERSE_PLAYER)
		image_to_window(data, data->mlx->reverse_player, y, x);
	else if (type == FLOOR)
		image_to_window(data, data->mlx->floor, y, x);
	else if (type == COLLECT)
		image_to_window(data, data->mlx->collect, y, x);
	else if (type == EXIT && data->collectible_count != 0)
	{
		image_to_window(data, data->mlx->destroyed_exit, y, x);
		data->exit_x = x;
		data->exit_y = y;
	}
	if (data->collectible_count == 0)
	{
		image_to_window(data, data->mlx->exit, data->exit_y, data->exit_x);
	}
}

void	map_images(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map[++y] != NULL)
	{
		x = -1;
		while (data->map[y][++x] != '\0')
		{
			put_images(data, data->map[y][x],y, x);
		}
	}
}

static void	*check_image(char *file_path, t_mlx *mlx, t_data *data)
{
	int		width;
	int		height;
	void	*ptr;

	ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, file_path, &width, &height);
	if (ptr == NULL)
	{
		free_and_exit(file_path, EXIT_FAILURE, data);
	}
	if (width != IMAGE_SIZE || height != IMAGE_SIZE)
	{
		free_and_exit("bad image size", EXIT_FAILURE, data);
	}
	return (ptr);
}
void	open_images(t_mlx *mlx, t_data *data)
{
	mlx->player = check_image(PLAYER_PATH, mlx, data);
	mlx->reverse_player = check_image(REVERSE_PLAYER_PATH, mlx, data);
	mlx->wall = check_image(WALL_PATH, mlx, data);
	mlx->floor = check_image(FLOOR_PATH, mlx, data);
	mlx->collect = check_image(COLLECT_PATH, mlx, data);
	mlx->exit = check_image(EXIT_PATH, mlx, data);
	mlx->destroyed_exit = check_image(DESTROYED_EXIT_PATH, mlx, data);
	mlx->black = check_image(BLACK_PATH, mlx, data);
	mlx->gg = mlx_xpm_file_to_image(mlx->mlx_ptr, GG_PATH, &mlx->gg_x_size, &mlx->gg_y_size);
}

