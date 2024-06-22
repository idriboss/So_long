#include "../../includes/so_long.h"

t_data	*init_data(char **argv)
{
	t_data		*data;
	t_player	*player;
	int			i;

	i = 0;
	data = malloc(sizeof(t_data) * 1);
	if (data == NULL)
		free_and_exit(MALLOC_FAILED,EXIT_FAILURE, data);
	ft_memset(data, 0, sizeof(t_data));
	player = malloc(sizeof(t_player) * 1);
	if (player == NULL)
		free_and_exit(MALLOC_FAILED,EXIT_FAILURE, data);
	ft_memset(player, 0, sizeof(t_player));
	init_map(data, argv[1]);
	data->map_x_length = ft_strlen(data->map[0]) - 1;
	if (data->map_x_length * IMAGE_SIZE >= 1980)
		free_and_exit("map too large\n", EXIT_FAILURE, data);
	while (data->map[i])
		i++;
	data->map_y_length = i - 1;
	if (data->map_y_length * IMAGE_SIZE >= 1080)
		free_and_exit("map too large\n", EXIT_FAILURE, data);
	init_player(data->map, player);
	data->player = player;
	return (data);
}

void set_images(t_mlx *mlx, t_data *data)
{
	open_images(mlx, data);
	map_images(data);
}
