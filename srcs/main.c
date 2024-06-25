/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:34:27 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/25 16:35:34 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/../includes/so_long.h"

void	put_step_count(t_data *data)
{
	char		*count;
	static int	step = 0;

	put_images(data, FLOOR, 0, 0);
	count = ft_itoa(++step);
	if (count == NULL)
		free_and_exit(MALLOC_FAILED, EXIT_FAILURE, data);
	mlx_string_put(data->mlx->mlx_ptr, data->mlx->win_ptr, IMAGE_SIZE / 3,
		IMAGE_SIZE / 2, 0xFFFFFF, count);
	ft_free((void **)&count);
}

static int	display(t_data *data)
{
	if (data->finish == true)
	{
		finish(data);
		return (EXIT_SUCCESS);
	}
	else
	{
		animation(data);
	}
	return (EXIT_SUCCESS);
}

static int	exit_button(t_data *data)
{
	free_and_exit("Game exited !", EXIT_SUCCESS, data);
	return (EXIT_FAILURE);
}

void	so_long(t_data *data)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx) * 1);
	if (mlx == NULL)
		free_and_exit(MALLOC_FAILED, EXIT_FAILURE, data);
	ft_memset(mlx, 0, sizeof(t_mlx));
	data->mlx = mlx;
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		free_and_exit("mlx init failed", EXIT_FAILURE, data);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, (data->map_x_length + 1)
			* IMAGE_SIZE, (data->map_y_length + 1) * IMAGE_SIZE, "So_long");
	if (mlx->win_ptr == NULL)
		free_and_exit("window opening failed", EXIT_FAILURE, data);
	set_images(mlx, data);
	put_images(data, FLOOR, 0, 0);
	mlx_loop_hook(mlx->mlx_ptr, display, data);
	mlx_hook(mlx->win_ptr, 02, (1L << 0), move, data);
	mlx_hook(mlx->win_ptr, 17, 0L, exit_button, data);
	mlx_loop(mlx->mlx_ptr);
	free_and_exit("YOU WIN !! GG !!", EXIT_SUCCESS, data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (EXIT_FAILURE);
	data = init_data(argv);
	if (data == NULL)
		return (1);
	so_long(data);
}
