#include "../../includes/so_long.h"

void	put_images(t_mlx *mlx, t_data *data, int y, int x)
{
	char	type;

	type = data->map[y][x];
	if (type == WALL)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->wall,
				y * IMAGE_SIZE, x * IMAGE_SIZE);
	if (type == PLAYER)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->player,
				y * IMAGE_SIZE, x * IMAGE_SIZE);
	if (type == FLOOR)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->floor,
				y * IMAGE_SIZE, x * IMAGE_SIZE);
	if (type == COLLECT)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->collect,
				y * IMAGE_SIZE, x * IMAGE_SIZE);
	if (type == EXIT)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->exit,
				y * IMAGE_SIZE, x * IMAGE_SIZE);
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

void set_images(t_mlx *mlx, t_data *data)
{
	open_images(mlx, data);
	map_images(mlx, data);
}