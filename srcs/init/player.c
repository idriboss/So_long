#include "../../includes/so_long.h"

void	init_player(t_data *data)
{
	char	**map;
	int		x;
	int		y;

	map = data->map;
	y = 1;
	while (map[y + 1])
	{
		x = 1;
		while (map[y][x + 1])
		{
			if (map[y][x] == PLAYER)
			{
				data->player_x = x;
				data->player_y = y;
				break;
			}
			x++;
		}
		y++;
	}
}
