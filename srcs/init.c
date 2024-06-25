/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 23:35:34 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/25 16:41:49 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	get_screen_size(int *x_address, int *y_address)
{
	t_mlx	*mlx;
	int		x;
	int		y;

	mlx = mlx_init();
	if (mlx == NULL)
		return (EXIT_FAILURE);
	mlx_get_screen_size(mlx, &x, &y);
	mlx_destroy_display(mlx);
	ft_free((void **)&mlx);
	*x_address = x;
	*y_address = y;
	return (EXIT_SUCCESS);
}

t_data	*init_data(char **argv)
{
	t_data		*data;
	int			i;
	int			screen_size_y;
	int			screen_size_x;

	i = 0;
	get_screen_size(&screen_size_x, &screen_size_y);
	if (get_screen_size(&screen_size_x, &screen_size_y) == EXIT_FAILURE)
		print_err_and_exit("mlx function failed", EXIT_FAILURE, false);
	data = malloc(sizeof(t_data) * 1);
	if (data == NULL)
		free_and_exit(MALLOC_FAILED, EXIT_FAILURE, data);
	ft_memset(data, 0, sizeof(t_data));
	init_map(data, argv[1]);
	data->map_x_length = ft_strlen(data->map[0]) - 1;
	if (data->map_x_length * IMAGE_SIZE >= screen_size_x)
		free_and_exit("map too large\n", EXIT_FAILURE, data);
	while (data->map[i])
		i++;
	data->map_y_length = i - 1;
	if (data->map_y_length * IMAGE_SIZE >= screen_size_y - IMAGE_SIZE * 2)
		free_and_exit("map too large\n", EXIT_FAILURE, data);
	init_player(data);
	return (data);
}

void	set_images(t_mlx *mlx, t_data *data)
{
	open_images(mlx, data);
	map_images(data);
	ft_mlx_destroy_ptr(&mlx->collect, IMAGE, mlx);
	ft_mlx_destroy_ptr(&mlx->destroyed_exit, IMAGE, mlx);
	ft_mlx_destroy_ptr(&mlx->wall, IMAGE, mlx);
}

static void	open_trees(t_data *data, t_mlx *mlx)
{
	mlx->trees = malloc(sizeof(void *) * 6);
	if (mlx->trees == NULL)
		free_and_exit(MALLOC_FAILED, EXIT_FAILURE, data);
	mlx->trees[0] = check_image(TREE1, mlx, data);
	mlx->trees[1] = check_image(TREE2, mlx, data);
	mlx->trees[2] = check_image(TREE3, mlx, data);
	mlx->trees[3] = check_image(TREE4, mlx, data);
	mlx->trees[4] = check_image(TREE5, mlx, data);
	mlx->trees[5] = check_image(TREE6, mlx, data);
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
	open_trees(data, mlx);
}
