/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 21:32:34 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/23 06:32:06 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft.h"
#include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <limits.h>

# define IMAGE_SIZE 64
# define MAP_ERROR 2
# define MALLOC_FAILED "syscall: malloc failed"
# define OPEN_FAIlED "syscall: open function failed"
# define WALL '1'
# define FLOOR '0'
# define COLLECT 'C'
# define PLAYER 'P'
# define REVERSE_PLAYER 'R'
# define EXIT 'E'
# define BLACK_PATH "./images/black.xpm"
# define WALL_PATH "./images/tree.xpm"
# define FLOOR_PATH "./images/ground.xpm"
# define COLLECT_PATH "./images/wood.xpm"
# define PLAYER_PATH "./images/player_right.xpm"
# define REVERSE_PLAYER_PATH "./images/player_left.xpm"
# define EXIT_PATH "./images/house.xpm"
# define DESTROYED_EXIT_PATH "./images/destroyed_house.xpm"
# define GG_PATH "./images/gg.xpm"
# define WINDOW_X_SIZE 1920
# define WINDOW_Y_SIZE 1080
# define mlx_ptr_number 11



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
	void	*reverse_player;
	void	*wall;
	void	*floor;
	void	*collect;
	void	*exit;
	void	*destroyed_exit;
	void	*black;
	void	*gg;
	int		gg_x_size;
	int		gg_y_size;
}	t_mlx;

typedef struct t_data
{
	t_mlx		*mlx;
	t_player	*player;
	char		**map;
	int			map_y_length;
	int			map_x_length;
	int			collectible_count;
	int			exit_x;
	int			exit_y;
	bool		finish;
}	t_data;

void	free_and_exit(const char *err, int code, t_data *data);
void	print_err_and_exit(const char *err, int code);
char	*map(const char *map_path, t_data *data);
void	init_map(t_data *data, char *map_path);
void	check_map(char **map, t_data *data);
void	check_map_ways(char **map, t_data *data);
void	init_player(char **map, t_player *player);
t_data	*init_data(char **argv);
void 	set_images(t_mlx *mlx, t_data *data);
int		move(int code, t_data *data);
void	put_images(t_data *data, char type, int y, int x);
void	map_images(t_data *data);
void	open_images(t_mlx *mlx, t_data *data);
int 	finish(t_data *data);
void	image_to_window(t_data *data, void *type, int y, int x);
int		escape(int code, t_data *data);
#endif