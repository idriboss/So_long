#include "../../includes/so_long.h"

// mlx_init / mlx_connection / mlx_loop(mlx_connection) / 

void	so_long(t_data *data)
{
	t_mlx *mlx;

	mlx = malloc(sizeof(t_mlx) * 1);
	if (mlx == NULL)
		free_and_exit(MALLOC_FAILED, EXIT_FAILURE, data);
	ft_memset(mlx, 0, sizeof(t_mlx));
	data->mlx = mlx;
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		free_and_exit("mlx init failed", EXIT_FAILURE, data);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, (data->map_x_length + 1) * IMAGE_SIZE,
			(data->map_y_length + 1) * IMAGE_SIZE, "So_long");
	if (mlx->win_ptr == NULL)
		free_and_exit("window opening failed", EXIT_FAILURE, data);
	set_images(mlx, data);
	// TODO: mlx_hook(exit)
	mlx_loop_hook(mlx->mlx_ptr, finish, data);
	mlx_hook(mlx->win_ptr, 02, (1L<<0), escape, data);
	mlx_hook(mlx->win_ptr, 02, (1L<<0), move, data);
	mlx_loop(mlx->mlx_ptr);
	printf("FINISHED\n");
}

int	main(int argc, char **argv)
{
	t_data	*data;
	
	if (argc != 2)
		return (EXIT_SUCCESS);
	data = init_data(argv);
	so_long(data);
}