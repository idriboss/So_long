/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 00:40:29 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/22 01:39:00 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	image_to_window(t_data *data, void *type, int y, int x)
{
	printf("case: %c\n", (char)(data->map[y][x]));
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
							type, x * IMAGE_SIZE, y * IMAGE_SIZE);
}

void	put_images(t_mlx *mlx, t_data *data, int y, int x)
{
	char	type;

	type = data->map[y][x];
	if (type == WALL)
		image_to_window(data, mlx->wall, y, x);
	else if (type == PLAYER)
		image_to_window(data, mlx->player, y, x);
	else if (type == REVERSE_PLAYER)
		image_to_window(data, mlx->player_left, y, x);
	else if (type == FLOOR)
		image_to_window(data, mlx->floor, y, x);
	else if (type == COLLECT)
		image_to_window(data, mlx->collect, y, x);
	else if (type == EXIT && data->collectible_count != 0)
	{
		image_to_window(data, mlx->floor, y, x);
		data->exit_x = x;
		data->exit_y = y;
	}
	else if (data->collectible_count == 0)
	{
		image_to_window(data, mlx->exit, data->exit_y, data->exit_x);
	}
}

void	map_images(t_mlx *mlx, t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map[++y] != NULL)
	{
		x = -1;
		while (data->map[y][++x] != '\0')
		{
			put_images(mlx, data, y, x);
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
		printf("oiu\n");
		printf("test = %s\n", file_path);
		free_and_exit(file_path, EXIT_FAILURE, data, false);
	}
	if (width != IMAGE_SIZE || height != IMAGE_SIZE)
	{
		printf("test = %s\n", file_path);
		free_and_exit("bad image size", EXIT_FAILURE, data, false);
	}
	return (ptr);
}
void	open_images(t_mlx *mlx, t_data *data)
{
	mlx->player = check_image(PLAYER_PATH, mlx, data);
	mlx->player_left = check_image(PLAYER_LEFT_PATH, mlx, data);
	mlx->wall = check_image(WALL_PATH, mlx, data);
	mlx->floor = check_image(FLOOR_PATH, mlx, data);
	mlx->collect = check_image(COLLECT_PATH, mlx, data);
	mlx->water = check_image(WATER_PATH, mlx, data);
	mlx->exit = check_image(EXIT_PATH, mlx, data);
}

