#include "../../includes/so_long.h"

void	init_player(char **map, t_player *player)
{
	int	x;
	int	y;

	y = 1;
	while (map[y + 1])
	{
		x = 1;
		while (map[y][x + 1])
		{
			if (map[y][x] == 'P')
			{
				player->x = x;
				player->y= y;
				break;
			}
			x++;
		}
		y++;
	}
}
