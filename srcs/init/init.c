/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 23:35:34 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/23 23:35:48 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_data	*init_data(char **argv)
{
	t_data		*data;
	int			i;

	i = 0;
	data = malloc(sizeof(t_data) * 1);
	if (data == NULL)
		free_and_exit(MALLOC_FAILED,EXIT_FAILURE, data);
	ft_memset(data, 0, sizeof(t_data));
	init_map(data, argv[1]);
	data->map_x_length = ft_strlen(data->map[0]) - 1;
	if (data->map_x_length * IMAGE_SIZE >= 1980)
		free_and_exit("map too large\n", EXIT_FAILURE, data);
	while (data->map[i])
		i++;
	data->map_y_length = i - 1;
	if (data->map_y_length * IMAGE_SIZE >= 1080)
		free_and_exit("map too large\n", EXIT_FAILURE, data);
	init_player(data);
	return (data);
}

void set_images(t_mlx *mlx, t_data *data)
{
	open_images(mlx, data);
	map_images(data);
	ft_mlx_destroy_ptr(&mlx->wall, IMAGE, mlx);
	ft_mlx_destroy_ptr(&mlx->collect, IMAGE, mlx);
	ft_mlx_destroy_ptr(&mlx->destroyed_exit, IMAGE, mlx);
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
	mlx->gg = mlx_xpm_file_to_image(mlx->mlx_ptr, GG_PATH,
			&mlx->gg_x_size, &mlx->gg_y_size);
	mlx->lose = mlx_xpm_file_to_image(mlx->mlx_ptr, LOSE_PATH,
			&mlx->gg_x_size, &mlx->gg_y_size);
	mlx->m_left = check_image(M_LEFT_PATH, mlx, data);
	mlx->m_right = check_image(M_RIGHT_PATH, mlx, data);
	mlx->m_up = check_image(M_UP_PATH, mlx, data);
	mlx->m_down = check_image(M_DOWN_PATH, mlx, data);
}
