#include "../../includes/so_long.h"





void	init_data(t_data *data, t_player *player, char **argv)
{
	int	i;

	i = 0;
	init_map(data, argv[1]);
	data->map_x_length = ft_strlen(data->map[0]) - 1;
	while (data->map[i])
		i++;
	data->map_y_length = i;
	init_player(data->map, player);
	data->player = player;
}

