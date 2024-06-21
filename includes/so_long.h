/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 21:32:34 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/21 19:49:40 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define IMAGE_SIZE 64
# define MAP_ERROR 2
# define USAGE_BONUS ""
# define MALLOC_FAILED "syscall: malloc failed"
# define OPEN_FAIlED "syscall: open function failed"
# define WALL '1'
# define FLOOR '0'
# define COLLECT 'C'
# define PLAYER 'P'
# define EXIT 'E'
# define WALL_PATH "./images/tree.xpm"
# define FLOOR_PATH "./images/ground.xpm"
# define COLLECT_PATH "./images/meat.xpm"
# define PLAYER_PATH "./images/player_right.xpm"
# define PLAYER_LEFT_PATH "./images/player_left.xpm"
# define WATER_PATH "./images/water.xpm"
# define EXIT_PATH "./images/house.xpm"


typedef struct t_player
{
	int	x;
	int	y;
}	t_player;

typedef struct t_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*player;
	void	*player_left;
	void	*wall;
	void	*floor;
	void	*collect;
	void	*water;
	void	*exit;
	
}	t_mlx;

typedef struct t_data
{
	t_mlx	*mlx;
	t_player	*player;
	char		**map;
	int			map_y_length;
	int			map_x_length;
}	t_data;

void	free_and_exit(const char *err, int code, t_data *data, bool errno);
void	print_err_and_exit(const char *err, int code, bool errno, t_data *data);
char	*map(const char *map_path, t_data *data);
void	init_map(t_data *data, char *map_path);
void	check_map(char **map, t_data *data);
void	check_map_ways(char **map, t_data *data);
void	init_player(char **map, t_player *player);
void	init_data(t_data *data, t_player *player, char **argv);
void 	set_images(t_mlx *mlx, t_data *data);
void	move(t_mlx *mlx, t_data data);


#endif