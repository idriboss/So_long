/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 05:29:26 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/25 16:56:54 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	final_image(t_data *data)
{
	int	x;
	int	y;

	x = (data->map_x_length * IMAGE_SIZE - data->mlx->gg_x_size) / 2;
	y = (data->map_y_length * IMAGE_SIZE - data->mlx->gg_y_size) / 2;
	if (data->mlx->gg_x_size <= data->map_x_length * IMAGE_SIZE
		&& data->mlx->gg_y_size <= data->map_y_length * IMAGE_SIZE)
	{
		mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
			data->mlx->final_image, x, y);
		return ;
	}
	else
		free_and_exit("play again with a larger map if you want a surprise !",
			EXIT_SUCCESS, data);
}

int	finish(t_data *data)
{
	static int	frame = 0;
	int			x;
	int			y;

	if (data->finish == false)
		return (EXIT_SUCCESS);
	frame += 1;
	if (frame > SPRITE_FRAME * 30)
		free_and_exit(NULL, EXIT_SUCCESS, data);
	y = -1;
	if (frame == 1)
	{
		while (data->map[++y] != NULL)
		{
			x = -1;
			while (data->map[y][++x] != '\0')
				image_to_window(data, data->mlx->black, y, x);
		}
		final_image(data);
	}
	return (EXIT_SUCCESS);
}

void	destroy_mlx(t_mlx *mlx)
{
	ft_mlx_destroy_ptr(&mlx->win_ptr, WINDOW, mlx);
	ft_mlx_destroy_ptr(&mlx->black, IMAGE, mlx);
	ft_mlx_destroy_ptr(&mlx->collect, IMAGE, mlx);
	ft_mlx_destroy_ptr(&mlx->destroyed_exit, IMAGE, mlx);
	ft_mlx_destroy_ptr(&mlx->exit, IMAGE, mlx);
	ft_mlx_destroy_ptr(&mlx->floor, IMAGE, mlx);
	ft_mlx_destroy_ptr(&mlx->reverse_player, IMAGE, mlx);
	ft_mlx_destroy_ptr(&mlx->player, IMAGE, mlx);
	ft_mlx_destroy_ptr(&mlx->gg, IMAGE, mlx);
	ft_mlx_destroy_ptr(&mlx->lose, IMAGE, mlx);
	ft_mlx_destroy_ptr(&mlx->m_down, IMAGE, mlx);
	ft_mlx_destroy_ptr(&mlx->m_left, IMAGE, mlx);
	ft_mlx_destroy_ptr(&mlx->wall, IMAGE, mlx);
	ft_mlx_destroy_ptr(&mlx->m_right, IMAGE, mlx);
	ft_mlx_destroy_ptr(&mlx->m_up, IMAGE, mlx);
	if (mlx->trees == NULL)
		return (ft_mlx_destroy_ptr(&mlx->mlx_ptr, DISPLAY, mlx));
	ft_mlx_destroy_ptr(&mlx->trees[0], IMAGE, mlx);
	ft_mlx_destroy_ptr(&mlx->trees[1], IMAGE, mlx);
	ft_mlx_destroy_ptr(&mlx->trees[2], IMAGE, mlx);
	ft_mlx_destroy_ptr(&mlx->trees[3], IMAGE, mlx);
	ft_mlx_destroy_ptr(&mlx->trees[4], IMAGE, mlx);
	ft_mlx_destroy_ptr(&mlx->trees[5], IMAGE, mlx);
	ft_free((void **)&mlx->trees);
	ft_mlx_destroy_ptr(&mlx->mlx_ptr, DISPLAY, mlx);
}

void	ft_mlx_destroy_ptr(void **ptd, char ptr_type, t_mlx *mlx)
{
	if (*ptd == NULL)
		return ;
	if (ptr_type == DISPLAY)
	{
		mlx_destroy_display(*ptd);
		ft_free(ptd);
	}
	if (ptr_type == WINDOW)
	{
		mlx_destroy_window(mlx->mlx_ptr, *ptd);
	}
	if (ptr_type == IMAGE)
	{
		mlx_destroy_image(mlx->mlx_ptr, *ptd);
	}
	*ptd = NULL;
}

void	free_and_exit(const char *err, int code, t_data *data)
{
	if (data->mlx != NULL)
	{
		destroy_mlx(data->mlx);
		ft_free((void **)&data->mlx);
	}
	free_2d_array((void ***)&data->map);
	ft_free((void **)&data->wall_pos);
	ft_free((void **)&data);
	if (code == EXIT_FAILURE || code == MAP_ERROR)
		ft_putstr_fd("Error: ", STDERR_FILENO);
	print_err_and_exit(err, code, false);
}
