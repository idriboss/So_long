/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 05:29:26 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/23 06:45:34 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int finish(t_data *data)
{
	static int	frame;
	int			x;
	int			y;

	if (data->finish == false)
		return (EXIT_SUCCESS);
	if (++frame >= 3000)
		mlx_loop_end(data->mlx->mlx_ptr);
	y = -1;
	while (data->map[++y] != NULL)
	{
		x = -1;
		while (data->map[y][++x] != '\0')
			image_to_window(data, data->mlx->black, y, x);
	}
	x = (data->map_x_length * IMAGE_SIZE - data->mlx->gg_x_size) / 2;
	y = (data->map_y_length * IMAGE_SIZE - data->mlx->gg_y_size) / 2;
	// printf("x: %i/%i\ny: %i/%i\n", x, data->map_x_length * IMAGE_SIZE, y, data->map_y_length * IMAGE_SIZE);
	// printf("(%i/%i && %i/%i)\n\n", x + data->mlx->gg_x_size, data->map_x_length * IMAGE_SIZE, y + data->mlx->gg_y_size, data->map_y_length * IMAGE_SIZE);
	if (data->mlx->gg_x_size <= data->map_x_length * IMAGE_SIZE && data->mlx->gg_y_size <= data->map_y_length * IMAGE_SIZE)
	{
		mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
								data->mlx->gg, x, y);
	}
	return (EXIT_SUCCESS);
}

int	escape(int code, t_data *data)
{
	int i;
	t_mlx	*mlx_to_free;

	i = 0;
	mlx_to_free = data->mlx;
	if (code == 65307)
	{
		printf("escape\n");
		mlx_destroy_window(mlx_to_free->mlx_ptr, mlx_to_free->win_ptr);
		mlx_destroy_display(mlx_to_free->mlx_ptr);
		while (i++ < mlx_ptr_number)
		{
			mlx_destroy_image(mlx_to_free->mlx_ptr, mlx_to_free);
		}
		free_and_exit(NULL, EXIT_SUCCESS, data);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	print_err_and_exit(const char *err, int code)
{
	if (err != NULL)
	{
		ft_putendl_fd((char *)err, STDERR_FILENO);
	}
	exit(code);
}

void	free_and_exit(const char *err, int code, t_data *data)
{
	ft_free((void **)&data->mlx);
	ft_free((void **)&data->player);
	ft_free((void **)&data);
	print_err_and_exit(err, code);
}
